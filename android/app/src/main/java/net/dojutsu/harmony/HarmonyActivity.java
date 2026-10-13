package net.dojutsu.harmony;

import android.content.ClipData;
import android.content.ClipboardManager;
import android.content.Intent;
import android.graphics.Color;
import android.graphics.Typeface;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.os.Handler;
import android.os.Looper;
import android.provider.Settings;
import android.util.TypedValue;
import android.view.Gravity;
import android.view.View;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;

import org.json.JSONObject;
import org.libsdl.app.SDLActivity;

import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.nio.charset.StandardCharsets;

/**
 * Harmony of Despair game activity. SDLActivity owns the surface, input and
 * audio; this subclass names the native libraries, hands the launcher's
 * flags to the game and, for online games, shows the invite code and party
 * size from the engine's online-status snapshot.
 */
public class HarmonyActivity extends SDLActivity {
    private final Handler handler = new Handler(Looper.getMainLooper());
    private TextView onlineOverlay;
    private String copiedCode;
    private final Runnable poll = new Runnable() {
        @Override public void run() {
            refreshOnlineOverlay();
            handler.postDelayed(this, 1000);
        }
    };

    @Override
    protected String[] getLibraries() {
        // Order matters: each library's dependencies must already be loaded.
        return new String[] {
            "c++_shared",
            "SDL3",
            "rexruntime",
            "main"
        };
    }

    @Override
    protected String[] getArguments() {
        Intent intent = getIntent();
        String[] args = intent != null ? intent.getStringArrayExtra(LauncherActivity.EXTRA_ARGS) : null;
        return args != null ? args : new String[0];
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R && !Environment.isExternalStorageManager()) {
            Toast.makeText(this, "Harmony needs 'All files access' to read the game data in /sdcard/HoD",
                    Toast.LENGTH_LONG).show();
            Intent intent = new Intent(Settings.ACTION_MANAGE_APP_ALL_FILES_ACCESS_PERMISSION,
                    Uri.parse("package:" + getPackageName()));
            startActivity(intent);
        }
        super.onCreate(savedInstanceState);

        Intent intent = getIntent();
        boolean online = intent != null && intent.getBooleanExtra(LauncherActivity.EXTRA_ONLINE, false);
        if (online && mLayout instanceof RelativeLayout) {
            onlineOverlay = new TextView(this);
            onlineOverlay.setTextColor(Color.WHITE);
            onlineOverlay.setBackgroundColor(Color.argb(120, 0, 0, 0));
            onlineOverlay.setTypeface(Typeface.MONOSPACE, Typeface.BOLD);
            onlineOverlay.setTextSize(TypedValue.COMPLEX_UNIT_SP, 13);
            int pad = Math.round(TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, 6, getResources().getDisplayMetrics()));
            onlineOverlay.setPadding(pad * 2, pad, pad * 2, pad);
            onlineOverlay.setGravity(Gravity.START);
            // Hidden until a lobby exists (hosting or joined); the title screen and single player stay clean.
            onlineOverlay.setVisibility(View.GONE);
            RelativeLayout.LayoutParams params = new RelativeLayout.LayoutParams(
                    RelativeLayout.LayoutParams.WRAP_CONTENT, RelativeLayout.LayoutParams.WRAP_CONTENT);
            // Lower left, clear of the menu titles and the HP/MP bars at the top.
            params.addRule(RelativeLayout.ALIGN_PARENT_BOTTOM);
            params.addRule(RelativeLayout.ALIGN_PARENT_START);
            // Keep clear of the rounded screen corners and the edge the game draws under.
            params.leftMargin = pad * 6;
            params.bottomMargin = pad * 7;
            mLayout.addView(onlineOverlay, params);
            handler.postDelayed(poll, 1000);
        }
    }

    @Override
    protected void onDestroy() {
        handler.removeCallbacks(poll);
        super.onDestroy();
    }

    private File filesRoot() {
        File external = getExternalFilesDir(null);
        return external != null ? external : getFilesDir();
    }

    private void refreshOnlineOverlay() {
        if (onlineOverlay == null) return;
        File dir = new File(filesRoot(), LauncherActivity.ONLINE_STATUS_DIR);
        File[] files = dir.listFiles();
        JSONObject newest = null;
        long newestTime = 0;
        if (files != null) {
            for (File file : files) {
                if (!file.getName().startsWith("online-status-") || !file.getName().endsWith(".json")) continue;
                if (newest != null && file.lastModified() < newestTime) continue;
                JSONObject parsed = readJson(file);
                if (parsed != null) {
                    newest = parsed;
                    newestTime = file.lastModified();
                }
            }
        }
        if (newest == null) {
            onlineOverlay.setVisibility(View.GONE);
            return;
        }
        String mode = newest.optString("mode", "offline");
        String code = newest.optString("invite_code", "");
        // Only the invite code is shown, and only while a lobby exists.
        if ("hosting".equals(mode) && code.length() == 6) {
            onlineOverlay.setText("Invite code  " + code);
            onlineOverlay.setVisibility(View.VISIBLE);
            if (!code.equals(copiedCode)) {
                copiedCode = code;
                ClipboardManager clipboard = (ClipboardManager) getSystemService(CLIPBOARD_SERVICE);
                if (clipboard != null) clipboard.setPrimaryClip(ClipData.newPlainText("Harmony invite code", code));
            }
        } else if ("hosting".equals(mode)) {
            onlineOverlay.setText("Getting invite code...");
            onlineOverlay.setVisibility(View.VISIBLE);
        } else if ("joined".equals(mode) && code.length() == 6) {
            onlineOverlay.setText("Invite code  " + code);
            onlineOverlay.setVisibility(View.VISIBLE);
        } else {
            onlineOverlay.setVisibility(View.GONE);
        }
    }

    private static JSONObject readJson(File file) {
        try (InputStream in = new FileInputStream(file)) {
            byte[] bytes = new byte[(int) Math.min(file.length(), 64 * 1024)];
            int total = 0;
            while (total < bytes.length) {
                int read = in.read(bytes, total, bytes.length - total);
                if (read <= 0) break;
                total += read;
            }
            return new JSONObject(new String(bytes, 0, total, StandardCharsets.UTF_8));
        } catch (Exception e) {
            return null;
        }
    }
}
