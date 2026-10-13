package net.dojutsu.harmony;

import android.app.ActivityManager;
import android.app.ApplicationExitInfo;
import android.content.ContentResolver;
import android.content.ContentValues;
import android.content.Context;
import android.content.SharedPreferences;
import android.content.pm.PackageInfo;
import android.net.Uri;
import android.os.Build;
import android.provider.MediaStore;
import android.util.Base64;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.RandomAccessFile;
import java.io.StringWriter;
import java.nio.charset.StandardCharsets;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;
import java.util.Locale;
import java.util.zip.GZIPOutputStream;

/**
 * Crash reports players can send back without a PC: when the game closed
 * unexpectedly, a text file with the device details, Android's record of the
 * crash and the end of the game log is saved to the Downloads folder.
 */
final class CrashReport {
    private static final String PREFS = "harmony";
    private static final String PREF_SEEN = "crash_seen_time";
    private static final String JAVA_CRASH_FILE = "last-java-crash.txt";
    private static final String GAME_LOG = "/sdcard/HoD/android-logs/harmonyrecomp.log";
    private static final int LOG_TAIL_BYTES = 96 * 1024;

    private CrashReport() {}

    /** Records Java crashes (the start screen or the game window) before the process dies. */
    static void installJavaHandler(final Context context) {
        final Context app = context.getApplicationContext();
        final Thread.UncaughtExceptionHandler previous = Thread.getDefaultUncaughtExceptionHandler();
        if (previous != null && previous.getClass().getName().startsWith(CrashReport.class.getName())) return;
        Thread.setDefaultUncaughtExceptionHandler(new Thread.UncaughtExceptionHandler() {
            @Override public void uncaughtException(Thread thread, Throwable error) {
                try {
                    StringWriter text = new StringWriter();
                    PrintWriter out = new PrintWriter(text);
                    out.println("Thread: " + thread.getName());
                    error.printStackTrace(out);
                    out.flush();
                    try (FileOutputStream file = new FileOutputStream(new File(app.getFilesDir(), JAVA_CRASH_FILE))) {
                        file.write(text.toString().getBytes(StandardCharsets.UTF_8));
                    }
                    // The start screen may crash every time it opens, so save the report right away too.
                    save(app, build(app, null, text.toString()));
                } catch (Throwable ignored) {
                }
                if (previous != null) previous.uncaughtException(thread, error);
            }
        });
    }

    /**
     * Saves a report if Android recorded a crash since the last check. Returns
     * the file name in Downloads, or null when there was nothing new.
     */
    static String saveIfCrashedLastTime(Context context) {
        if (Build.VERSION.SDK_INT < Build.VERSION_CODES.R) return null;
        SharedPreferences prefs = context.getSharedPreferences(PREFS, Context.MODE_PRIVATE);
        long seen = prefs.getLong(PREF_SEEN, 0);
        try {
            ActivityManager am = (ActivityManager) context.getSystemService(Context.ACTIVITY_SERVICE);
            List<ApplicationExitInfo> exits = am.getHistoricalProcessExitReasons(context.getPackageName(), 0, 8);
            ApplicationExitInfo crash = null;
            long newest = seen;
            for (ApplicationExitInfo info : exits) {
                if (info.getTimestamp() <= seen) continue;
                newest = Math.max(newest, info.getTimestamp());
                if (isProblem(info) && (crash == null || info.getTimestamp() > crash.getTimestamp())) crash = info;
            }
            prefs.edit().putLong(PREF_SEEN, newest).apply();
            if (crash == null) return null;
            File javaCrashFile = new File(context.getFilesDir(), JAVA_CRASH_FILE);
            String javaCrash = readSmallFile(javaCrashFile);
            String name = save(context, build(context, crash, javaCrash, exits));
            javaCrashFile.delete();
            return name;
        } catch (Throwable error) {
            return null;
        }
    }

    /**
     * Anything but a normal quit, the player closing the app, or an update counts:
     * crashes, but also Android stopping the game for memory or the game giving up.
     */
    private static boolean isProblem(ApplicationExitInfo info) {
        switch (info.getReason()) {
            case ApplicationExitInfo.REASON_USER_REQUESTED:
            case ApplicationExitInfo.REASON_USER_STOPPED:
            case ApplicationExitInfo.REASON_PACKAGE_UPDATED:
            case ApplicationExitInfo.REASON_PACKAGE_STATE_CHANGE:
            case ApplicationExitInfo.REASON_PERMISSION_CHANGE:
                return false;
            case ApplicationExitInfo.REASON_EXIT_SELF:
                return info.getStatus() != 0;
            default:
                return true;
        }
    }

    /** The "Save a problem report" button: always writes a report, with whatever Android recorded. */
    static String saveNow(Context context) {
        List<ApplicationExitInfo> exits = null;
        ApplicationExitInfo latest = null;
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
            try {
                ActivityManager am = (ActivityManager) context.getSystemService(Context.ACTIVITY_SERVICE);
                exits = am.getHistoricalProcessExitReasons(context.getPackageName(), 0, 8);
                for (ApplicationExitInfo info : exits) {
                    if (isProblem(info) && (latest == null || info.getTimestamp() > latest.getTimestamp())) latest = info;
                }
            } catch (Throwable ignored) {
            }
        }
        return save(context, build(context, latest, readSmallFile(new File(context.getFilesDir(), JAVA_CRASH_FILE)), exits));
    }

    private static String build(Context context, ApplicationExitInfo exit, String javaCrash) {
        return build(context, exit, javaCrash, null);
    }

    private static String build(Context context, ApplicationExitInfo exit, String javaCrash,
            List<ApplicationExitInfo> recent) {
        StringBuilder out = new StringBuilder();
        out.append("Harmony of Despair crash report\n");
        out.append("Saved: ").append(new Date()).append('\n');
        try {
            PackageInfo pkg = context.getPackageManager().getPackageInfo(context.getPackageName(), 0);
            out.append("App version: ").append(pkg.versionName).append('\n');
        } catch (Throwable ignored) {
        }
        out.append("Device: ").append(Build.MANUFACTURER).append(' ').append(Build.MODEL)
                .append(" (").append(Build.DEVICE).append(")\n");
        out.append("Android: ").append(Build.VERSION.RELEASE).append(" (API ").append(Build.VERSION.SDK_INT).append(")\n");
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.S) {
            out.append("Chip: ").append(Build.SOC_MANUFACTURER).append(' ').append(Build.SOC_MODEL).append('\n');
        }
        out.append("Hardware: ").append(Build.HARDWARE).append('\n');
        if (exit != null && Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
            out.append("\n== Android exit record ==\n");
            out.append("Time: ").append(new Date(exit.getTimestamp())).append('\n');
            out.append("Reason: ").append(exit.getReason()).append(" status: ").append(exit.getStatus())
                    .append(" importance: ").append(exit.getImportance()).append('\n');
            out.append("Description: ").append(exit.getDescription()).append('\n');
            out.append("Memory (PSS/RSS kB): ").append(exit.getPss()).append(" / ").append(exit.getRss()).append('\n');
            try (InputStream trace = exit.getTraceInputStream()) {
                if (trace != null) {
                    ByteArrayOutputStream packed = new ByteArrayOutputStream();
                    try (GZIPOutputStream gz = new GZIPOutputStream(packed)) {
                        byte[] buffer = new byte[16384];
                        int n;
                        while ((n = trace.read(buffer)) > 0) gz.write(buffer, 0, n);
                    }
                    out.append("\n== Android trace (gzip, base64) ==\n");
                    out.append(Base64.encodeToString(packed.toByteArray(), Base64.DEFAULT)).append('\n');
                }
            } catch (Throwable error) {
                out.append("Trace unavailable: ").append(error).append('\n');
            }
        }
        if (recent != null && Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
            out.append("\n== Recent exits (newest first) ==\n");
            for (ApplicationExitInfo info : recent) {
                out.append(new Date(info.getTimestamp())).append("  reason ").append(info.getReason())
                        .append("  status ").append(info.getStatus()).append("  importance ").append(info.getImportance())
                        .append("  pss/rss kB ").append(info.getPss()).append('/').append(info.getRss())
                        .append("  ").append(info.getDescription()).append('\n');
            }
        }
        ActivityManager.MemoryInfo memory = new ActivityManager.MemoryInfo();
        try {
            ((ActivityManager) context.getSystemService(Context.ACTIVITY_SERVICE)).getMemoryInfo(memory);
            out.append("\nPhone memory: total ").append(memory.totalMem / (1024 * 1024)).append(" MB, free ")
                    .append(memory.availMem / (1024 * 1024)).append(" MB\n");
        } catch (Throwable ignored) {
        }
        if (javaCrash != null && !javaCrash.isEmpty()) {
            out.append("\n== Last Java crash ==\n").append(javaCrash).append('\n');
        }
        out.append("\n== End of game log ==\n").append(logTail()).append('\n');
        return out.toString();
    }

    private static String logTail() {
        File log = new File(GAME_LOG);
        if (!log.isFile()) return "(no game log)";
        try (RandomAccessFile file = new RandomAccessFile(log, "r")) {
            long start = Math.max(0, file.length() - LOG_TAIL_BYTES);
            file.seek(start);
            byte[] data = new byte[(int) (file.length() - start)];
            file.readFully(data);
            return new String(data, StandardCharsets.UTF_8);
        } catch (Throwable error) {
            return "(game log unreadable: " + error + ")";
        }
    }

    private static String readSmallFile(File file) {
        if (!file.isFile() || file.length() > 256 * 1024) return null;
        try (FileInputStream in = new FileInputStream(file)) {
            byte[] data = new byte[(int) file.length()];
            int off = 0;
            while (off < data.length) {
                int n = in.read(data, off, data.length - off);
                if (n < 0) break;
                off += n;
            }
            return new String(data, 0, off, StandardCharsets.UTF_8);
        } catch (Throwable error) {
            return null;
        }
    }

    /** Writes the report to Downloads through MediaStore, which needs no storage permission. */
    private static String save(Context context, String report) {
        String name = "Harmony-crash-report-"
                + new SimpleDateFormat("yyyyMMdd-HHmmss", Locale.ROOT).format(new Date()) + ".txt";
        try {
            ContentResolver resolver = context.getContentResolver();
            ContentValues values = new ContentValues();
            values.put(MediaStore.MediaColumns.DISPLAY_NAME, name);
            values.put(MediaStore.MediaColumns.MIME_TYPE, "text/plain");
            values.put(MediaStore.MediaColumns.RELATIVE_PATH, "Download/");
            Uri uri = resolver.insert(MediaStore.Downloads.EXTERNAL_CONTENT_URI, values);
            if (uri == null) return null;
            try (OutputStream out = resolver.openOutputStream(uri)) {
                if (out == null) return null;
                out.write(report.getBytes(StandardCharsets.UTF_8));
            }
            return name;
        } catch (Throwable error) {
            return null;
        }
    }
}
