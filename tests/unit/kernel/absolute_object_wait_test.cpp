// Real typed NT waits and native completion objects. Only this bound fixture
// thread sees virtual clock adjustments; host time and other threads are intact.
#include <rex/runtime.h>
#include <rex/logging.h>
#include <rex/chrono/clock.h>
#include <rex/ppc/context.h>
#include <rex/system/xthread.h>
#include <rex/system/xevent.h>
#include <rex/system/xsemaphore.h>
#include <rex/system/xiocompletion.h>
#include <dlfcn.h>
#include <pthread.h>
#include <atomic>
#include <chrono>
#include <cstdint>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <thread>
REX_EXTERN(__imp__NtWaitForSingleObjectEx);
REX_EXTERN(__imp__NtWaitForMultipleObjectsEx);
REX_EXTERN(__imp__NtSignalAndWaitForSingleObjectEx);
using namespace std::chrono_literals;
using rex::X_STATUS;
static std::atomic<uint64_t> fixture_thread{0};
static thread_local int clock_mode = 0;
static thread_local uint64_t clock_origin = 0;
static thread_local std::chrono::steady_clock::time_point clock_start;
static uint64_t RealClock() {
  static auto real = reinterpret_cast<uint64_t (*)()>(dlsym(RTLD_NEXT, "_ZN3rex6chrono5Clock20QueryGuestSystemTimeEv"));
  if (!real) std::abort();
  return real();
}
uint64_t rex::chrono::Clock::QueryGuestSystemTime() {
  if (!clock_mode || fixture_thread.load()!=static_cast<uint64_t>(pthread_self())) return RealClock();
  auto elapsed=std::chrono::steady_clock::now()-clock_start;
  int64_t ticks=std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count()/100;
  if (elapsed>=10ms) ticks+=(clock_mode==1?1000000000LL:-400000LL);
  return static_cast<uint64_t>(static_cast<int64_t>(clock_origin)+ticks);
}
static unsigned checks=0;
static void Check(bool ok,const char* message) { ++checks;if(!ok)throw std::runtime_error(message); }
struct Converter : rex::system::XObject { using XObject::TimeoutTicksToMs; };
int main() {
  rex::InitLogging();rex::Runtime runtime("");rex::RuntimeConfig config;config.tool_mode=true;
  if(runtime.Setup(std::move(config))) return 2;
  int result=0;
  auto worker=rex::system::object_ref<rex::system::XHostThread>(new rex::system::XHostThread(runtime.kernel_state(),128*1024,0,[&] {
    auto* thread=rex::system::XThread::GetCurrentThread();auto* memory=runtime.memory();auto address=memory->SystemHeapAlloc(4096);
    fixture_thread=static_cast<uint64_t>(pthread_self());
    try {
      Check(thread&&address,"bound guest state and interval storage");auto* ctx=thread->thread_state()->context();
      auto event=[&](bool ready=false) {auto p=rex::system::object_ref<rex::system::XEvent>(new rex::system::XEvent(runtime.kernel_state()));p->Initialize(false,ready);return p;};
      auto a=event(),b=event();
      auto store=[&](uint64_t ticks) {*memory->TranslateVirtual<rex::be<uint64_t>*>(address)=ticks;};
      auto single=[&](rex::system::XObject* object,uint64_t ticks,uint32_t alertable=0) {
        store(ticks);ctx->r3.u64=object->handle();ctx->r4.u64=1;ctx->r5.u64=alertable;ctx->r6.u64=address;
        __imp__NtWaitForSingleObjectEx(*ctx,memory->virtual_membase());return ctx->r3.u32;
      };
      auto multiple=[&](bool any,uint64_t ticks,uint32_t alertable=0) {
        store(ticks);auto* handles=memory->TranslateVirtual<rex::be<uint32_t>*>(address+32);handles[0]=a->handle();handles[1]=b->handle();
        ctx->r3.u64=2;ctx->r4.u64=address+32;ctx->r5.u64=any;ctx->r6.u64=1;ctx->r7.u64=alertable;ctx->r8.u64=address;
        __imp__NtWaitForMultipleObjectsEx(*ctx,memory->virtual_membase());return ctx->r3.u32;
      };
      auto adjusted=[&](int mode) {clock_mode=mode;clock_origin=RealClock();clock_start=std::chrono::steady_clock::now();};
      Check(single(a.get(),RealClock()-1)==X_STATUS_TIMEOUT,"expired empty object times out");a->Set(0,false);
      Check(single(a.get(),RealClock()-1)==X_STATUS_SUCCESS,"expired ready object still satisfies wait");
      Check(single(a.get(),0)==X_STATUS_TIMEOUT,"auto-reset signal consumed once");
      auto began=std::chrono::steady_clock::now();Check(single(a.get(),RealClock()+300000)==X_STATUS_TIMEOUT,"future empty object times out");
      Check(std::chrono::steady_clock::now()-began>=25ms,"future deadline actually waits");
      Check(Converter::TimeoutTicksToMs(std::numeric_limits<int64_t>::max())==UINT32_MAX,"huge absolute converter saturates before narrowing");
      Check(Converter::TimeoutTicksToMs(1)==0,"expired positive converter is immediate");
      adjusted(1);began=std::chrono::steady_clock::now();Check(single(a.get(),clock_origin+100000000)==X_STATUS_TIMEOUT,"forward clock expires long object deadline");
      Check(std::chrono::steady_clock::now()-began>=10ms&&std::chrono::steady_clock::now()-began<350ms,"forward clock is observed within bounded slice");
      adjusted(-1);began=std::chrono::steady_clock::now();Check(single(a.get(),clock_origin+250000)==X_STATUS_TIMEOUT,"backward clock preserves absolute deadline");
      Check(std::chrono::steady_clock::now()-began>=60ms&&std::chrono::steady_clock::now()-began<500ms,"backward clock extends actual wait");clock_mode=0;
      b->Set(0,false);Check(multiple(true,RealClock()-1)==1,"expired WaitAny returns ready object's index");
      a->Set(0,false);b->Set(0,false);Check(multiple(false,RealClock()-1)==X_STATUS_SUCCESS,"expired WaitAll consumes a fully ready set");
      Check(single(a.get(),0)==X_STATUS_TIMEOUT&&single(b.get(),0)==X_STATUS_TIMEOUT,"WaitAll consumes both signals exactly once");
      a->Set(0,false);began=std::chrono::steady_clock::now();Check(multiple(false,RealClock()+1500000)==X_STATUS_TIMEOUT,"absolute WaitAll times out across slices");
      Check(std::chrono::steady_clock::now()-began>=140ms,"WaitAll retains future duration across slices");
      Check(single(a.get(),0)==X_STATUS_SUCCESS,"failed sliced WaitAll preserves partial auto-reset signal");
      began=std::chrono::steady_clock::now();Check(multiple(true,RealClock()+250000)==X_STATUS_TIMEOUT,"future empty WaitAny times out");
      Check(std::chrono::steady_clock::now()-began>=20ms,"future WaitAny actually waits");
      unsigned callbacks=0;thread->thread()->QueueUserCallback([&]{++callbacks;});
      Check(single(a.get(),RealClock()+100000000,1)==X_STATUS_USER_APC&&callbacks==1,"absolute single wait preserves pending APC delivery");
      thread->thread()->QueueUserCallback([&]{++callbacks;});
      Check(multiple(true,RealClock()+100000000,1)==X_STATUS_USER_APC&&callbacks==2,"absolute multiple wait preserves pending APC delivery");
      thread->thread()->QueueUserCallback([&]{++callbacks;});
      Check(single(a.get(),RealClock()-1,1)==X_STATUS_USER_APC&&callbacks==3,"expired alertable single wait delivers pending APC");
      thread->thread()->QueueUserCallback([&]{++callbacks;});
      Check(multiple(true,RealClock()-1,1)==X_STATUS_USER_APC&&callbacks==4,"expired alertable multiple wait delivers pending APC");
      adjusted(1);began=std::chrono::steady_clock::now();
      Check(multiple(true,clock_origin+100000000)==X_STATUS_TIMEOUT,"forward clock expires absolute WaitAny");
      Check(std::chrono::steady_clock::now()-began>=10ms&&std::chrono::steady_clock::now()-began<350ms,"WaitAny rechecks clock within bounded slice");clock_mode=0;
      auto signal=rex::system::object_ref<rex::system::XSemaphore>(new rex::system::XSemaphore(runtime.kernel_state()));Check(signal->Initialize(0,16),"real signal semaphore initializes");
      store(RealClock()+2200000);ctx->r3.u64=signal->handle();ctx->r4.u64=a->handle();ctx->r5.u64=0;ctx->r6.u64=0;ctx->r7.u64=address;
      began=std::chrono::steady_clock::now();__imp__NtSignalAndWaitForSingleObjectEx(*ctx,memory->virtual_membase());
      Check(ctx->r3.u32==X_STATUS_TIMEOUT&&std::chrono::steady_clock::now()-began>=210ms,"signal-and-wait honors multi-slice absolute deadline");
      Check(single(signal.get(),0)==X_STATUS_SUCCESS,"signal-and-wait actually signals source");
      Check(single(signal.get(),0)==X_STATUS_TIMEOUT,"signal source is signaled once across all slices");
      auto io=rex::system::object_ref<rex::system::XIOCompletion>(new rex::system::XIOCompletion(runtime.kernel_state()));
      rex::system::XIOCompletion::IONotification expected{17,23,0,1234},output{91,92,93,94};
      Check(!io->WaitForNotification(RealClock()-1,&output)&&output.key_context==91&&output.num_bytes==94,"expired empty completion preserves output");
      io->QueueNotification(expected);Check(io->WaitForNotification(RealClock()-1,&output)&&output.key_context==17&&output.apc_context==23&&output.num_bytes==1234,"expired ready completion pops actual packet");
      began=std::chrono::steady_clock::now();Check(!io->WaitForNotification(RealClock()+250000,&output),"future completion timeout is finite");
      Check(std::chrono::steady_clock::now()-began>=20ms,"future completion actually waits");
      std::thread producer([&]{std::this_thread::sleep_for(15ms);io->QueueNotification(expected);});
      bool received=io->WaitForNotification(RealClock()+500000,&output);producer.join();Check(received&&output.status==0&&output.num_bytes==1234,"native producer wakes future completion");
      Check(!io->WaitForNotification(0,&output),"completion packet dequeued exactly once");
      adjusted(1);began=std::chrono::steady_clock::now();
      Check(!io->WaitForNotification(clock_origin+100000000,&output),"forward clock expires absolute completion wait");
      Check(std::chrono::steady_clock::now()-began>=10ms&&std::chrono::steady_clock::now()-began<350ms,"completion wait rechecks clock within bounded slice");
      adjusted(-1);began=std::chrono::steady_clock::now();
      Check(!io->WaitForNotification(clock_origin+250000,&output),"backward clock preserves absolute completion deadline");
      Check(std::chrono::steady_clock::now()-began>=60ms&&std::chrono::steady_clock::now()-began<500ms,"completion deadline follows backward guest-clock adjustment");clock_mode=0;
      began=std::chrono::steady_clock::now();Check(single(a.get(),static_cast<uint64_t>(int64_t(-20000)))==X_STATUS_TIMEOUT,"relative object deadline remains supported");
      Check(std::chrono::steady_clock::now()-began>=1ms,"relative deadline retains native waiting");
    } catch(const std::exception& error) {std::cerr<<"FAIL after "<<checks<<": "<<error.what()<<'\n';result=1;}
    clock_mode=0;fixture_thread=0;if(address)memory->SystemHeapFree(address);return result;
  }));
  if(worker->Create()!=X_STATUS_SUCCESS)return 3;worker->Wait(0,0,0,nullptr);worker.reset();runtime.Shutdown();
  if(!result)std::cout<<"PASS "<<checks<<" actual typed absolute-object checks\n";return result;
}
