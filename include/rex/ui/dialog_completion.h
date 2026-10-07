#pragma once

#include <atomic>
#include <rex/system/xtypes.h>
#include <rex/thread.h>

namespace rex::ui {

struct DialogCompletion {
  X_RESULT result = X_ERROR_CANCELLED;
  uint32_t extended_error = 0;
  uint32_t length = 0;
};

// The UI submitter must run attachment synchronously before returning true.
// Failed UI delivery deletes the owned dialog and deterministically cancels.
template <typename Dialog, typename Close, typename Post>
DialogCompletion RunDialogAndWait(Dialog* dialog, Close close, Post post,
                                  std::atomic<int>& shown) {
  DialogCompletion completion;
  dialog->set_close_callback([&] {
    completion.result = close(dialog, completion.extended_error, completion.length);
  });
  thread::Fence fence;
  if (post([&] { dialog->Then(&fence); })) {
    ++shown;
    fence.Wait();
    --shown;
  } else {
    delete dialog;
  }
  return completion;
}

}  // namespace rex::ui
