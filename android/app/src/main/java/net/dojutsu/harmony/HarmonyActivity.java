package net.dojutsu.harmony;

import android.content.Intent;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.provider.Settings;
import android.widget.Toast;

import org.libsdl.app.SDLActivity;

/**
 * Harmony of Despair host activity. SDLActivity owns the surface, input and
 * audio; this subclass only names the native libraries and makes sure the app
 * can read the game data folder on shared storage.
 */
public class HarmonyActivity extends SDLActivity {
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
    protected void onCreate(Bundle savedInstanceState) {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R && !Environment.isExternalStorageManager()) {
            Toast.makeText(this, "Harmony needs 'All files access' to read the game data in /sdcard/HoD",
                    Toast.LENGTH_LONG).show();
            Intent intent = new Intent(Settings.ACTION_MANAGE_APP_ALL_FILES_ACCESS_PERMISSION,
                    Uri.parse("package:" + getPackageName()));
            startActivity(intent);
        }
        super.onCreate(savedInstanceState);
    }
}
