package net.dojutsu.harmony;

import android.app.Activity;
import android.content.ClipData;
import android.content.ClipboardManager;
import android.content.Intent;
import android.content.SharedPreferences;
import android.graphics.Color;
import android.graphics.Typeface;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.provider.Settings;
import android.text.InputFilter;
import android.text.InputType;
import android.util.TypedValue;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.ScrollView;
import android.widget.TextView;
import android.widget.Toast;

import java.io.File;
import java.security.SecureRandom;
import java.util.ArrayList;
import java.util.Locale;

/**
 * Start screen: player name plus the choice between playing offline, hosting
 * an online game (the invite code is shown in-game) or joining a friend's game
 * by invite code. Mirrors the flags the PC launcher (Setup-Harmony.ps1) passes.
 */
public class LauncherActivity extends Activity {
    public static final String EXTRA_ARGS = "net.dojutsu.harmony.ARGS";
    public static final String EXTRA_ONLINE = "net.dojutsu.harmony.ONLINE";
    public static final String ONLINE_STATUS_DIR = "online-status";

    private static final String PREFS = "harmony";
    private static final String PREF_NAME = "player_name";
    private static final String PREF_XUID = "player_xuid";
    private static final String DEFAULT_XUID_HEX = "B13EBABEBABEBABE";  // the engine's built-in player id
    private static final String DIRECTORY_URL = "https://hod.dojutsu.net";
    private static final String CODE_ALPHABET = "ABCDEFGHJKMNPQRSTUVWXYZ23456789";

    private EditText nameField;
    private EditText codeField;
    private TextView storageNote;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        SharedPreferences prefs = getSharedPreferences(PREFS, MODE_PRIVATE);

        LinearLayout column = new LinearLayout(this);
        column.setOrientation(LinearLayout.VERTICAL);
        int pad = dp(24);
        column.setPadding(pad, pad, pad, pad);
        column.setBackgroundColor(Color.rgb(16, 12, 24));

        TextView title = new TextView(this);
        title.setText("Harmony of Despair");
        title.setTextColor(Color.WHITE);
        title.setTypeface(Typeface.DEFAULT_BOLD);
        title.setTextSize(TypedValue.COMPLEX_UNIT_SP, 28);
        column.addView(title);

        TextView nameLabel = label("Player name");
        column.addView(nameLabel);
        nameField = new EditText(this);
        nameField.setSingleLine(true);
        nameField.setInputType(InputType.TYPE_CLASS_TEXT | InputType.TYPE_TEXT_FLAG_NO_SUGGESTIONS);
        nameField.setFilters(new InputFilter[] {new InputFilter.LengthFilter(15)});
        nameField.setText(prefs.getString(PREF_NAME, "Thor"));
        nameField.setTextColor(Color.WHITE);
        nameField.setTextSize(TypedValue.COMPLEX_UNIT_SP, 20);
        column.addView(nameField);

        Button offline = button("Play offline");
        offline.setOnClickListener(new View.OnClickListener() {
            @Override public void onClick(View v) { launch(null, false); }
        });
        column.addView(offline);

        Button host = button("Host an online game");
        host.setOnClickListener(new View.OnClickListener() {
            @Override public void onClick(View v) { launch(null, true); }
        });
        column.addView(host);

        column.addView(label("Friend's invite code"));
        LinearLayout codeRow = new LinearLayout(this);
        codeRow.setOrientation(LinearLayout.HORIZONTAL);
        codeField = new EditText(this);
        codeField.setSingleLine(true);
        codeField.setHint("6 letters");
        codeField.setHintTextColor(Color.GRAY);
        codeField.setInputType(InputType.TYPE_CLASS_TEXT | InputType.TYPE_TEXT_FLAG_CAP_CHARACTERS
                | InputType.TYPE_TEXT_FLAG_NO_SUGGESTIONS);
        codeField.setFilters(new InputFilter[] {new InputFilter.LengthFilter(6), new InputFilter.AllCaps()});
        codeField.setTextColor(Color.WHITE);
        codeField.setTextSize(TypedValue.COMPLEX_UNIT_SP, 24);
        codeField.setTypeface(Typeface.MONOSPACE);
        LinearLayout.LayoutParams grow = new LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT, 1f);
        codeRow.addView(codeField, grow);
        Button paste = button("Paste");
        paste.setOnClickListener(new View.OnClickListener() {
            @Override public void onClick(View v) {
                ClipboardManager clipboard = (ClipboardManager) getSystemService(CLIPBOARD_SERVICE);
                if (clipboard != null && clipboard.hasPrimaryClip() && clipboard.getPrimaryClip().getItemCount() > 0) {
                    CharSequence text = clipboard.getPrimaryClip().getItemAt(0).coerceToText(LauncherActivity.this);
                    if (text != null) codeField.setText(normalizeCode(text.toString()));
                }
            }
        });
        codeRow.addView(paste);
        column.addView(codeRow);

        Button join = button("Join with this code");
        join.setOnClickListener(new View.OnClickListener() {
            @Override public void onClick(View v) {
                String code = normalizeCode(codeField.getText().toString());
                if (code.length() != 6) {
                    Toast.makeText(LauncherActivity.this, "Type the six-letter code from your friend", Toast.LENGTH_LONG).show();
                    return;
                }
                launch(code, true);
            }
        });
        column.addView(join);

        storageNote = label("");
        storageNote.setTextColor(Color.rgb(255, 200, 120));
        column.addView(storageNote);
        Button storage = button("Allow access to the game files");
        storage.setOnClickListener(new View.OnClickListener() {
            @Override public void onClick(View v) {
                Intent intent = new Intent(Settings.ACTION_MANAGE_APP_ALL_FILES_ACCESS_PERMISSION,
                        Uri.parse("package:" + getPackageName()));
                startActivity(intent);
            }
        });
        column.addView(storage);

        ScrollView scroll = new ScrollView(this);
        scroll.addView(column);
        setContentView(scroll);
    }

    @Override
    protected void onResume() {
        super.onResume();
        boolean ok = Build.VERSION.SDK_INT < Build.VERSION_CODES.R || Environment.isExternalStorageManager();
        storageNote.setText(ok ? "" : "The game needs 'All files access' to read its data in /sdcard/HoD.");
    }

    private void launch(String inviteCode, boolean online) {
        SharedPreferences prefs = getSharedPreferences(PREFS, MODE_PRIVATE);
        String name = nameField.getText().toString().trim();
        if (name.isEmpty() || !isPrintableAscii(name)) {
            Toast.makeText(this, "Player name: 1 to 15 plain letters or numbers", Toast.LENGTH_LONG).show();
            return;
        }
        String xuid = ensureXuid(prefs);
        prefs.edit().putString(PREF_NAME, name).apply();

        ArrayList<String> args = new ArrayList<>();
        args.add("--user_name=" + name);
        args.add("--user_xuid=" + xuid);
        if (online) {
            args.add("--lan_online=true");
            args.add("--lan_discovery_port=30741");
            args.add("--lan_gameplay_port=30742");
            args.add("--session_directory_url=" + DIRECTORY_URL);
            args.add("--session_directory_candidate_type=public");
            File statusDir = new File(filesRoot(), ONLINE_STATUS_DIR);
            statusDir.mkdirs();
            args.add("--online_status_directory=" + statusDir.getAbsolutePath());
            if (inviteCode != null) args.add("--session_directory_invite_code=" + inviteCode);
        }

        Intent intent = new Intent(this, HarmonyActivity.class);
        intent.putExtra(EXTRA_ARGS, args.toArray(new String[0]));
        intent.putExtra(EXTRA_ONLINE, online);
        startActivity(intent);
        finish();
    }

    /** Returns the persistent player id, creating it (and moving the saves made under the engine default) once. */
    private String ensureXuid(SharedPreferences prefs) {
        String existing = prefs.getString(PREF_XUID, null);
        if (existing != null) return existing;
        SecureRandom random = new SecureRandom();
        long value;
        do {
            value = random.nextLong() & ~(3L << 54);  // bits 54 and 55 clear, as the PC launcher requires
        } while (value == 0);
        String decimal = Long.toUnsignedString(value);
        String hex = String.format(Locale.ROOT, "%016X", value);
        // Saves live under <user root>/<player id in hex>/...; carry over anything saved under the default id.
        File userRoot = new File(filesRoot(), "user");
        File oldDir = new File(userRoot, DEFAULT_XUID_HEX);
        File newDir = new File(userRoot, hex);
        if (oldDir.isDirectory() && !newDir.exists()) oldDir.renameTo(newDir);
        prefs.edit().putString(PREF_XUID, decimal).apply();
        return decimal;
    }

    /** The directory the native side uses for config, saves and status files (see android_main.cpp). */
    private File filesRoot() {
        File external = getExternalFilesDir(null);
        return external != null ? external : getFilesDir();
    }

    private static String normalizeCode(String text) {
        StringBuilder out = new StringBuilder();
        for (char ch : text.toUpperCase(Locale.ROOT).toCharArray()) {
            if (CODE_ALPHABET.indexOf(ch) >= 0 && out.length() < 6) out.append(ch);
        }
        return out.toString();
    }

    private static boolean isPrintableAscii(String text) {
        for (char ch : text.toCharArray()) {
            if (ch < 0x20 || ch > 0x7e) return false;
        }
        return true;
    }

    private TextView label(String text) {
        TextView view = new TextView(this);
        view.setText(text);
        view.setTextColor(Color.LTGRAY);
        view.setTextSize(TypedValue.COMPLEX_UNIT_SP, 16);
        view.setPadding(0, dp(16), 0, dp(4));
        return view;
    }

    private Button button(String text) {
        Button view = new Button(this);
        view.setText(text);
        view.setAllCaps(false);
        view.setTextSize(TypedValue.COMPLEX_UNIT_SP, 20);
        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(
                ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT);
        params.topMargin = dp(10);
        view.setLayoutParams(params);
        view.setGravity(Gravity.CENTER);
        return view;
    }

    private int dp(int value) {
        return Math.round(TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, value, getResources().getDisplayMetrics()));
    }
}
