/**
 * @file        input/touch/touch_haptics_ios.mm
 * @brief       Light tap feedback for the on-screen touch controls.
 *
 * @license     BSD 3-Clause License
 *              See LICENSE file in the project root for full license text.
 */

#import <UIKit/UIKit.h>

namespace rex::input::touch {

// UIKit feedback generators belong to the main thread; touches arrive there
// too, but hop over in case a caller is elsewhere.
void HapticTap() {
  dispatch_async(dispatch_get_main_queue(), ^{
    static UIImpactFeedbackGenerator* generator =
        [[UIImpactFeedbackGenerator alloc] initWithStyle:UIImpactFeedbackStyleLight];
    [generator impactOccurred];
    [generator prepare];
  });
}

}  // namespace rex::input::touch
