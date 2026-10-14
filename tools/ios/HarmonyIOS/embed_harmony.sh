#!/bin/bash
# Xcode build phase: swaps in the CMake-built game binary and its dylibs, then
# signs each dylib with the identity Xcode picked (Xcode signs the app itself).
set -euo pipefail
# HARMONY_SKIP_EMBED=1 leaves the stub app alone (to check signing by itself).
[ "${HARMONY_SKIP_EMBED:-0}" = "1" ] && exit 0
build=${HARMONY_IOS_BUILD_DIR:-"$SRCROOT/../../out/build/ios-arm64-relwithdebinfo"}
# CMake lays out iOS executables as <name>.app with the dylibs beside them.
built="$build/harmonyrecomp.app"
test -x "$built/harmonyrecomp" || { echo "error: run tools/ios/build_ios.sh first (no $built/harmonyrecomp)"; exit 1; }

app="$TARGET_BUILD_DIR/$WRAPPER_NAME"
cp "$built/harmonyrecomp" "$TARGET_BUILD_DIR/$EXECUTABLE_PATH"
mkdir -p "$app/Frameworks"
find "$built" -maxdepth 1 -name '*.dylib' -type f -exec cp {} "$app/Frameworks/" \;

if [ "${CODE_SIGNING_ALLOWED:-YES}" = "YES" ] && [ -n "${EXPANDED_CODE_SIGN_IDENTITY:-}" ]; then
  for lib in "$app/Frameworks"/*.dylib; do
    codesign --force --sign "$EXPANDED_CODE_SIGN_IDENTITY" --timestamp=none "$lib"
  done
  # Xcode skips its own CodeSign step when the stub is unchanged, which would
  # leave the swapped-in binary unsigned; sign the app here with Xcode's
  # entitlements (Xcode re-signs it the same way when it does run).
  codesign --force --sign "$EXPANDED_CODE_SIGN_IDENTITY" --timestamp=none \
    --entitlements "$TARGET_TEMP_DIR/$WRAPPER_NAME.xcent" --generate-entitlement-der "$app"
fi
