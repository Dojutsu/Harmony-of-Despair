// Registered leaf infrastructure acceptance; no framework signal interception.
#include <rex/platform/guest_access.h>
#include <rex/platform/exceptions.h>
#include <signal.h>
#include <sys/mman.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <unistd.h>
#include <atomic>
#include <cstdio>
#include <cstring>
#include <thread>
#include <vector>

namespace {
std::atomic<int> checks{0},failures{0};
void Check(bool okay,const char* name){++checks;if(!okay){++failures;std::fprintf(stderr,"FAIL %s\n",name);}}
void Prior(int sig,siginfo_t* info,void* context){_exit(sig==SIGSEGV&&info&&context?42:43);}
void NativeChain(bool custom){
  std::fflush(nullptr);pid_t child=fork();
  if(!child){struct rlimit limit{0,0};setrlimit(RLIMIT_CORE,&limit);alarm(4);
    if(custom){struct sigaction prior{};sigemptyset(&prior.sa_mask);prior.sa_flags=SA_SIGINFO;prior.sa_sigaction=Prior;sigaction(SIGSEGV,&prior,nullptr);}
    rex::initialize_seh();rex::SehGuard guard;
    auto* page=mmap(nullptr,4096,PROT_NONE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
    *static_cast<volatile unsigned char*>(page)=1;_exit(44);
  }
  int status=0;Check(child>0&&waitpid(child,&status,0)==child,"native_child_reaped");
  Check(custom?(WIFEXITED(status)&&WEXITSTATUS(status)==42):(WIFSIGNALED(status)&&WTERMSIG(status)==SIGSEGV),"unregistered_native_fault_chains_without_sigabrt");
}
void Captures(){
  using namespace rex::guest;
  size_t size=sysconf(_SC_PAGESIZE);auto* page=static_cast<unsigned char*>(mmap(nullptr,size*2,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0));
  Check(page!=MAP_FAILED,"mapped");if(page==MAP_FAILED)return;mprotect(page+size,size,PROT_NONE);
  for(size_t width:{1u,2u,4u,8u}){
    uint64_t out=0xdeadbeef11223344,expected=out;auto read=CaptureRead(page+size,&out,width);
    Check(!read.success&&out==expected,"failed_load_output_uncommitted");Check(read.fault.access_intent==0&&read.fault.address==reinterpret_cast<uintptr_t>(page+size),"read_address_and_intent");
    auto write=CaptureWrite(page+size,&expected,width);Check(!write.success&&write.fault.access_intent==1,"write_intent");
    Check(write.fault.signal_number==SIGSEGV&&write.fault.signal_code==SEGV_ACCERR&&(write.fault.page_fault_error&2),"kernel_write_metadata");
    Check(write.fault.integer_registers[4]==write.fault.stack_pointer&&write.fault.instruction_pointer,"native_stack_and_pc");
    auto valid=CaptureWrite(page,&expected,width);out=0;auto reread=CaptureRead(page,&out,width);
    uint64_t mask=width==8?~uint64_t(0):((uint64_t(1)<<(width*8))-1);
    Check(valid.success&&reread.success&&(out&mask)==(expected&mask),"successful_width_retains_bits");
  }
  alignas(16) unsigned char value[16],output[16];for(int i=0;i<16;++i)value[i]=i+1;memset(output,0xcc,16);
  auto vector=CaptureVectorRead(page+size,output);Check(!vector.success&&vector.fault.access_intent==0&&output[0]==0xcc&&output[15]==0xcc,"vector_failure_uncommitted");
  vector=CaptureVectorWrite(page+size,value);Check(!vector.success&&vector.fault.access_intent==1,"vector_store_intent");
  vector=CaptureVectorWrite(page,value);auto loaded=CaptureVectorRead(page,output);Check(vector.success&&loaded.success&&!memcmp(value,output,16),"vector_success");
  uint32_t old32=77;uint64_t old64=88;auto cas32=CaptureCompareExchange32(page+size,0,1,&old32);auto cas64=CaptureCompareExchange64(page+size,0,1,&old64);
  Check(!cas32.success&&cas32.fault.access_intent==1&&old32==77,"cas32_fault_not_comparison");Check(!cas64.success&&cas64.fault.access_intent==1&&old64==88,"cas64_fault_no_result_commit");
  *reinterpret_cast<uint64_t*>(page)=0;cas64=CaptureCompareExchange64(page,0,1,&old64);Check(cas64.success&&old64==0&&*reinterpret_cast<uint64_t*>(page)==1,"cas64_match");
  cas64=CaptureCompareExchange64(page,0,2,&old64);Check(cas64.success&&old64==1&&*reinterpret_cast<uint64_t*>(page)==1,"cas64_mismatch_is_successful_access");
  auto* source=static_cast<unsigned char*>(mmap(nullptr,size*2,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0));memset(source,0x5a,size*2);
  auto bulk=CaptureCopy(page,source,size*2);Check(!bulk.success&&bulk.completed==size&&bulk.fault.access_intent==1,"forward_bulk_completed_prefix");
  Check(bulk.fault.integer_registers[1]==size&&bulk.fault.integer_registers[6]==reinterpret_cast<uintptr_t>(source+size)&&bulk.fault.integer_registers[7]==reinterpret_cast<uintptr_t>(page+size),"bulk_progress_context");
  mprotect(page,size,PROT_READ);mprotect(page+size,size,PROT_READ|PROT_WRITE);bulk=CaptureCopy(page+size,source+size,size);
  Check(bulk.success&&bulk.completed==size&&!memcmp(page+size,source+size,size),"bulk_suffix_without_prefix_replay");
  Check(!HasArmedAccessFrame(),"access_frame_tls_cleared");munmap(source,size*2);munmap(page,size*2);
}
}
int main(){NativeChain(false);NativeChain(true);Captures();std::vector<std::thread> workers;for(int i=0;i<4;++i)workers.emplace_back(Captures);for(auto& worker:workers)worker.join();
  std::printf("{\"fixture\":\"guest_access_capture\",\"checks\":%d,\"failures\":%d}\n",checks.load(),failures.load());return failures?1:0;
}
