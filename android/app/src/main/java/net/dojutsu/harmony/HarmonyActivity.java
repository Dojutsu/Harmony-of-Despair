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
        CrashReport.installJavaHandler(this);
        super.onCreate(savedInstanceState);

        Intent intent = getIntent();
        boolean online = intent != null && intent.getBooleanExtra(LauncherActivity.EXTRA_ONLINE, false);
        if (online && mLayout instanceof RelativeLayout) {
            onlineOverlay = new TextView(this);
            onlineOverlay.setTextColor(Color.WHITE);
            onlineOverlay.setBackgroundColor(Color.argb(120, 0, 0, 0));
            onlineOverlay.setTypeface(Typeface.MONOSPACE, Typeface.BOLD);
            onlineOverlay.setTextSize(TypedValue.COMPLEX_UNIT_SP, 11);
            int pad = Math.round(TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, 6, getResources().getDisplayMetrics()));
            onlineOverlay.setPadding(pad, pad / 2, pad, pad / 2);
            onlineOverlay.setGravity(Gravity.CENTER_HORIZONTAL);
            // Hidden until a lobby exists (hosting or joined); the title screen and single player stay clean.
            onlineOverlay.setVisibility(View.GONE);
            RelativeLayout.LayoutParams params = new RelativeLayout.LayoutParams(
                    RelativeLayout.LayoutParams.WRAP_CONTENT, RelativeLayout.LayoutParams.WRAP_CONTENT);
            // On the open book of the team screen, just right of "Invite to Team" / "Finalize Team",
            // where no player card or menu text sits. Placed as a fraction of the screen so it
            // follows the game picture at any resolution.
            params.addRule(RelativeLayout.ALIGN_PARENT_TOP);
            params.addRule(RelativeLayout.ALIGN_PARENT_START);
            mLayout.addView(onlineOverlay, params);
            mLayout.addOnLayoutChangeListener(new View.OnLayoutChangeListener() {
                @Override public void onLayoutChange(View v, int l, int t, int r, int b, int ol, int ot, int or, int ob) {
                    if (r - l == or - ol && b - t == ob - ot) return;
                    RelativeLayout.LayoutParams p = (RelativeLayout.LayoutParams) onlineOverlay.getLayoutParams();
                    p.leftMargin = Math.round((r - l) * 0.505f);
                    p.topMargin = Math.round((b - t) * 0.695f);
                    onlineOverlay.setLayoutParams(p);
                }
            });
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
        String state = newest.optString("session_state", "lobby");
        int players = newest.optInt("player_count", 0);
        int max = newest.optInt("max_players", 0);
        // Show the code only while the hosted lobby is still taking players. Finalizing the team
        // closes the free seats (max_players drops to the team size), which hides it; searching
        // for more players reopens them and it comes back.
        boolean recruiting = "hosting".equals(mode) && "lobby".equals(state) && players < max;
        if (recruiting && code.length() == 6) {
            onlineOverlay.setText("Invite code\n" + code);
            onlineOverlay.setVisibility(View.VISIBLE);
            if (!code.equals(copiedCode)) {
                copiedCode = code;
                ClipboardManager clipboard = (ClipboardManager) getSystemService(CLIPBOARD_SERVICE);
                if (clipboard != null) clipboard.setPrimaryClip(ClipData.newPlainText("Harmony invite code", code));
            }
        } else if (recruiting) {
            onlineOverlay.setText("Invite code\n...");
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
