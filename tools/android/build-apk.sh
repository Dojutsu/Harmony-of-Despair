#!/usr/bin/env bash
# Packages the Android build of HarmonyRecomp into an installable APK without
# Gradle: javac + d8 for the Java side, aapt2 for resources, apksigner for the
# signature. Inputs:
#   $1  build directory of the Android CMake build (holds android-libs/arm64-v8a)
#   $2  output APK path
# Environment:
#   ANDROID_SDK_ROOT   Android SDK with build-tools and platforms (default /opt/android-sdk)
#   SDL_ANDROID_JAVA   SDL3's Java sources (android-project/app/src/main/java)
#   HARMONY_KEYSTORE   signing keystore (created with the "android" password if missing)
#   HARMONY_RELEASE    set to 1 for a public build: not debuggable, and signed with the
#                      keystore whose password is read from HARMONY_KEYSTORE_PASS_FILE
#                      (alias from HARMONY_KEY_ALIAS, default "harmony")
#   HARMONY_ICON       optional square PNG used as the launcher icon (kept out of the repo,
#                      since the artwork is third-party); needs python3 with Pillow
set -euo pipefail

BUILD_DIR=${1:?build dir}
OUT_APK=${2:?output apk}
SDK=${ANDROID_SDK_ROOT:-/opt/android-sdk}
BT=$(ls -d "$SDK"/build-tools/* | sort -V | tail -1)
PLATFORM=$(ls -d "$SDK"/platforms/android-* | sort -V | tail -1)
ANDROID_JAR="$PLATFORM/android.jar"
HERE=$(cd "$(dirname "$0")" && pwd)
APP="$HERE/../../android/app/src/main"
SDL_JAVA=${SDL_ANDROID_JAVA:?path to SDL3 android-project/app/src/main/java}
KEYSTORE=${HARMONY_KEYSTORE:-$HOME/.harmony-android-debug.keystore}
LIBS="$BUILD_DIR/android-libs/arm64-v8a"

WORK=$(mktemp -d)
trap 'rm -rf "$WORK"' EXIT

echo "[1/5] Java"
mkdir -p "$WORK/classes"
find "$SDL_JAVA" "$APP/java" -name '*.java' > "$WORK/sources.txt"
javac -source 1.8 -target 1.8 -nowarn -Xlint:-options -bootclasspath "$ANDROID_JAR" -classpath "$ANDROID_JAR" \
    -d "$WORK/classes" @"$WORK/sources.txt"
"$BT/d8" --release --min-api 29 --lib "$ANDROID_JAR" --output "$WORK" \
    $(find "$WORK/classes" -name '*.class')

echo "[2/5] Resources"
mkdir -p "$WORK/res-compiled"
RES="$APP/res"
if [ -n "${HARMONY_ICON:-}" ]; then
    RES="$WORK/res"
    cp -r "$APP/res" "$RES"
    python3 "$HERE/make-icons.py" "$HARMONY_ICON" "$RES"
fi
"$BT/aapt2" compile --dir "$RES" -o "$WORK/res.zip"
MANIFEST="$APP/AndroidManifest.xml"
if [ "${HARMONY_RELEASE:-}" = "1" ]; then
    MANIFEST="$WORK/AndroidManifest.xml"
    sed 's/android:debuggable="true"/android:debuggable="false"/' "$APP/AndroidManifest.xml" > "$MANIFEST"
fi
"$BT/aapt2" link -o "$WORK/base.apk" -I "$ANDROID_JAR" --manifest "$MANIFEST" \
    --min-sdk-version 29 --target-sdk-version 33 "$WORK/res.zip"

echo "[3/5] Native libraries"
mkdir -p "$WORK/stage/lib/arm64-v8a"
NDK_DIR="$SDK/ndk/$(ls "$SDK/ndk" | sort -V | tail -1)"
TOOLCHAIN="$NDK_DIR/toolchains/llvm/prebuilt/linux-x86_64"
cp "$LIBS"/*.so "$WORK/stage/lib/arm64-v8a/"
cp "$TOOLCHAIN/sysroot/usr/lib/aarch64-linux-android/libc++_shared.so" "$WORK/stage/lib/arm64-v8a/"
# The build keeps debug info for symbolizing crashes; the APK ships stripped
# copies so it stays a reasonable size.
if [ -z "${HARMONY_KEEP_SYMBOLS:-}" ]; then
    "$TOOLCHAIN/bin/llvm-strip" --strip-unneeded "$WORK/stage/lib/arm64-v8a"/*.so
fi
du -sh "$WORK/stage/lib/arm64-v8a" | cut -f1 | sed 's/^/  native libraries: /'
cp "$WORK/classes.dex" "$WORK/stage/"
cp "$WORK/base.apk" "$WORK/unaligned.apk"
(cd "$WORK/stage" && zip -q -r -X "$WORK/unaligned.apk" classes.dex lib)

echo "[4/5] Align"
"$BT/zipalign" -p -f 4 "$WORK/unaligned.apk" "$WORK/aligned.apk"

echo "[5/5] Sign"
if [ "${HARMONY_RELEASE:-}" = "1" ]; then
    PASS_FILE=${HARMONY_KEYSTORE_PASS_FILE:?release builds need HARMONY_KEYSTORE_PASS_FILE}
    [ -f "$KEYSTORE" ] || { echo "release keystore $KEYSTORE is missing" >&2; exit 1; }
    "$BT/apksigner" sign --ks "$KEYSTORE" --ks-pass "file:$PASS_FILE" \
        --ks-key-alias "${HARMONY_KEY_ALIAS:-harmony}" --out "$OUT_APK" "$WORK/aligned.apk"
    "$BT/apksigner" verify "$OUT_APK"
    ls -la "$OUT_APK"
    exit 0
fi
if [ ! -f "$KEYSTORE" ]; then
    keytool -genkeypair -v -keystore "$KEYSTORE" -storepass android -keypass android \
        -alias harmony -keyalg RSA -keysize 2048 -validity 10000 \
        -dname "CN=Harmony Android Debug, O=Harmony, C=US" >/dev/null 2>&1
fi
"$BT/apksigner" sign --ks "$KEYSTORE" --ks-pass pass:android --key-pass pass:android \
    --ks-key-alias harmony --out "$OUT_APK" "$WORK/aligned.apk"
"$BT/apksigner" verify "$OUT_APK"
ls -la "$OUT_APK"
