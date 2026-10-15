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
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.ScrollView;
import android.widget.TextView;
import android.widget.Toast;

import java.io.File;
import java.security.SecureRandom;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;

/**
 * Start screen: player name plus the choice between playing offline, hosting
 * an online game (the invite code is shown in-game) or joining a friend's game
 * by invite code. Mirrors the flags the PC launcher (Setup-Harmony.ps1) passes.
 */
public class LauncherActivity extends Activity {
    public static final String EXTRA_ARGS = "net.dojutsu.harmony.ARGS";
    public static final String EXTRA_ONLINE = "net.dojutsu.harmony.ONLINE";
    public static final String EXTRA_HAPTICS = "net.dojutsu.harmony.HAPTICS";
    public static final String ONLINE_STATUS_DIR = "online-status";

    private static final String PREFS = "harmony";
    private static final String PREF_NAME = "player_name";
    private static final String PREF_XUID = "player_xuid";
    private static final String PREF_HAPTICS = "touch_haptics";
    private static final String DEFAULT_XUID_HEX = "B13EBABEBABEBABE";  // the engine's built-in player id
    private static final String DIRECTORY_URL = "https://hod.dojutsu.net";
    private static final String CODE_ALPHABET = "ABCDEFGHJKMNPQRSTUVWXYZ23456789";

    private static final int PICK_GAME_FILES = 41;
    private static final String PICK_NOTE = "Pick the folder that holds your own Harmony of Despair Xbox 360 files: "
            + "the base game, title update 2 and any extra content. They are copied into the game once.";
    private int setupState = -1;

    private EditText nameField;
    private EditText codeField;
    private CheckBox hapticsBox;
    private LinearLayout setupPanel;
    private TextView setupNote;
    private Button pickButton;
    private final List<View> playControls = new ArrayList<>();
    private boolean importing;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        CrashReport.installJavaHandler(this);
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

        String crashReport = CrashReport.saveIfCrashedLastTime(this);
        if (crashReport != null) {
            TextView crashNote = label("The game closed unexpectedly last time. A crash report was saved in your "
                    + "Downloads folder as " + crashReport + ". Please send that file to whoever gave you the game.");
            crashNote.setTextColor(Color.rgb(255, 196, 64));
            column.addView(crashNote);
        }

        // First-run setup, shown only while no game files are installed.
        setupPanel = new LinearLayout(this);
        setupPanel.setOrientation(LinearLayout.VERTICAL);
        TextView setupTitle = label("First-time setup");
        setupTitle.setTextColor(Color.WHITE);
        setupTitle.setTypeface(Typeface.DEFAULT_BOLD);
        setupPanel.addView(setupTitle);
        setupNote = label(PICK_NOTE);
        setupNote.setPadding(0, dp(4), 0, dp(4));
        setupPanel.addView(setupNote);
        pickButton = button("Pick your game files");
        pickButton.setOnClickListener(new View.OnClickListener() {
            @Override public void onClick(View v) { pickGameFiles(); }
        });
        setupPanel.addView(pickButton);
        column.addView(setupPanel);

        TextView nameLabel = label("Player name");
        column.addView(nameLabel);
        nameField = new EditText(this);
        nameField.setSingleLine(true);
        nameField.setInputType(InputType.TYPE_CLASS_TEXT | InputType.TYPE_TEXT_FLAG_NO_SUGGESTIONS);
        nameField.setFilters(new InputFilter[] {new InputFilter.LengthFilter(15)});
        nameField.setText(prefs.getString(PREF_NAME, "Thor"));
        nameField.setTextColor(Color.WHITE);
        nameField.setTextSize(TypedValue.COMPLEX_UNIT_SP, 20);
        styleBox(nameField);
        column.addView(nameField);

        // One Play button, like the PC launcher: the game always starts online-capable and the player
        // picks single player or an online game in the game's own menus. Hosting shows the invite code.
        Button play = button("Play");
        play.setOnClickListener(new View.OnClickListener() {
            @Override public void onClick(View v) { launch(null, true); }
        });
        column.addView(play);
        playControls.add(play);

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
        styleBox(codeField);
        codeField.setMinWidth(dp(200));
        LinearLayout.LayoutParams grow = new LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT, 1f);
        grow.gravity = Gravity.CENTER_VERTICAL;
        codeRow.addView(codeField, grow);
        Button paste = button("Paste");
        // button() sizes for the vertical column (full width); in this row that would push the code box
        // down to zero width, so size the Paste button to its text and let the code box take the rest.
        LinearLayout.LayoutParams pasteParams = new LinearLayout.LayoutParams(
                ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT);
        pasteParams.leftMargin = dp(12);
        pasteParams.gravity = Gravity.CENTER_VERTICAL;
        paste.setLayoutParams(pasteParams);
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
        playControls.add(join);

        // Only matters on phones that use the on-screen buttons.
        hapticsBox = new CheckBox(this);
        hapticsBox.setText("Vibrate when touch buttons are pressed");
        hapticsBox.setTextColor(Color.LTGRAY);
        hapticsBox.setTextSize(TypedValue.COMPLEX_UNIT_SP, 16);
        hapticsBox.setChecked(prefs.getBoolean(PREF_HAPTICS, true));
        hapticsBox.setPadding(dp(8), dp(12), 0, dp(12));
        column.addView(hapticsBox);

        // For players whose game closes in a way Android doesn't flag as a crash.
        TextView report = label("Game closing by itself? Tap here to save a problem report to Downloads.");
        report.setTextColor(Color.GRAY);
        report.setTextSize(TypedValue.COMPLEX_UNIT_SP, 13);
        report.setPadding(0, dp(28), 0, dp(4));
        report.setOnClickListener(new View.OnClickListener() {
            @Override public void onClick(View v) {
                String name = CrashReport.saveNow(LauncherActivity.this);
                Toast.makeText(LauncherActivity.this, name != null
                        ? "Saved " + name + " in Downloads. Please send it to whoever gave you the game."
                        : "Couldn't save the report", Toast.LENGTH_LONG).show();
            }
        });
        column.addView(report);

        ScrollView scroll = new ScrollView(this);
        scroll.addView(column);
        setContentView(scroll);
    }

    @Override
    protected void onResume() {
        super.onResume();
        if (!importing) refreshSetup();
    }

    private boolean hasFileAccess() {
        return Build.VERSION.SDK_INT < Build.VERSION_CODES.R || Environment.isExternalStorageManager();
    }

    /** Shows the setup step only while the game files are missing, and holds the play buttons until then. */
    private void refreshSetup() {
        boolean ready = hasFileAccess() && GameFiles.status() != GameFiles.MISSING;
        setupPanel.setVisibility(ready ? View.GONE : View.VISIBLE);
        // One setup panel covers both steps: first file access, then (only if still missing) the game files.
        int state = ready ? 0 : (hasFileAccess() ? 2 : 1);
        if (state != setupState) {
            setupState = state;
            if (state == 1) {
                setupNote.setText("First, let the game read files on this device. Turn on 'Allow access to manage all files', then come back.");
                pickButton.setText("Allow file access");
            } else if (state == 2) {
                setupNote.setText(PICK_NOTE);
                pickButton.setText("Pick your game files");
            }
        }
        for (View control : playControls) {
            control.setEnabled(ready);
            control.setAlpha(ready ? 1f : 0.4f);
        }
    }

    private void pickGameFiles() {
        if (!hasFileAccess()) {
            startActivity(new Intent(Settings.ACTION_MANAGE_APP_ALL_FILES_ACCESS_PERMISSION,
                    Uri.parse("package:" + getPackageName())));
            return;
        }
        Intent intent = new Intent(Intent.ACTION_OPEN_DOCUMENT_TREE);
        try {
            startActivityForResult(intent, PICK_GAME_FILES);
        } catch (android.content.ActivityNotFoundException e) {
            Toast.makeText(this, "This device has no folder picker.", Toast.LENGTH_LONG).show();
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode != PICK_GAME_FILES || resultCode != RESULT_OK || data == null) return;
        final File source = GameFiles.folderFromTree(data.getData());
        if (source == null || !source.isDirectory()) {
            setupNote.setText("That folder can't be read directly. Pick a folder on the device's own storage or SD card.");
            return;
        }
        importing = true;
        pickButton.setEnabled(false);
        setupNote.setText("Copying your game files. This can take a few minutes; keep the app open.");
        final File contentRoot = new File(filesRoot(), "user");
        new Thread(new Runnable() {
            @Override public void run() {
                final String result = GameFiles.importFrom(source, contentRoot);
                runOnUiThread(new Runnable() {
                    @Override public void run() {
                        importing = false;
                        pickButton.setEnabled(true);
                        if (result.startsWith("OK:")) {
                            Toast.makeText(LauncherActivity.this, result.substring(3), Toast.LENGTH_LONG).show();
                            refreshSetup();
                        } else {
                            setupNote.setText("The game files could not be copied. "
                                    + result.substring(Math.min(4, result.length()))
                                    + " Pick the folder again when it's fixed.");
                        }
                    }
                });
            }
        }, "harmony-import").start();
    }

    private void launch(String inviteCode, boolean online) {
        SharedPreferences prefs = getSharedPreferences(PREFS, MODE_PRIVATE);
        String name = nameField.getText().toString().trim();
        if (name.isEmpty() || !isPrintableAscii(name)) {
            Toast.makeText(this, "Player name: 1 to 15 plain letters or numbers", Toast.LENGTH_LONG).show();
            return;
        }
        String xuid = ensureXuid(prefs);
        boolean haptics = hapticsBox.isChecked();
        prefs.edit().putString(PREF_NAME, name).putBoolean(PREF_HAPTICS, haptics).apply();

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
        intent.putExtra(EXTRA_HAPTICS, haptics);
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

    /** Visible text box on the dark background (the stock EditText only draws a thin underline). */
    private void styleBox(EditText field) {
        field.setBackgroundColor(Color.rgb(44, 38, 64));
        field.setPadding(dp(12), dp(10), dp(12), dp(10));
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
