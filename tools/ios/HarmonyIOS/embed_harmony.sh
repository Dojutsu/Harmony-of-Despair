#!/bin/bash
# Xcode build phase: swaps in the CMake-built game binary and its dylibs, then
# signs each dylib with the identity Xcode picked (Xcode signs the app itself).
set -euo pipefail
build=${HARMONY_IOS_BUILD_DIR:-"$SRCROOT/../../out/build/ios-arm64-relwithdebinfo"}
test -x "$build/harmonyrecomp" || { echo "error: run tools/ios/build_ios.sh first (no $build/harmonyrecomp)"; exit 1; }

app="$TARGET_BUILD_DIR/$WRAPPER_NAME"
cp "$build/harmonyrecomp" "$TARGET_BUILD_DIR/$EXECUTABLE_PATH"
mkdir -p "$app/Frameworks"
find "$build" -maxdepth 1 -name '*.dylib' -type f -exec cp {} "$app/Frameworks/" \;

if [ "${CODE_SIGNING_ALLOWED:-YES}" = "YES" ] && [ -n "${EXPANDED_CODE_SIGN_IDENTITY:-}" ]; then
  for lib in "$app/Frameworks"/*.dylib; do
    codesign --force --sign "$EXPANDED_CODE_SIGN_IDENTITY" --timestamp=none "$lib"
  done
fi
