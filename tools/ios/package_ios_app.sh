#!/bin/bash
# Assembles an unsigned "Harmony.app" for iPadOS/iOS from an iOS build.
# The game files are never included: they're copied into the app's
# Documents folder with the Files app and imported by the first-run screen.
#
# usage: tools/ios/package_ios_app.sh <build-dir> <app-path> [icon.png]
set -euo pipefail

build_dir=$(cd "$1" && pwd)
app=$2
icon_png=${3:-}

# CMake lays out iOS executables as <name>.app with the dylibs beside them.
built="$build_dir/harmonyrecomp.app"
test -x "$built/harmonyrecomp" || { echo "no harmonyrecomp.app in $build_dir" >&2; exit 1; }
rm -rf "$app"
mkdir -p "$app/Frameworks"

cp "$built/harmonyrecomp" "$app/harmonyrecomp"
# iOS loads code only from the bundle; the runtime looks in Frameworks for
# MoltenVK and the guest modules (rpath @executable_path/Frameworks).
find "$built" -maxdepth 1 -name '*.dylib' -type f -exec cp {} "$app/Frameworks/" \;

version=$(git -C "$(dirname "$0")/../.." describe --tags --always 2>/dev/null || echo dev)
# Same Info.plist the Xcode wrapper project uses, with its build settings filled in.
sed -e "s|\$(PRODUCT_BUNDLE_IDENTIFIER)|${BUNDLE_ID:-net.dojutsu.harmony.ios}|" \
    -e "s|\$(EXECUTABLE_NAME)|harmonyrecomp|" \
    -e "s|\$(CURRENT_PROJECT_VERSION)|${version}|" \
    -e "s|\$(IPHONEOS_DEPLOYMENT_TARGET)|${IOS_DEPLOYMENT_TARGET:-17.0}|" \
    "$(dirname "$0")/Info.plist" > "$app/Info.plist"
plutil -lint "$app/Info.plist" >/dev/null

if [ -n "$icon_png" ] && [ -f "$icon_png" ]; then
  sips -z 120 120 "$icon_png" --out "$app/AppIcon60x60@2x.png" >/dev/null
  sips -z 152 152 "$icon_png" --out "$app/AppIcon76x76@2x~ipad.png" >/dev/null
  sips -z 167 167 "$icon_png" --out "$app/AppIcon83.5x83.5@2x~ipad.png" >/dev/null
  /usr/libexec/PlistBuddy -c 'Add :CFBundleIcons dict' \
    -c 'Add :CFBundleIcons:CFBundlePrimaryIcon dict' \
    -c 'Add :CFBundleIcons:CFBundlePrimaryIcon:CFBundleIconFiles array' \
    -c 'Add :CFBundleIcons:CFBundlePrimaryIcon:CFBundleIconFiles:0 string AppIcon60x60' \
    -c 'Add :CFBundleIcons~ipad dict' \
    -c 'Add :CFBundleIcons~ipad:CFBundlePrimaryIcon dict' \
    -c 'Add :CFBundleIcons~ipad:CFBundlePrimaryIcon:CFBundleIconFiles array' \
    -c 'Add :CFBundleIcons~ipad:CFBundlePrimaryIcon:CFBundleIconFiles:0 string AppIcon76x76' \
    -c 'Add :CFBundleIcons~ipad:CFBundlePrimaryIcon:CFBundleIconFiles:1 string AppIcon83.5x83.5' \
    "$app/Info.plist"
fi

echo "Assembled $app ($(find "$app/Frameworks" -name '*.dylib' | wc -l | tr -d ' ') dylibs)"
