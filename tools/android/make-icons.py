#!/usr/bin/env python3
"""Writes launcher icon mipmaps from one square PNG into an Android res directory.

Legacy icons (ic_launcher.png) get the image as-is; the adaptive icon (Android 8+) puts it
inside the 72dp visible circle of the 108dp layer, on a black background, so launchers that
mask icons into circles or squircles don't cut the artwork.
"""
import os
import sys

from PIL import Image

DENSITIES = {"mdpi": 1.0, "hdpi": 1.5, "xhdpi": 2.0, "xxhdpi": 3.0, "xxxhdpi": 4.0}


def main(source, res):
    art = Image.open(source).convert("RGBA")
    for name, scale in DENSITIES.items():
        folder = os.path.join(res, "mipmap-" + name)
        os.makedirs(folder, exist_ok=True)
        legacy = round(48 * scale)
        art.resize((legacy, legacy), Image.LANCZOS).save(os.path.join(folder, "ic_launcher.png"))
        layer = round(108 * scale)
        inner = round(74 * scale)
        foreground = Image.new("RGBA", (layer, layer), (0, 0, 0, 0))
        offset = (layer - inner) // 2
        foreground.paste(art.resize((inner, inner), Image.LANCZOS), (offset, offset))
        foreground.save(os.path.join(folder, "ic_launcher_foreground.png"))
    adaptive = os.path.join(res, "mipmap-anydpi-v26")
    os.makedirs(adaptive, exist_ok=True)
    with open(os.path.join(adaptive, "ic_launcher.xml"), "w") as out:
        out.write('<?xml version="1.0" encoding="utf-8"?>\n'
                  '<adaptive-icon xmlns:android="http://schemas.android.com/apk/res/android">\n'
                  '    <background android:drawable="@android:color/black" />\n'
                  '    <foreground android:drawable="@mipmap/ic_launcher_foreground" />\n'
                  '</adaptive-icon>\n')


if __name__ == "__main__":
    main(sys.argv[1], sys.argv[2])
