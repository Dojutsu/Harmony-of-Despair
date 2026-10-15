/**
 * @file        rex/system/xam/title_presence.h
 * @brief       The title's current rich-presence context, for host UI such as touch controls
 *
 * @license     BSD 3-Clause License
 *              See LICENSE file in the project root for full license text.
 */
#pragma once

#include <cstdint>

namespace rex::system::xam {

/// Last X_CONTEXT_PRESENCE (0x8001) value the title set for user 0, or 0 before any.
uint32_t TitlePresenceContext();

}  // namespace rex::system::xam
