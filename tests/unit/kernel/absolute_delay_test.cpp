// Typed HLE with a real bound XHostThread. Virtual time/sleeps are limited to
// this fixture's own thread; all other calls forward unchanged. No host clock edit.
#include <rex/runtime.h>
#include <rex/logging.h>
#include <rex/chrono/clock.h>
#include <rex/ppc/context.h>
#include <rex/system/xthread.h>
#include <dlfcn.h>
#include <pthread.h>
#include <time.h>
#include <atomic>
#include <chrono>
#include <cstdint>
#include <iostream>
#include <limits>
#include <stdexcept>
REX_EXTERN(__imp__KeDelayExecutionThread);
using rex::X_STATUS;
static std::atomic<uint64_t> observed_thread{0};
static thread_local bool virtual_clock = false;
static thread_local uint64_t filetime = 123456789000000000ULL;
static thread_local int first_clock_jump = 0;
static thread_local unsigned sleeps = 0;
static thread_local uint64_t total_ns = 0, max_ns = 0;
uint64_t rex::chrono::Clock::QueryGuestSystemTime() {
  static auto real = reinterpret_cast<uint64_t (*)()>(dlsym(RTLD_NEXT, "_ZN3rex6chrono5Clock20QueryGuestSystemTimeEv"));
  if (!real) std::abort();
  if (virtual_clock && observed_thread.load() == static_cast<uint64_t>(pthread_self())) return filetime;
  return real();
}
extern "C" int nanosleep(const timespec* request, timespec* remaining) {
  static auto real = reinterpret_cast<int (*)(const timespec*, timespec*)>(dlsym(RTLD_NEXT, "nanosleep"));
  if (!real) std::abort();
  if (observed_thread.load() == static_cast<uint64_t>(pthread_self())) {
    uint64_t ns = uint64_t(request->tv_sec)*1000000000ULL + request->tv_nsec;
    ++sleeps; total_ns += ns; max_ns = std::max(max_ns,ns);
    if (virtual_clock) {
      if (sleeps==1 && first_clock_jump==1) filetime += 1000000000ULL;
      if (sleeps==1 && first_clock_jump==-1) filetime -= 2000000ULL;
      filetime += ns/100;
      return 0;
    }
  }
  return real(request,remaining);
}
static unsigned checks = 0;
static void Check(bool ok,const char* text) { ++checks; if (!ok) throw std::runtime_error(text); }
int main() {
  rex::InitLogging(); rex::Runtime runtime(""); rex::RuntimeConfig config; config.tool_mode=true;
  if (runtime.Setup(std::move(config))) return 2;
  int result=0;
  auto controller=rex::system::object_ref<rex::system::XHostThread>(new rex::system::XHostThread(runtime.kernel_state(),128*1024,0,[&] {
    auto* current=rex::system::XThread::GetCurrentThread();auto* memory=runtime.memory();uint32_t address=memory->SystemHeapAlloc(4096);
    try {
      Check(current && address,"real bound guest thread and interval allocation");
      auto* ctx=current->thread_state()->context();
      auto invoke=[&](int64_t interval,uint32_t alertable=0) {
        *memory->TranslateVirtual<rex::be<int64_t>*>(address)=interval;
        ctx->r3.u64=1;ctx->r4.u64=alertable;ctx->r5.u64=address;
        __imp__KeDelayExecutionThread(*ctx,memory->virtual_membase());return ctx->r3.u32;
      };
      auto reset=[&](bool simulated,int jump=0) {
        virtual_clock=simulated;first_clock_jump=jump;filetime=123456789000000000ULL;
        sleeps=0;total_ns=0;max_ns=0;observed_thread=static_cast<uint64_t>(pthread_self());
      };
      reset(true);Check(invoke(int64_t(filetime-1))==X_STATUS_SUCCESS,"expired absolute interval succeeds");
      Check(sleeps==0,"expired nonalertable deadline adds no artificial sleep");
      reset(true);uint64_t deadline=filetime+500000;Check(invoke(int64_t(deadline))==X_STATUS_SUCCESS,"future absolute interval succeeds");
      Check(filetime>=deadline && sleeps==1 && total_ns==50000000,"absolute future duration is not treated as zero");
      reset(true);deadline=filetime+2500000;Check(invoke(int64_t(deadline))==X_STATUS_SUCCESS,"multi-slice absolute interval succeeds");
      Check(filetime>=deadline && sleeps==3 && total_ns==250000000 && max_ns<=100000000,"long absolute delay uses bounded clock-sensitive slices");
      reset(true,1);deadline=filetime+100000000;Check(invoke(int64_t(deadline))==X_STATUS_SUCCESS,"clock forward adjustment completes delay");
      Check(sleeps==1 && max_ns<=100000000,"forward adjustment is recognized at next bounded slice");
      reset(true,-1);deadline=filetime+500000;Check(invoke(int64_t(deadline))==X_STATUS_SUCCESS,"clock backward adjustment preserves deadline");
      Check(sleeps==3 && total_ns==250000000 && filetime>=deadline,"backward adjustment extends the absolute wait");
      reset(true);deadline=std::numeric_limits<int64_t>::max();filetime=deadline-25000;
      Check(invoke(int64_t(deadline))==X_STATUS_SUCCESS,"largest positive deadline is safe");
      Check(filetime>=deadline && total_ns==3000000,"submillisecond remainder rounds up without overflow");
      reset(false);auto began=std::chrono::steady_clock::now();deadline=rex::chrono::Clock::QueryGuestSystemTime()+300000;
      Check(invoke(int64_t(deadline))==X_STATUS_SUCCESS,"real native future deadline succeeds");
      auto elapsed=std::chrono::steady_clock::now()-began;
      Check(elapsed>=std::chrono::milliseconds(25) && elapsed<std::chrono::seconds(2) && sleeps>0,"real future deadline actually waits");
      reset(false);began=std::chrono::steady_clock::now();deadline=rex::chrono::Clock::QueryGuestSystemTime()+100000;
      Check(invoke(int64_t(deadline),1)==X_STATUS_SUCCESS,"future alertable deadline succeeds without pending APC");
      Check(std::chrono::steady_clock::now()-began>=std::chrono::milliseconds(8),"alertable future deadline actually waits");
      for (bool expired : {false,true}) {
        reset(false);unsigned callbacks=0;current->thread()->QueueUserCallback([&]{++callbacks;});
        deadline=rex::chrono::Clock::QueryGuestSystemTime();deadline=expired?deadline-1:deadline+100000000;
        Check(invoke(int64_t(deadline),1)==X_STATUS_USER_APC,"absolute alertable wait preserves queued callback result");
        Check(callbacks==1 && sleeps==0,"queued callback is delivered once before sleeping, even at expired deadline");
      }
      reset(false);Check(invoke(-20000)==X_STATUS_SUCCESS,"ordinary relative delay remains successful");
      Check(sleeps>0 && total_ns>=2000000,"ordinary relative delay retains positive native sleep");
    } catch (const std::exception& error) { std::cerr<<"FAIL after "<<checks<<": "<<error.what()<<'\n';result=1; }
    virtual_clock=false;observed_thread=0;if(address) memory->SystemHeapFree(address);return result;
  }));
  if(controller->Create()!=X_STATUS_SUCCESS) return 3;
  controller->Wait(0,0,0,nullptr);controller.reset();runtime.Shutdown();
  if(!result)std::cout<<"PASS "<<checks<<" actual typed absolute-delay checks\n";
  return result;
}
