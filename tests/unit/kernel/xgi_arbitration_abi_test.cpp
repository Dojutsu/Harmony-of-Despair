// Actual Runtime/HLE and authorized local session store; owned loopback UDP only.
#include <rex/runtime.h>
#include <rex/cvar.h>
#include <rex/kernel/xam/apps/xgi_app.h>
#include <rex/logging.h>
#include <rex/ppc/context.h>
#include <rex/platform/guest_fault_state.h>
#include <rex/system/xam/session.h>
#include <rex/system/xam/session_arbitration_guest.h>
#include <rex/system/xevent.h>
#include <rex/memory/mapping_lease.h>
#include <rex/system/xio.h>
#include <rex/system/xthread.h>
#include <rex/system/xsocket.h>
#include <algorithm>
#include <array>
#include <cstring>
#include <iostream>
#include <stdexcept>
REX_EXTERN(__imp__XMsgStartIORequest);
REX_EXTERN(__imp__NtClose);
REX_EXTERN(__imp__NtDuplicateObject);
REX_EXTERN(__imp__NetDll_XNetXnAddrToMachineId);
REX_EXTERN(__imp__NetDll_bind);
REX_EXTERN(__imp__NetDll_XNetGetTitleXnAddr);
REX_EXTERN(__imp__NetDll_closesocket);
using namespace rex;
using namespace rex::system;
using namespace rex::system::xam;
namespace {
size_t checks = 0;
void Check(bool value, const char* message) { ++checks; if (!value) throw std::runtime_error(message); }
uint32_t Invoke(PPCFunc* function, std::initializer_list<uint64_t> arguments) {
  auto* current = XThread::GetCurrentThread();
  Check(current && runtime::ThreadState::Get() == current->thread_state(), "actual bound HLE thread");
  auto* context = current->thread_state()->context();
  PPCRegister* registers[]{&context->r3,&context->r4,&context->r5,&context->r6,&context->r7,&context->r8};
  Check(arguments.size() <= std::size(registers), "HLE argument bound");
  size_t index = 0;
  for (auto value : arguments) registers[index++]->u64 = value;
  guest::ExecutionActivation activation;
  function(*context,current->memory()->virtual_membase());
  return context->r3.u32;
}
uint64_t Read(memory::Memory* memory,uint32_t address,size_t width) {
  const auto* ptr=memory->TranslateVirtual(address);uint64_t value=0;
  for(size_t i=0;i<width;++i)value=(value<<8)|ptr[i];return value;
}
void Put(memory::Memory* memory,uint32_t address,uint64_t value,size_t width=4) {
  auto* ptr=memory->TranslateVirtual(address);
  for(size_t i=0;i<width;++i){ptr[width-i-1]=uint8_t(value);value>>=8;}
}
void Run(KernelState* kernel) {
  auto* memory=kernel->memory();
  const uint32_t allocation=memory->SystemHeapAlloc(1024*1024);
  Check(allocation!=0,"actual guest memory");
  auto* heap=memory->LookupHeap(allocation); const auto page=heap->page_size();
  const auto request=allocation; const auto output=allocation+2*page;
  const auto overlapped=allocation+5*page; const auto address=allocation+6*page;
  const auto machine_output=address+64;
  auto& registry=kernel->session_manager()->registry(); const auto xuid=kernel->user_profile()->xuid();
  auto object=make_object<XSession>(kernel);Check(object->Initialize(),"actual native session object");
  const auto session=registry.Create(xuid,"Native host",{0x0100007fu,3074},1,4,2);
  Check(session && session->arbitration && session->host_machine_id,"actual hosted authority created");
  object->set_record(session);
  const auto machine=session->host_machine_id;
  // Match the actual title's Create3074 -> bind guest1000/native52279 order.
  // The bind HLE publishes the observed native endpoint to existing records.
  auto gameplay_socket=make_object<XSocket>(kernel);
  Check(gameplay_socket->Initialize(XSocket::X_AF_INET,XSocket::X_SOCK_DGRAM,XSocket::X_IPPROTO_UDP)==X_STATUS_SUCCESS,
        "actual owned UDP gameplay socket");
  std::memset(memory->TranslateVirtual(address),0,sizeof(XSOCKADDR_IN));
  Put(memory,address,2,2);Put(memory,address+2,1000,2);Put(memory,address+4,0x7F000001u);
  Check(Invoke(__imp__NetDll_bind,{1,gameplay_socket->handle(),address,sizeof(XSOCKADDR_IN)})==0,
        "actual bind HLE maps guest1000 to configured native52279");
  Check(session->info.host_address.port==52279 && session->members[0].gameplay_address.port==52279,
        "bind after Create publishes native52279 to host record and member");
  Check(Read(memory,address+2,2)==1000,"bind preserves guest socket port argument");
  auto setup=[&](uint32_t destination=0) {
    std::memset(memory->TranslateVirtual(request),0,32);
    Put(memory,request,object->guest_object());Put(memory,request+4,0);
    Put(memory,request+8,session->nonce,8);Put(memory,request+16,300);
    Put(memory,request+20,3592);Put(memory,request+24,destination?destination:output);
    Put(memory,request+28,0xdeadbeef);
  };
  auto call=[&](uint32_t length=32,uint32_t req=0,uint32_t ov=0) {
    return Invoke(__imp__XMsgStartIORequest,{0xfb,0x000B001A,ov,req?req:request,length});
  };
  auto unchanged=[&](uint32_t pointer,uint32_t length,uint8_t sentinel,const char* message) {
    const auto* bytes=memory->TranslateVirtual(pointer);
    Check(std::all_of(bytes,bytes+length,[&](uint8_t byte){return byte==sentinel;}),message);
  };
  auto reject=[&](uint32_t expected,uint32_t length=32,uint32_t req=0) {
    std::memset(memory->TranslateVirtual(output),0xa5,3592);
    const auto actual=call(length,req);
    if(actual!=expected) {
      const auto decoded=ReadArbitrationGuestRequest(memory,request,32);
#if REX_PLATFORM_GNU_LINUX
      memory::MappingAccessLease diagnostic_lease;
#endif
      auto* request_heap=memory->LookupHeap(request);
      memory::HeapAllocationInfo info{};
      const bool region=request_heap && request_heap->QueryRegionInfo(request,&info);
      std::cerr<<"decoded="<<bool(decoded)<<" heap="<<bool(request_heap)
               <<" type="<<(request_heap?int(request_heap->heap_type()):-1)
               <<" access="<<(request_heap?int(request_heap->QueryRangeAccess(request,request+31)):-1)
               <<" region="<<region<<" state="<<info.state<<" base="<<std::hex<<info.base_address
               <<" size="<<info.region_size
#if REX_PLATFORM_GNU_LINUX
               <<" backing="<<memory->MatchesGuestBacking(memory->TranslateVirtual(request),request,32)
#endif
               <<" object="<<Read(memory,request,4)<<" nonce="<<Read(memory,request+8,8)
               <<" expected_nonce="<<session->nonce<<std::dec<<'\n';
      std::cerr<<"request="<<std::hex<<(req?req:request)<<" length="<<std::dec<<length
               <<" capacity="<<Read(memory,request+20,4)<<" flags="<<Read(memory,request+4,4)
               <<" output="<<std::hex<<Read(memory,request+24,4)<<" actual="<<actual
               <<" expected="<<expected<<std::dec<<'\n';
    }
    Check(actual==expected,"malformed request returns precise failure");
    unchanged(output,3592,0xa5,"malformed request has no guest output prefix");
    Check(session->arbitration->Snapshot()->registrants.empty(),"preflight failures do not register host");
    Check(session->state==SessionState::kLobby,"preflight failures preserve lobby state");
  };
  setup();
  for(uint32_t length:{0u,1u,27u,29u,31u,33u,UINT32_MAX})reject(X_E_INVALIDARG,length);
  reject(X_E_INVALIDARG,32,0xfffffff0u);
  Put(memory,request+4,1);reject(X_E_INVALIDARG);setup();
  Put(memory,request+8,0,8);reject(X_E_INVALIDARG);setup();
  Put(memory,request+8,session->nonce^1,8);reject(X_E_INVALIDARG);setup();
  Put(memory,request,0);reject(X_E_INVALIDARG);setup();
  Put(memory,request,allocation+7*page);reject(X_E_INVALIDARG);setup();
  Put(memory,request+24,0);reject(X_E_INVALIDARG);setup();
  for(uint32_t capacity:{0u,8u,40u,263u}){Put(memory,request+20,capacity);reject(X_ERROR_INSUFFICIENT_BUFFER);}
  setup();Put(memory,request+20,UINT32_MAX);reject(X_E_INVALIDARG);setup();
  Check(heap->Protect(output,page,memory::kMemoryProtectRead),"readonly result page");
  Check(call()==X_E_INVALIDARG,"readonly preflight rejected");
  unchanged(output,3592,0xa5,"readonly preflight leaves output unchanged");
  Check(session->arbitration->Snapshot()->registrants.empty(),"readonly output does not register");
  Check(heap->Protect(output,page,memory::kMemoryProtectRead|memory::kMemoryProtectWrite),"restore result page");
  const auto crossing=allocation+4*page-128;
  std::memset(memory->TranslateVirtual(crossing),0x6d,128);setup(crossing);
  Check(heap->Protect(allocation+4*page,page,0),"unmapped output tail");
  Check(call()==X_E_INVALIDARG,"crossing noaccess preflight rejected");
  unchanged(crossing,128,0x6d,"noaccess output tail publishes no prefix");
  Check(session->arbitration->Snapshot()->registrants.empty(),"crossing output does not register");
  Check(heap->Protect(allocation+4*page,page,memory::kMemoryProtectRead|memory::kMemoryProtectWrite),"restore output tail");
  setup();
  const auto split_request=allocation+page-28;
  std::memcpy(memory->TranslateVirtual(split_request),memory->TranslateVirtual(request),32);
  Check(heap->Protect(allocation+page,page,0),"declared request tail noaccess");
  reject(X_E_INVALIDARG,32,split_request);
  // The legacy explicit28 spelling succeeds when all semantic bytes are readable;
  // declared32 still requires its unwritten four-byte tail to be readable.
  std::memset(memory->TranslateVirtual(output),0xa5,3592);
  Check(call(28,split_request)==X_E_SUCCESS,"actual legacy28 HLE registration");
  Check(heap->Protect(allocation+page,page,memory::kMemoryProtectRead|memory::kMemoryProtectWrite),"restore request tail");
  Check(session->state==SessionState::kRegistration,"only successful output commits registration state");
  Check(Read(memory,output,4)==1 && Read(memory,output+4,4)==output+8,"guest header8 count and nested pointer");
  Check(Read(memory,output+8,8)==machine && Read(memory,output+16,4)==0,"machine BE64 and conservative trust");
  Check(Read(memory,output+20,4)==1 && Read(memory,output+24,4)==output+32,"registrant24 count and user pointer");
  Check(Read(memory,output+28,4)==0 && Read(memory,output+32,8)==xuid,"registrant padding and BE64 XUID");
  unchanged(output+40,3592-40,0xa5,"actual output prefix only; declared unused capacity unchanged");
  Check(Read(memory,request+28,4)==0xdeadbeef,"unwritten request suffix ignored and unchanged");
  Put(memory,output+32,0,8);
  Check(session->arbitration->Snapshot()->registrants[0].xuids[0]==xuid,"guest result mutation cannot change authority");
  Check(call()==X_E_SUCCESS && Read(memory,output+32,8)==xuid,"retry creates fresh independent guest result");
  setup();Put(memory,request+20,264);
  // Capacity is a scalar. The fixture's3592 was never used as a guest size pointer.
  Check(call()==X_E_SUCCESS,"exact bounded264 capacity accepted");
  auto event=make_object<XEvent>(kernel);event->Initialize(true,false);
  std::memset(memory->TranslateVirtual(overlapped),0,sizeof(XAM_OVERLAPPED));
  Put(memory,overlapped,X_ERROR_IO_PENDING);Put(memory,overlapped+12,event->handle());
  Check(call(32,0,overlapped)==X_ERROR_IO_PENDING,"real overlapped HLE returns pending");
  Check(Read(memory,overlapped,4)==X_E_SUCCESS && Read(memory,overlapped+24,4)==X_E_SUCCESS,
        "real overlapped completion carries actual result");
  uint64_t immediate=0;
  Check(event->Wait(3,1,0,&immediate)==X_STATUS_SUCCESS && Read(memory,output+32,8)==xuid,
        "completion event observes complete actual output");
  event->Reset();Put(memory,request+4,1);Put(memory,overlapped,X_ERROR_IO_PENDING);
  std::memset(memory->TranslateVirtual(output),0xa5,264);
  Check(call(32,0,overlapped)==X_ERROR_IO_PENDING && Read(memory,overlapped,4)==X_E_INVALIDARG,
        "overlapped API return does not hide completion failure");
  Check(event->Wait(3,1,0,&immediate)==X_STATUS_SUCCESS,"failed completion still signals event");
  unchanged(output,264,0xa5,"failed overlapped registration leaves output unchanged");
  setup();
  // XNADDR exact36-byte guest layout; IP fields remain network-order bytes.
  std::memset(memory->TranslateVirtual(address),0,36);
  std::memcpy(memory->TranslateVirtual(address),&session->info.host_address.ipv4,4);
  Put(memory,address+8,session->info.host_address.port,2);
  std::memcpy(memory->TranslateVirtual(address+10),session->info.ethernet_address.data(),6);
  std::memcpy(memory->TranslateVirtual(address+16),session->info.online_address.data(),20);
  std::memset(memory->TranslateVirtual(machine_output),0x5a,16);
  auto machine_call=[&](uint32_t input=0,uint32_t destination=0) {
    return Invoke(__imp__NetDll_XNetXnAddrToMachineId,{1,input?input:address,destination?destination:machine_output});
  };
  Check(machine_call()==0 && Read(memory,machine_output,8)==machine,"actual XNet writes full BE64 machine ID");
  unchanged(machine_output+8,8,0x5a,"XNet output is exactly eight bytes");
  Check(Invoke(__imp__NetDll_XNetGetTitleXnAddr,{1,address})==0xAu && Read(memory,address+8,2)==3074,
        "actual title XNADDR HLE retains explicit guest3074 port after native bind");
  std::memset(memory->TranslateVirtual(machine_output),0x5a,16);
  Check(machine_call()==0 && Read(memory,machine_output,8)==machine,
        "known hosted native port52279 also resolves explicit guest3074 alias");
  unchanged(machine_output+8,8,0x5a,"guest3074 alias writes exactly eight bytes");
  Put(memory,address+8,52280,2);
  std::memset(memory->TranslateVirtual(machine_output),0x5a,16);
  Check(machine_call()==0x2741,"hosted identity rejects an unknown third port");
  unchanged(machine_output,16,0x5a,"unknown hosted port preserves full output");
  Put(memory,address+8,session->info.host_address.port,2);
  const uint32_t wrong_host_ip=0x0200007fu;
  std::memcpy(memory->TranslateVirtual(address),&wrong_host_ip,4);
  Check(machine_call()==0x2741,"hosted identity rejects a different IPv4 endpoint");
  unchanged(machine_output,16,0x5a,"wrong hosted IP preserves full output");
  std::memcpy(memory->TranslateVirtual(address),&session->info.host_address.ipv4,4);
  memory->TranslateVirtual(address+35)[0]^=1;
  std::memset(memory->TranslateVirtual(machine_output),0x5a,16);
  Check(machine_call()==0x2741,"unknown exact XNADDR fails");
  unchanged(machine_output,16,0x5a,"unknown address does not manufacture machine output");
  memory->TranslateVirtual(address+35)[0]^=1;
  Check(machine_call(0xfffffff0u)==0x2726,"wrapping XNADDR input fails");
  const auto machine_crossing=allocation+8*page-4;
  std::memset(memory->TranslateVirtual(machine_crossing),0x63,4);
  Check(heap->Protect(allocation+8*page,page,0),"machine64 output second half noaccess");
  Check(machine_call(address,machine_crossing)==0x2726,"machine output requires full eight writable bytes");
  unchanged(machine_crossing,4,0x63,"failed machine64 output does not publish first DWORD");
  Check(heap->Protect(allocation+8*page,page,memory::kMemoryProtectRead|memory::kMemoryProtectWrite),"restore machine output tail");
  // Accepted remote membership has a distinct native endpoint and an actual
  // host-owned continuity record. It is joined, but has never registered.
  const uint64_t peer_xuid=xuid^1u;
  const uint64_t peer_machine=machine==0xAABBCCDD11223344ull ?
      0xAABBCCDD11223345ull : 0xAABBCCDD11223344ull;
  ArbitrationToken peer_challenge{},peer_credential{};
  peer_challenge.fill(0x31);peer_credential.fill(0x42);
  const uint32_t peer_ipv4=0x0200007fu;
  const ArbitrationJoinClaim peer_claim{peer_xuid,peer_machine,{peer_ipv4,45000},peer_challenge,{}};
  Check(session->arbitration->Admit(peer_claim,peer_credential,SessionArbitrationAuthority::Clock::now()).accepted(),
        "actual host authority accepts native fixture peer admission");
  SessionMember peer{};peer.xuid=peer_xuid;peer.name="Native peer";
  peer.machine_id=peer_machine;peer.gameplay_address={peer_ipv4,52280};
  Check(registry.JoinBatch(session,std::span<const SessionMember>(&peer,1)),
        "actual membership store publishes admitted native peer endpoint");
  auto write_peer_address=[&](uint64_t identity_xuid,uint32_t ipv4,uint16_t port) {
    const auto identity=ReconstructXnAddrIdentity(identity_xuid);
    std::memset(memory->TranslateVirtual(address),0,36);
    std::memcpy(memory->TranslateVirtual(address),&ipv4,4);
    Put(memory,address+8,port,2);
    std::memcpy(memory->TranslateVirtual(address+10),identity.ethernet_address.data(),6);
    std::memcpy(memory->TranslateVirtual(address+16),identity.online_address.data(),20);
    std::memset(memory->TranslateVirtual(machine_output),0x5a,16);
  };
  for(const uint16_t port:{uint16_t(52280),uint16_t(3074)}) {
    write_peer_address(peer_xuid,peer_ipv4,port);
    Check(machine_call()==0 && Read(memory,machine_output,8)==peer_machine,
          "actual HLE resolves admitted peer native port and explicit guest3074 alias to same BE64 identity");
    Check(Read(memory,machine_output,4)==0xAABBCCDDu,"known peer machine retains high32 bits");
    unchanged(machine_output+8,8,0x5a,"known peer output is exactly eight bytes");
  }
  write_peer_address(peer_xuid,peer_ipv4,52281);
  Check(machine_call()==0x2741,"admitted peer rejects unknown third port");
  unchanged(machine_output,16,0x5a,"unknown peer port preserves full output");
  write_peer_address(peer_xuid,0x0300007fu,52280);
  Check(machine_call()==0x2741,"admitted peer rejects wrong IP");
  unchanged(machine_output,16,0x5a,"wrong peer IP preserves full output");
  write_peer_address(peer_xuid^0x10u,peer_ipv4,52280);
  Check(machine_call()==0x2741,"same native endpoint cannot manufacture nonmember identity");
  unchanged(machine_output,16,0x5a,"nonmember identity preserves full output");
  Check(registry.Leave(session->info.id,peer_xuid),"actual host store removes native peer");
  write_peer_address(peer_xuid,peer_ipv4,3074);
  Check(machine_call()==0x2741,"departed peer loses both endpoint aliases");
  unchanged(machine_output,16,0x5a,"departed peer lookup preserves full output");
  Check(Invoke(__imp__NetDll_closesocket,{1,gameplay_socket->handle()})==0,
        "actual closesocket HLE retires the owned native socket");
  gameplay_socket.reset();
  const auto snapshot=session->arbitration->Snapshot();
  Check(snapshot.has_value(),"real registered snapshot exists");
  auto bad_identity=snapshot->identity;bad_identity.incarnation[0]^=1;
  bool invoked=false;
  Check(!registry.CommitArbitration(session,bad_identity,snapshot->revision,[&]{invoked=true;return true;}) && !invoked,
        "stale incarnation never invokes guest publication callback");
  invoked=false;
  Check(!registry.CommitArbitration(session,snapshot->identity,snapshot->revision+1,[&]{invoked=true;return true;}) && !invoked,
        "stale authority revision never invokes guest publication callback");
  auto malformed_snapshot=*snapshot;
  malformed_snapshot.registrants.clear();
  Check(!SerializeArbitrationGuestResults(malformed_snapshot,output),"empty authority result never serializes fake success");
  malformed_snapshot=*snapshot;malformed_snapshot.registrants[0].machine_id=0;
  Check(!SerializeArbitrationGuestResults(malformed_snapshot,output),"zero machine result rejected");
  malformed_snapshot=*snapshot;malformed_snapshot.registrants[0].trustworthiness=1;
  Check(!SerializeArbitrationGuestResults(malformed_snapshot,output),"unqualified trust assertion rejected");
  malformed_snapshot=*snapshot;malformed_snapshot.registrants[0].xuids[0]=0;
  Check(!SerializeArbitrationGuestResults(malformed_snapshot,output),"zero XUID result rejected");
  Check(!SerializeArbitrationGuestResults(*snapshot,0xfffffff0u),"wrapped nested result pointers rejected");
  const auto alias_address=allocation+7*page;
  Check(Invoke(__imp__NtDuplicateObject,{object->handle(),alias_address,0})==X_STATUS_SUCCESS,
        "actual duplicate session handle");
  const auto alias=uint32_t(Read(memory,alias_address,4));
  Check(alias && alias!=object->handle(),"session duplicate alias distinct from stashed primary");
  Check(Invoke(__imp__NtClose,{object->handle()})==X_STATUS_SUCCESS,"real HLE closes stashed primary while alias remains live");
  Check(call()==X_E_SUCCESS && Read(memory,output+32,8)==xuid,
        "live alias preserves normal arbitration with stale primary native header");
  const auto join_request=alias_address+32;
  std::memset(memory->TranslateVirtual(join_request),0,24);
  Put(memory,join_request,object->guest_object());Put(memory,join_request+4,1);
  Put(memory,join_request+12,join_request+20);Put(memory,join_request+20,0);
  auto join_call=[&] {
    return Invoke(__imp__XMsgStartIORequest,{0xfb,0x000B0012,0,join_request,20});
  };
  Check(join_call()==X_E_SUCCESS && object->record()==session,
        "actual local join retains live alias with stale primary header and same record");
  Check(Invoke(__imp__NtClose,{alias})==X_STATUS_SUCCESS,"real HLE closes last session alias while object remains retained");
  Check(join_call()==X_E_INVALIDARG,"actual local join cannot revive retained object after last alias closes");
  std::memset(memory->TranslateVirtual(output),0xa5,264);
  Check(call()==X_E_INVALIDARG,"retained native session header cannot revive a closed handle");
  unchanged(output,264,0xa5,"closed session handle never publishes guest result");
  Check(registry.Delete(session->info.id),"actual session delete");
  invoked=false;
  Check(!registry.CommitArbitration(session,snapshot->identity,snapshot->revision,[&]{invoked=true;return true;}) && !invoked,
        "deleted exact record never invokes publication callback");
  std::memset(memory->TranslateVirtual(output),0xa5,264);
  Check(call()!=X_E_SUCCESS,"deleted retained object cannot register/publish again");
  unchanged(output,264,0xa5,"deleted session leaves output unchanged");
  object->set_record(nullptr);
  object.reset();event->ReleaseHandle();event.reset();
  memory->SystemHeapFree(allocation);
}
} // namespace
int main() {
  InitLogging();
  Check(cvar::SetFlagFromCommandLine("lan_bind_address","127.0.0.1"),"process-local loopback isolation");
  Check(cvar::SetFlagFromCommandLine("lan_gameplay_port","52279"),"process-local native gameplay port");
  Runtime runtime("");RuntimeConfig config;config.tool_mode=true;
  if(runtime.Setup(std::move(config)))return 2;
  // Tool mode returns before InitializeKernel registers any apps. Install the
  // actual XGI app so the imported HLE exercises its normal AppManager route.
  runtime.kernel_state()->app_manager()->RegisterApp(
      std::make_unique<kernel::xam::apps::XgiApp>(runtime.kernel_state()));
  std::atomic<int> result{0};
  auto controller=make_object<XHostThread>(runtime.kernel_state(),128*1024,0,[&]{
    try{Run(runtime.kernel_state());}
    catch(const std::exception& error){std::cerr<<"FAIL after "<<checks<<": "<<error.what()<<'\n';result.store(1);}
    return result.load();
  });
  if(controller->Create()!=X_STATUS_SUCCESS)return 3;
  uint64_t deadline=uint64_t(-100000000LL);
  if(controller->Wait(0,0,0,&deadline)!=X_STATUS_SUCCESS)result=4;
  controller.reset();runtime.Shutdown();
  if(!result.load())std::cout<<"PASS "<<checks<<" actual arbitration guest/HLE checks; title/MP unqualified\n";
  return result.load();
}
