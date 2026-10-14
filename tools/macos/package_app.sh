#!/bin/bash
# Wraps a finished macOS build into "Harmony of Despair.app" and a zip for
# sharing. The game files are never included; the app's first-run screen
# imports them from the player's own copy.
#
# usage: tools/macos/package_app.sh <build-dir> <output-dir> [icon.png]
set -euo pipefail

build_dir=$(cd "$1" && pwd)
out_dir=$2
icon_png=${3:-}
app="$out_dir/Harmony of Despair.app"

test -x "$build_dir/harmonyrecomp" || { echo "no harmonyrecomp in $build_dir" >&2; exit 1; }
rm -rf "$app"
mkdir -p "$app/Contents/MacOS" "$app/Contents/Resources"

# The runtime looks for its Vulkan loader, MoltenVK and guest modules next to
# the executable, so the whole build output folder goes into Contents/MacOS.
rsync -a --exclude 'CMakeFiles' --exclude '*.a' --exclude '*.cmake' \
  --exclude 'CMakeCache.txt' --exclude 'Testing' --exclude '*_tests' \
  --exclude 'stfs_inspect' --exclude '*.log' --exclude 'harmonyrecomp-user.cfg' \
  --exclude '_deps' --exclude 'include' --exclude 'rexglue-sdk' --exclude '*.pc' \
  --exclude '*.ninja' --exclude '.ninja_*' --exclude 'compile_commands.json' \
  "$build_dir/" "$app/Contents/MacOS/"
# Folders with an extension (vulkan/share/vulkan/icd.d) are refused as code
# inside Contents/MacOS; the runtime also finds the bundle's Resources/vulkan.
mv "$app/Contents/MacOS/vulkan" "$app/Contents/Resources/vulkan"

version=$(git -C "$(dirname "$0")/../.." describe --tags --always 2>/dev/null || echo dev)
cat > "$app/Contents/Info.plist" <<PLIST
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
  <key>CFBundleName</key><string>Harmony of Despair</string>
  <key>CFBundleDisplayName</key><string>Harmony of Despair</string>
  <key>CFBundleIdentifier</key><string>net.dojutsu.harmony</string>
  <key>CFBundleExecutable</key><string>harmonyrecomp</string>
  <key>CFBundlePackageType</key><string>APPL</string>
  <key>CFBundleShortVersionString</key><string>${version}</string>
  <key>CFBundleVersion</key><string>${version}</string>
  <key>CFBundleIconFile</key><string>AppIcon</string>
  <key>LSMinimumSystemVersion</key><string>13.3</string>
  <key>NSHighResolutionCapable</key><true/>
  <key>LSApplicationCategoryType</key><string>public.app-category.games</string>
  <key>GCSupportsControllerUserInteraction</key><true/>
  <key>NSLocalNetworkUsageDescription</key>
  <string>Harmony of Despair finds and joins games with players on your network.</string>
</dict>
</plist>
PLIST

# Optional icon; the emblem art is supplied locally and never committed.
if [ -n "$icon_png" ] && [ -f "$icon_png" ]; then
  iconset=$(mktemp -d)/AppIcon.iconset
  mkdir -p "$iconset"
  for size in 16 32 128 256 512; do
    sips -z $size $size "$icon_png" --out "$iconset/icon_${size}x${size}.png" >/dev/null
    sips -z $((size*2)) $((size*2)) "$icon_png" --out "$iconset/icon_${size}x${size}@2x.png" >/dev/null
  done
  iconutil -c icns "$iconset" -o "$app/Contents/Resources/AppIcon.icns"
fi

# Ad-hoc signature: required on Apple Silicon. Without a paid Apple developer
# certificate, players open it the first time with right-click > Open.
# Sign each binary first (including the Vulkan runtime in Resources), then
# the bundle itself; --deep does not reach code kept under Resources.
find "$app/Contents/MacOS" "$app/Contents/Resources/vulkan/lib" -type f \( -name '*.dylib' -o -perm -u+x \) -print0 |
  xargs -0 codesign --force --sign -
codesign --force --sign - "$app"
codesign --verify --strict "$app"

(cd "$out_dir" && ditto -c -k --keepParent "Harmony of Despair.app" HarmonyRecomp-macos-arm64.zip)
echo "built: $app"
echo "zip:   $out_dir/HarmonyRecomp-macos-arm64.zip"
