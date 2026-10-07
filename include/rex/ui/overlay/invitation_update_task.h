/**
 * Owns one user-submitted invitation update until completion or dialog close.
 */
#pragma once

#include <chrono>
#include <functional>
#include <future>
#include <optional>
#include <stop_token>
#include <string>
#include <utility>

namespace rex::ui {

class InvitationUpdateTask {
 public:
  using SubmitCallback =
      std::function<std::string(std::string, std::stop_token)>;

  explicit InvitationUpdateTask(SubmitCallback callback)
      : callback_(std::move(callback)) {}
  ~InvitationUpdateTask() { Close(); }
  InvitationUpdateTask(const InvitationUpdateTask&) = delete;
  InvitationUpdateTask& operator=(const InvitationUpdateTask&) = delete;

  bool Submit(std::string code) {
    if (closed_ || pending_.valid() || !callback_)
      return false;
    cancellation_ = std::stop_source();
    // The worker retains its callback and input, never the dialog or this task.
    auto callback = callback_;
    auto token = cancellation_.get_token();
    try {
      pending_ = std::async(std::launch::async,
                            [callback = std::move(callback),
                             code = std::move(code), token]() mutable {
        return callback(std::move(code), token);
      });
    } catch (...) {
      return false;
    }
    return true;
  }

  bool busy() const { return pending_.valid(); }

  std::optional<std::string> Poll() {
    if (closed_ || !pending_.valid() ||
        pending_.wait_for(std::chrono::seconds(0)) !=
            std::future_status::ready)
      return std::nullopt;
    try {
      return pending_.get();
    } catch (...) {
      return "Invitation unavailable.";
    }
  }

  void Close() {
    if (closed_)
      return;
    closed_ = true;
    cancellation_.request_stop();
    if (pending_.valid()) {
      // The runtime remains alive until this dialog-owned task is joined.
      try {
        pending_.get();
      } catch (...) {
      }
    }
    callback_ = {};
  }

 private:
  SubmitCallback callback_;
  std::stop_source cancellation_;
  std::future<std::string> pending_;
  bool closed_ = false;
};

}  // namespace rex::ui
