#include <catch2/catch_test_macros.hpp>

#include <array>
#include <atomic>
#include <barrier>
#include <cstdint>
#include <limits>
#include <thread>

#include <rex/graphics/command_processor.h>
#include <rex/graphics/graphics_system.h>
#include <rex/types.h>

namespace {
// Exercise the production packet and vblank methods without starting a GPU or
// a guest dispatcher. IssueSwap needs no rendering for this counter contract.
class CounterCommandProcessor final : public rex::graphics::CommandProcessor {
 public:
  explicit CounterCommandProcessor(rex::graphics::GraphicsSystem* graphics)
      : CommandProcessor(graphics, nullptr) {}
  void SetCounter(uint32_t value) { counter_ = value; }
  bool Swap() {
    std::array<rex::be<uint32_t>, 4> packet{
        rex::graphics::xenos::kSwapSignature, 0, 1280, 720};
    rex::memory::RingBuffer reader(reinterpret_cast<uint8_t*>(packet.data()),
                                   sizeof(packet));
    return ExecutePacketType3_XE_SWAP(&reader, 0, 4);
  }
  void IssueSwap(uint32_t, uint32_t, uint32_t) override { ++swaps_; }
  uint32_t swaps() const { return swaps_; }
 private:
  bool SetupContext() override { return true; }
  void ShutdownContext() override {}
  uint32_t swaps_ = 0;  // Only the packet producer accesses this during a run.
};

class CounterGraphics final : public rex::graphics::GraphicsSystem {
 public:
  CounterGraphics() {
    command_processor_ = std::make_unique<CounterCommandProcessor>(this);
  }
  std::string name() const override { return "video-counter-fixture"; }
  CounterCommandProcessor& processor() {
    return static_cast<CounterCommandProcessor&>(*command_processor_);
  }
  void Vblank() { MarkVblank(); }
 private:
  void CreateProvider(bool) override {}
  std::unique_ptr<rex::graphics::CommandProcessor> CreateCommandProcessor() override {
    return nullptr;
  }
};
}  // namespace

TEST_CASE("actual vblank and swap counter preserves uint32 wrap",
          "[graphics][video-counter]") {
  CounterGraphics graphics;
  auto& processor = graphics.processor();
  CHECK(processor.counter() == 0);
  graphics.Vblank();
  CHECK(processor.counter() == 1);
  REQUIRE(processor.Swap());
  CHECK(processor.counter() == 2);
  CHECK(processor.swaps() == 1);
  processor.SetCounter(std::numeric_limits<uint32_t>::max() - 1);
  graphics.Vblank();
  CHECK(processor.counter() == std::numeric_limits<uint32_t>::max());
  REQUIRE(processor.Swap());
  CHECK(processor.counter() == 0);
}

TEST_CASE("actual concurrent vblank and swap producers never lose progress",
          "[graphics][video-counter][race]") {
  CounterGraphics graphics;
  auto& processor = graphics.processor();
  constexpr uint32_t kIncrements = 100000;
  for (unsigned pass = 0; pass != 6; ++pass) {
    processor.SetCounter(0);
    std::barrier start(3);
    std::atomic<unsigned> finished{0};
    std::atomic<bool> packets_valid{true};
    std::jthread vblank([&] {
      start.arrive_and_wait();
      for (uint32_t i = 0; i != kIncrements; ++i) graphics.Vblank();
      finished.fetch_add(1, std::memory_order_release);
    });
    std::jthread swap([&] {
      start.arrive_and_wait();
      for (uint32_t i = 0; i != kIncrements; ++i) {
        if (!processor.Swap()) packets_valid.store(false);
      }
      finished.fetch_add(1, std::memory_order_release);
    });
    start.arrive_and_wait();
    uint32_t previous = 0;
    bool monotonic = true;
    while (finished.load(std::memory_order_acquire) != 2) {
      const auto observed = processor.counter();
      monotonic &= observed >= previous && observed <= 2 * kIncrements;
      previous = observed;
      std::this_thread::yield();
    }
    vblank.join();
    swap.join();
    INFO("producer pass " << pass);
    CHECK(packets_valid.load());
    CHECK(monotonic);
    CHECK(processor.counter() == 2 * kIncrements);
    CHECK(processor.swaps() == (pass + 1) * kIncrements);
  }
}
