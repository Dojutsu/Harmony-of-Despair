package net.dojutsu.harmony;

import android.net.Uri;
import android.os.Environment;
import android.provider.DocumentsContract;

import java.io.File;

/** First-run game file import, backed by libharmonyimport.so (android_import.cpp). */
final class GameFiles {
    static final int MISSING = 0;
    static final int BASE_ONLY = 1;
    static final int READY = 2;

    /** Where android_main.cpp tells the game to read its data from. */
    static final File GAME_ROOT = new File(Environment.getExternalStorageDirectory(), "HoD");
    static final File GAME_DATA = new File(GAME_ROOT, "game-data");

    private static boolean loaded;
    private static String loadError;

    private GameFiles() {}

    static synchronized boolean load() {
        if (loaded) return true;
        try {
            System.loadLibrary("harmonyimport");
            loaded = true;
        } catch (Throwable error) {
            loadError = error.toString();
        }
        return loaded;
    }

    static String loadError() { return loadError; }

    static int status() {
        if (!load()) return MISSING;
        return nativeStatus(GAME_DATA.getAbsolutePath());
    }

    /** Returns "OK:..." or "ERR:...". Runs for minutes; call off the UI thread. */
    static String importFrom(File source, File contentRoot) {
        if (!load()) return "ERR:The import part of the app did not load (" + loadError + ").";
        GAME_ROOT.mkdirs();
        return nativeImport(source.getAbsolutePath(), GAME_DATA.getAbsolutePath(),
                contentRoot.getAbsolutePath());
    }

    /**
     * Turns a folder picked with the system file picker into a plain path. The app reads it
     * directly through "All files access", which the native import needs.
     */
    static File folderFromTree(Uri tree) {
        if (tree == null) return null;
        String id;
        try {
            id = DocumentsContract.getTreeDocumentId(tree);
        } catch (IllegalArgumentException e) {
            return null;
        }
        int colon = id.indexOf(':');
        if (colon < 0) return null;
        String volume = id.substring(0, colon);
        String relative = id.substring(colon + 1);
        File base = "primary".equalsIgnoreCase(volume)
                ? Environment.getExternalStorageDirectory()
                : new File("/storage", volume);
        return relative.isEmpty() ? base : new File(base, relative);
    }

    private static native int nativeStatus(String root);
    private static native String nativeImport(String source, String destination, String contentRoot);
}
