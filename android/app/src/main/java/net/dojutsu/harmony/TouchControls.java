package net.dojutsu.harmony;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.RectF;
import android.hardware.input.InputManager;
import android.os.Handler;
import android.os.Looper;
import android.os.VibrationEffect;
import android.os.Vibrator;
import android.util.Log;
import android.util.SparseArray;
import android.view.HapticFeedbackConstants;
import android.view.InputDevice;
import android.view.MotionEvent;
import android.view.View;

/**
 * See-through on-screen controller for phones without one. It drives a
 * virtual gamepad in the native game, so the game sees an ordinary
 * controller. It hides itself, and unplugs the virtual pad, whenever a real
 * controller (or the Thor's built-in one) is present.
 *
 * Menus get a fixed D-pad. In a stage (the title's presence says so) the
 * D-pad becomes an analog stick that appears wherever the left thumb lands
 * and disappears on release.
 */
final class TouchControls extends View implements InputManager.InputDeviceListener {
    // SDL gamepad button and axis numbers.
    private static final int A = 0, B = 1, X = 2, Y = 3, BACK = 4, START = 6, R3 = 8;
    private static final int LB = 9, RB = 10, UP = 11, DOWN = 12, LEFT = 13, RIGHT = 14;
    private static final int AXIS_LEFTX = 0, AXIS_LEFTY = 1, AXIS_LT = 4, AXIS_RT = 5;
    private static final int TRIGGER_BASE = 100;  // controls >= this are trigger axes
    private static final int STICK = -3, DPAD = -2, NONE = -1;
    private static final String TAG = "harmony";

    static native boolean nativeAttach();
    static native void nativeDetach();
    static native void nativeSetButton(int button, boolean down);
    static native void nativeSetAxis(int axis, int value);
    static native int nativePresence();

    private static final class Control {
        final int id;
        final String label;
        final RectF bounds = new RectF();
        boolean round;
        Control(int id, String label) { this.id = id; this.label = label; }
    }

    private final Control[] controls = {
        new Control(A, "A"), new Control(B, "B"), new Control(X, "X"), new Control(Y, "Y"),
        new Control(LB, "LB"), new Control(RB, "RB"),
        new Control(TRIGGER_BASE + AXIS_LT, "LT"), new Control(TRIGGER_BASE + AXIS_RT, "RT"),
        new Control(BACK, "BACK"), new Control(START, "START"), new Control(R3, "R3"),
    };
    private final Paint fill = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint pressedFill = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint outline = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint text = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Handler handler = new Handler(Looper.getMainLooper());
    private final InputManager inputManager;
    private final Vibrator vibrator;
    private final boolean haptics;

    // Which control each finger holds; a finger that starts on the D-pad or stick keeps steering it.
    private final SparseArray<Integer> fingers = new SparseArray<>();
    private float dpadX, dpadY, dpadRadius;
    private float stickZoneRight, stickZoneTop;
    private float stickOriginX, stickOriginY, stickKnobX, stickKnobY;
    private boolean stickHeld;
    private int stickAxisX, stickAxisY;
    private boolean stickMode;  // in a stage: analog stick instead of the D-pad
    private int presence = -1;
    private final boolean[] pressed = new boolean[TRIGGER_BASE + 6];
    private boolean attached;
    private boolean wanted;

    private final Runnable tryAttach = new Runnable() {
        @Override public void run() {
            if (!wanted || attached) return;
            attached = nativeAttach();
            if (!attached) handler.postDelayed(this, 500);
        }
    };

    // The title reports where the player is through its rich presence; check it a few times a second.
    private final Runnable pollPresence = new Runnable() {
        @Override public void run() {
            if (!wanted) return;
            int now = nativePresence();
            if (now != presence) {
                presence = now;
                boolean stage = now == 4 || now == 5;
                if (stage != stickMode) {
                    releaseAll();
                    stickMode = stage;
                    invalidate();
                }
                Log.i(TAG, "Touch controls: " + (stickMode ? "analog stick" : "D-pad")
                        + " (title presence " + now + ")");
            }
            handler.postDelayed(this, 250);
        }
    };

    TouchControls(Context context, boolean haptics) {
        super(context);
        this.haptics = haptics;
        fill.setColor(Color.argb(60, 255, 255, 255));
        pressedFill.setColor(Color.argb(140, 255, 255, 255));
        outline.setColor(Color.argb(110, 255, 255, 255));
        outline.setStyle(Paint.Style.STROKE);
        text.setColor(Color.argb(170, 255, 255, 255));
        text.setTextAlign(Paint.Align.CENTER);
        text.setFakeBoldText(true);
        vibrator = (Vibrator) context.getSystemService(Context.VIBRATOR_SERVICE);
        inputManager = (InputManager) context.getSystemService(Context.INPUT_SERVICE);
        if (inputManager != null) inputManager.registerInputDeviceListener(this, handler);
        refresh();
    }

    void release() {
        if (inputManager != null) inputManager.unregisterInputDeviceListener(this);
        wanted = false;
        handler.removeCallbacks(tryAttach);
        handler.removeCallbacks(pollPresence);
        if (attached) nativeDetach();
        attached = false;
    }

    /** True when a physical controller (not this virtual one) is connected. */
    private static boolean hasRealController() {
        for (int id : InputDevice.getDeviceIds()) {
            InputDevice device = InputDevice.getDevice(id);
            if (device == null || device.isVirtual()) continue;
            int sources = device.getSources();
            if ((sources & InputDevice.SOURCE_GAMEPAD) == InputDevice.SOURCE_GAMEPAD
                    || (sources & InputDevice.SOURCE_JOYSTICK) == InputDevice.SOURCE_JOYSTICK) {
                return true;
            }
        }
        return false;
    }

    private void refresh() {
        wanted = !hasRealController();
        setVisibility(wanted ? VISIBLE : GONE);
        handler.removeCallbacks(pollPresence);
        if (wanted) {
            handler.post(tryAttach);
            handler.post(pollPresence);
        } else {
            handler.removeCallbacks(tryAttach);
            releaseAll();
            if (attached) nativeDetach();
            attached = false;
        }
    }

    @Override public void onInputDeviceAdded(int deviceId) { refresh(); }
    @Override public void onInputDeviceRemoved(int deviceId) { refresh(); }
    @Override public void onInputDeviceChanged(int deviceId) { refresh(); }

    @Override
    protected void onSizeChanged(int w, int h, int oldw, int oldh) {
        float s = Math.min(w, h);
        float margin = s * 0.06f;
        dpadRadius = s * 0.17f;
        dpadX = margin + dpadRadius;
        dpadY = h - margin - dpadRadius;

        float face = s * 0.075f;      // face button radius
        float spread = s * 0.125f;    // distance from the diamond's centre
        float cx = w - margin - spread - face;
        float cy = h - margin - spread - face;
        circle(controls[0], cx, cy + spread, face);   // A bottom
        circle(controls[1], cx + spread, cy, face);   // B right
        circle(controls[2], cx - spread, cy, face);   // X left
        circle(controls[3], cx, cy - spread, face);   // Y top

        float bw = s * 0.2f, bh = s * 0.1f, top = s * 0.04f;
        rect(controls[6], margin, top, bw, bh);                      // LT
        rect(controls[4], margin, top + bh + s * 0.03f, bw, bh);    // LB
        rect(controls[7], w - margin - bw, top, bw, bh);             // RT
        rect(controls[5], w - margin - bw, top + bh + s * 0.03f, bw, bh); // RB

        float pw = s * 0.18f, ph = s * 0.075f;
        rect(controls[8], w / 2f - pw - s * 0.03f, top, pw, ph);     // BACK
        rect(controls[9], w / 2f + s * 0.03f, top, pw, ph);          // START

        // R3 (right-stick click, camera zoom): small, up and left of Y and X.
        circle(controls[10], w - s * 0.40f, h * 0.50f, s * 0.06f);

        // The floating stick can start anywhere on the left half below the shoulder buttons.
        stickZoneRight = w * 0.5f;
        stickZoneTop = top + 2f * bh + s * 0.06f;

        outline.setStrokeWidth(Math.max(2f, s * 0.006f));
        text.setTextSize(s * 0.045f);
    }

    private static void circle(Control c, float x, float y, float r) {
        c.round = true;
        c.bounds.set(x - r, y - r, x + r, y + r);
    }

    private static void rect(Control c, float x, float y, float w, float h) {
        c.round = false;
        c.bounds.set(x, y, x + w, y + h);
    }

    @Override
    protected void onDraw(Canvas canvas) {
        if (stickMode) {
            // Only drawn while a thumb holds it.
            if (stickHeld) {
                canvas.drawCircle(stickOriginX, stickOriginY, dpadRadius, fill);
                canvas.drawCircle(stickOriginX, stickOriginY, dpadRadius, outline);
                canvas.drawCircle(stickKnobX, stickKnobY, dpadRadius * 0.4f, pressedFill);
            }
        } else {
            // D-pad: a ring with four arms; the held direction lights up.
            canvas.drawCircle(dpadX, dpadY, dpadRadius, fill);
            canvas.drawCircle(dpadX, dpadY, dpadRadius, outline);
            float arm = dpadRadius * 0.62f, knob = dpadRadius * 0.22f;
            drawArrow(canvas, dpadX, dpadY - arm, knob, pressed[UP]);
            drawArrow(canvas, dpadX, dpadY + arm, knob, pressed[DOWN]);
            drawArrow(canvas, dpadX - arm, dpadY, knob, pressed[LEFT]);
            drawArrow(canvas, dpadX + arm, dpadY, knob, pressed[RIGHT]);
        }

        float baseline = (text.descent() + text.ascent()) / 2f;
        for (Control c : controls) {
            Paint p = pressed[c.id] ? pressedFill : fill;
            if (c.round) {
                canvas.drawOval(c.bounds, p);
                canvas.drawOval(c.bounds, outline);
            } else {
                float r = c.bounds.height() / 2f;
                canvas.drawRoundRect(c.bounds, r, r, p);
                canvas.drawRoundRect(c.bounds, r, r, outline);
            }
            canvas.drawText(c.label, c.bounds.centerX(), c.bounds.centerY() - baseline, text);
        }
    }

    private void drawArrow(Canvas canvas, float x, float y, float r, boolean on) {
        canvas.drawCircle(x, y, r, on ? pressedFill : fill);
    }

    /** What a finger landing at (x, y) takes hold of. */
    private int grab(float x, float y) {
        int button = hit(x, y);
        if (button != NONE) return button;
        if (stickMode) return !stickHeld && x < stickZoneRight && y > stickZoneTop ? STICK : NONE;
        return onDpad(x, y, 1.15f) ? DPAD : NONE;
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        int action = event.getActionMasked();
        int index = event.getActionIndex();
        switch (action) {
            case MotionEvent.ACTION_DOWN:
                // A touch that starts away from every control goes to the game as before.
                if (grab(event.getX(), event.getY()) == NONE) return false;
                // fall through
            case MotionEvent.ACTION_POINTER_DOWN: {
                int id = event.getPointerId(index);
                float x = event.getX(index), y = event.getY(index);
                int held = grab(x, y);
                fingers.put(id, held);
                if (held == STICK) {
                    stickHeld = true;
                    stickOriginX = stickKnobX = x;
                    stickOriginY = stickKnobY = y;
                }
                break;
            }
            case MotionEvent.ACTION_MOVE:
                for (int i = 0; i < event.getPointerCount(); i++) {
                    int id = event.getPointerId(i);
                    Integer held = fingers.get(id);
                    // Fingers on buttons may slide from one button to the next.
                    if (held != null && held != DPAD && held != STICK) fingers.put(id, hit(event.getX(i), event.getY(i)));
                }
                break;
            case MotionEvent.ACTION_UP:
            case MotionEvent.ACTION_POINTER_UP: {
                Integer held = fingers.get(event.getPointerId(index));
                if (held != null && held == STICK) stickHeld = false;
                fingers.remove(event.getPointerId(index));
                break;
            }
            case MotionEvent.ACTION_CANCEL:
                fingers.clear();
                stickHeld = false;
                break;
            default:
                break;
        }
        update(event, action == MotionEvent.ACTION_POINTER_UP || action == MotionEvent.ACTION_UP ? index : -1);
        return true;
    }

    private boolean onDpad(float x, float y, float scale) {
        float dx = x - dpadX, dy = y - dpadY;
        return dx * dx + dy * dy <= dpadRadius * dpadRadius * scale * scale;
    }

    private int hit(float x, float y) {
        for (Control c : controls) {
            // A little slack around each button makes them easier to press.
            float pad = c.bounds.height() * 0.2f;
            if (x >= c.bounds.left - pad && x <= c.bounds.right + pad
                    && y >= c.bounds.top - pad && y <= c.bounds.bottom + pad) {
                return c.id;
            }
        }
        return NONE;
    }

    private void update(MotionEvent event, int liftedIndex) {
        boolean[] next = new boolean[pressed.length];
        int axisX = 0, axisY = 0;
        for (int i = 0; i < event.getPointerCount(); i++) {
            if (i == liftedIndex) continue;
            Integer held = fingers.get(event.getPointerId(i));
            if (held == null || held == NONE) continue;
            if (held == STICK) {
                float dx = event.getX(i) - stickOriginX, dy = event.getY(i) - stickOriginY;
                float len = (float) Math.sqrt(dx * dx + dy * dy);
                if (len > dpadRadius) {  // the knob stays on the ring
                    dx *= dpadRadius / len;
                    dy *= dpadRadius / len;
                    len = dpadRadius;
                }
                stickKnobX = stickOriginX + dx;
                stickKnobY = stickOriginY + dy;
                if (len >= dpadRadius * 0.1f) {  // small dead zone
                    axisX = Math.round(dx / dpadRadius * 32767f);
                    axisY = Math.round(dy / dpadRadius * 32767f);
                }
            } else if (held == DPAD) {
                float dx = event.getX(i) - dpadX, dy = event.getY(i) - dpadY;
                float len = (float) Math.sqrt(dx * dx + dy * dy);
                if (len < dpadRadius * 0.25f) continue;  // dead zone in the middle
                // Eight directions: a component counts once it is past ~22 degrees of its axis.
                if (dx > len * 0.38f) next[RIGHT] = true;
                if (dx < -len * 0.38f) next[LEFT] = true;
                if (dy > len * 0.38f) next[DOWN] = true;
                if (dy < -len * 0.38f) next[UP] = true;
            } else {
                next[held] = true;
            }
        }
        setStick(axisX, axisY);
        apply(next);
        if (stickMode) invalidate();
    }

    private void setStick(int x, int y) {
        if (x != stickAxisX) {
            stickAxisX = x;
            if (attached) nativeSetAxis(AXIS_LEFTX, x);
        }
        if (y != stickAxisY) {
            stickAxisY = y;
            if (attached) nativeSetAxis(AXIS_LEFTY, y);
        }
    }

    private void releaseAll() {
        fingers.clear();
        stickHeld = false;
        setStick(0, 0);
        apply(new boolean[pressed.length]);
    }

    private void apply(boolean[] next) {
        boolean changed = false, tap = false;
        for (int i = 0; i < next.length; i++) {
            if (next[i] == pressed[i]) continue;
            pressed[i] = next[i];
            changed = true;
            if (next[i]) tap = true;  // a new press or a new D-pad direction
            if (!attached) continue;
            if (i >= TRIGGER_BASE) {
                nativeSetAxis(i - TRIGGER_BASE, next[i] ? 32767 : -32768);
            } else {
                nativeSetButton(i, next[i]);
            }
        }
        if (tap) buzz();
        if (changed) invalidate();
    }

    /** A light tap, when the player left vibration on at the start screen. */
    private void buzz() {
        if (!haptics) return;
        if (vibrator != null && vibrator.hasVibrator()) {
            vibrator.vibrate(VibrationEffect.createPredefined(VibrationEffect.EFFECT_TICK));
        } else {
            performHapticFeedback(HapticFeedbackConstants.KEYBOARD_TAP);
        }
    }
}
