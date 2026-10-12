package net.dojutsu.harmony;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.URL;

/**
 * HTTP bridge for the engine's session-directory client. The native side
 * (rexruntime, session_directory.cpp) calls {@link #request} through JNI so
 * the directory is reached with Android's own TLS stack and trust store.
 */
public final class HarmonyHttp {
    private static final int MAX_RESPONSE_BYTES = 64 * 1024;

    private HarmonyHttp() {}

    /**
     * Performs one request synchronously on the calling (native) thread.
     *
     * @param status receives the HTTP status code in status[0]
     * @return the response body (possibly empty), or null when no response arrived
     */
    public static byte[] request(String url, String method, String bearer, byte[] body, int[] status) {
        HttpURLConnection connection = null;
        try {
            if (url == null || !(url.startsWith("https://") || url.startsWith("http://"))) return null;
            connection = (HttpURLConnection) new URL(url).openConnection();
            connection.setConnectTimeout(1500);
            connection.setReadTimeout(2500);
            connection.setInstanceFollowRedirects(false);
            connection.setUseCaches(false);
            connection.setRequestMethod(method);
            connection.setRequestProperty("User-Agent", "HarmonyRecomp/1");
            connection.setRequestProperty("Accept", "application/json");
            connection.setRequestProperty("Content-Type", "application/json");
            if (bearer != null && !bearer.isEmpty()) {
                connection.setRequestProperty("Authorization", "Bearer " + bearer);
            }
            if (body != null && body.length > 0) {
                connection.setDoOutput(true);
                connection.setFixedLengthStreamingMode(body.length);
                OutputStream out = connection.getOutputStream();
                out.write(body);
                out.close();
            }
            int code = connection.getResponseCode();
            if (status != null && status.length > 0) status[0] = code;
            InputStream in = code >= 400 ? connection.getErrorStream() : connection.getInputStream();
            ByteArrayOutputStream buffer = new ByteArrayOutputStream();
            if (in != null) {
                byte[] chunk = new byte[4096];
                int read;
                while ((read = in.read(chunk)) > 0) {
                    if (buffer.size() + read > MAX_RESPONSE_BYTES) {
                        in.close();
                        return null;
                    }
                    buffer.write(chunk, 0, read);
                }
                in.close();
            }
            return buffer.toByteArray();
        } catch (IOException | RuntimeException e) {
            return null;
        } finally {
            if (connection != null) connection.disconnect();
        }
    }
}
