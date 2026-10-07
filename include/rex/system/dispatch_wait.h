#pragma once

namespace rex::system {

// Keep shutdown and spurious wakeups away from the queue's front/pop pair.
template <typename Condition, typename Lock, typename Running, typename Queue>
bool WaitForDispatchWork(Condition& condition, Lock& lock, Running& running, Queue& queue) {
  condition.wait(lock, [&] { return !running || !queue.empty(); });
  return running && !queue.empty();
}

}  // namespace rex::system
