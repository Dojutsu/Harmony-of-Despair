// Linux timer queue wakeups, deadline ordering and callback lifetime regression.
#include <rex/thread/timer_queue.h>
#include <rex/logging.h>
#include <atomic>
#include <chrono>
#include <cmath>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <time.h>
#include <unistd.h>
using namespace std::chrono_literals;
std::atomic<unsigned> checks{0};
void check(bool value){++checks;if(!value){std::cerr<<"failed check "<<checks<<"\n";std::abort();}}
template<class F> void ready(F& f){check(f.wait_for(8s)==std::future_status::ready);}
uint64_t cpu_ns(){timespec t{};check(clock_gettime(CLOCK_THREAD_CPUTIME_ID,&t)==0);return uint64_t(t.tv_sec)*1000000000+t.tv_nsec;}
template<class Item,class Once,class Recurring> void exercise(const char* name,Once once,Recurring recurring){
 using Clock=typename Item::clock;
 // The two timestamps execute on the actual queue dispatch thread.
 std::promise<uint64_t> p1,p2;auto f1=p1.get_future(),f2=p2.get_future();
 once([&](void*){p1.set_value(cpu_ns());},nullptr,Clock::now()+20ms);ready(f1);auto before=f1.get();
 auto begin=Clock::now();once([&](void*){p2.set_value(cpu_ns());},nullptr,begin+2s);ready(f2);auto after=f2.get();
 auto elapsed=std::chrono::duration<double>(Clock::now()-begin).count();check(after>=before);check(elapsed>=2);
 std::cout<<"{\"variant\":\""<<name<<"\",\"idle_wall_seconds\":"<<elapsed<<",\"dispatch_cpu_seconds\":"<<double(after-before)/1e9<<"}\n";
 // Leave the queue truly empty; its maximum deadline must not spin or overflow.
 std::promise<uint64_t> empty_start,empty_end;auto esf=empty_start.get_future(),eef=empty_end.get_future();
 once([&](void*){empty_start.set_value(cpu_ns());},nullptr,Clock::now()+10ms);ready(esf);auto empty_before=esf.get();
 std::this_thread::sleep_for(2s);
 once([&](void*){empty_end.set_value(cpu_ns());},nullptr,Clock::now());ready(eef);auto empty_after=eef.get();
 check(empty_after>=empty_before);
 std::cout<<"{\"variant\":\""<<name<<"\",\"empty_queue_wall_seconds\":2,\"dispatch_cpu_seconds\":"<<double(empty_after-empty_before)/1e9<<"}\n";
 // A newly submitted earlier timer must wake the queue and precede its old head.
 std::atomic<unsigned> order{0};std::promise<void> early,late;auto ef=early.get_future(),lf=late.get_future();
 auto due=Clock::now();once([&](void*){check(order.fetch_add(1)==1);late.set_value();},nullptr,due+150ms);
 once([&](void*){check(Clock::now()>=due+20ms);check(order.fetch_add(1)==0);early.set_value();},nullptr,due+20ms);
 ready(ef);ready(lf);check(order==2);
 // Cancellation must prevent a callback; a later callback proves queue progress.
 std::atomic<unsigned> canceled{0};auto c=once([&](void*){++canceled;},nullptr,Clock::now()+40ms).lock();check(bool(c));c->Disarm();
 std::promise<void> barrier;auto bf=barrier.get_future();once([&](void*){barrier.set_value();},nullptr,Clock::now()+80ms);ready(bf);check(canceled==0);
 // Recurring self-disarm is safe on the queue's callback thread.
 std::mutex item_mutex;std::weak_ptr<Item> recurring_item;std::atomic<unsigned> count{0};std::promise<void> ten;auto tf=ten.get_future();
 auto first=Clock::now()+20ms;
 auto w=recurring([&](void*){if(++count==10){std::lock_guard lock(item_mutex);auto owned=recurring_item.lock();check(bool(owned));owned->Disarm();ten.set_value();}},nullptr,first,8ms);
 {std::lock_guard lock(item_mutex);recurring_item=w;}ready(tf);std::this_thread::sleep_for(30ms);check(count==10);
 // Disarm from another thread must wait for the active callback to finish.
 std::promise<void> entered;auto inf=entered.get_future();std::atomic<bool> release{false},callback_done{false},disarmed{false};
 auto active=once([&](void*){entered.set_value();release.wait(false);callback_done=true;},nullptr,Clock::now()+10ms).lock();check(bool(active));ready(inf);
 std::thread cancel([&]{active->Disarm();check(callback_done.load());disarmed=true;});
 std::this_thread::sleep_for(10ms);check(!disarmed);release=true;release.notify_all();cancel.join();check(disarmed);
 // More than 512 concurrent submissions exercise ring wrap and producer wakeups.
 constexpr unsigned producers=6, per_producer=200,total=producers*per_producer;
 std::atomic<unsigned> fired{0};std::promise<void> all;auto af=all.get_future();std::vector<std::thread> threads;
 for(unsigned i=0;i<producers;++i)threads.emplace_back([&]{for(unsigned j=0;j<per_producer;++j)
  once([&](void*){if(++fired==total)all.set_value();},nullptr,Clock::now()+100ms);});
 for(auto& t:threads)t.join();ready(af);check(fired==total);
 // A past deadline is delivered, without replaying any one-shot callback.
 std::promise<void> past;auto pf=past.get_future();once([&](void*){past.set_value();},nullptr,Clock::now()-1s);ready(pf);
 std::cout<<"{\"variant\":\""<<name<<"\",\"concurrent_one_shots\":"<<fired<<",\"recurring_callbacks\":"<<count<<",\"checks_passed\":true}\n";
}
int main(){rex::InitLogging();

 exercise<rex::thread::TimerQueueWaitItem>("production",rex::thread::QueueTimerOnce,rex::thread::QueueTimerRecurring);
 std::cout<<"PASS "<<checks<<" actual timer queue checks\n";
}
