#!/bin/bash
# Cross-compiles the runtime and game for iPadOS/iOS (arm64 devices).
#
# usage: tools/ios/build_ios.sh [build-type]   (default RelWithDebInfo)
#
# Environment:
#   DEVELOPER_DIR   Xcode to use (default /Applications/Xcode.app/Contents/Developer)
#   REXSDK_DIR      rexglue-sdk checkout (default ../rexglue-sdk next to this repo)
#   OPENSSL_SRC     OpenSSL source tree (default ../deps/src/openssl-*)
#   JOBS            parallel jobs (default 4)
set -euo pipefail

here=$(cd "$(dirname "$0")" && pwd)
game_root=$(cd "$here/../.." && pwd)
work_root=$(cd "$game_root/.." && pwd)
build_type=${1:-RelWithDebInfo}
jobs=${JOBS:-4}

export DEVELOPER_DIR=${DEVELOPER_DIR:-/Applications/Xcode.app/Contents/Developer}
xcrun --sdk iphoneos --show-sdk-path >/dev/null || {
  echo "No iphoneos SDK under $DEVELOPER_DIR; install Xcode with the iOS platform." >&2
  exit 1
}

rexsdk=${REXSDK_DIR:-$work_root/rexglue-sdk}
deployment_target=${IOS_DEPLOYMENT_TARGET:-17.0}
build_dir="$game_root/out/build/ios-arm64-$(echo "$build_type" | tr '[:upper:]' '[:lower:]')"
openssl_prefix="$work_root/deps/openssl-ios"

# OpenSSL (libcrypto only is linked; static, no apps or tests).
if [ ! -f "$openssl_prefix/lib/libcrypto.a" ]; then
  openssl_src=${OPENSSL_SRC:-$(ls -d "$work_root"/deps/src/openssl-*/ | head -1)}
  scratch=$(mktemp -d)
  rsync -a "$openssl_src/" "$scratch/openssl/"
  (
    cd "$scratch/openssl"
    CC="$(xcrun --sdk iphoneos -f clang)" \
      ./Configure ios64-xcrun no-shared no-tests no-apps no-docs no-dso \
        -mios-version-min="$deployment_target" --prefix="$openssl_prefix" --libdir=lib
    make -j"$jobs" build_libs
    make install_dev
  )
  rm -rf "$scratch"
fi

cmake -S "$game_root" -B "$build_dir" -G Ninja \
  -DCMAKE_SYSTEM_NAME=iOS \
  -DCMAKE_OSX_SYSROOT=iphoneos \
  -DCMAKE_OSX_ARCHITECTURES=arm64 \
  -DCMAKE_OSX_DEPLOYMENT_TARGET="$deployment_target" \
  -DCMAKE_BUILD_TYPE="$build_type" \
  -DREXSDK_DIR="$rexsdk" \
  -DREXGLUE_USE_PREGENERATED=ON \
  -DREXGLUE_ENABLE_TRACY=OFF \
  -DOPENSSL_ROOT_DIR="$openssl_prefix" \
  -DOPENSSL_USE_STATIC_LIBS=ON

cmake --build "$build_dir" --target harmonyrecomp --parallel "$jobs"
echo "Built $build_dir/harmonyrecomp"
