package net.dojutsu.harmony;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.RectF;
import android.hardware.input.InputManager;
import android.os.Handler;
import android.os.Looper;
import android.util.SparseArray;
import android.view.InputDevice;
import android.view.MotionEvent;
import android.view.View;

/**
 * See-through on-screen controller for phones without one. It drives a
 * virtual gamepad in the native game, so the game sees an ordinary
 * controller. It hides itself, and unplugs the virtual pad, whenever a real
 * controller (or the Thor's built-in one) is present.
 */
final class TouchControls extends View implements InputManager.InputDeviceListener {
    // SDL gamepad button and axis numbers.
    private static final int A = 0, B = 1, X = 2, Y = 3, BACK = 4, START = 6;
    private static final int LB = 9, RB = 10, UP = 11, DOWN = 12, LEFT = 13, RIGHT = 14;
    private static final int AXIS_LT = 4, AXIS_RT = 5;
    private static final int TRIGGER_BASE = 100;  // controls >= this are trigger axes
    private static final int DPAD = -2, NONE = -1;

    static native boolean nativeAttach();
    static native void nativeDetach();
    static native void nativeSetButton(int button, boolean down);
    static native void nativeSetAxis(int axis, int value);

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
        new Control(BACK, "BACK"), new Control(START, "START"),
    };
    private final Paint fill = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint pressedFill = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint outline = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint text = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Handler handler = new Handler(Looper.getMainLooper());
    private final InputManager inputManager;

    // Which control each finger holds; a finger that starts on the D-pad keeps steering it.
    private final SparseArray<Integer> fingers = new SparseArray<>();
    private float dpadX, dpadY, dpadRadius;
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

    TouchControls(Context context) {
        super(context);
        fill.setColor(Color.argb(60, 255, 255, 255));
        pressedFill.setColor(Color.argb(140, 255, 255, 255));
        outline.setColor(Color.argb(110, 255, 255, 255));
        outline.setStyle(Paint.Style.STROKE);
        text.setColor(Color.argb(170, 255, 255, 255));
        text.setTextAlign(Paint.Align.CENTER);
        text.setFakeBoldText(true);
        inputManager = (InputManager) context.getSystemService(Context.INPUT_SERVICE);
        if (inputManager != null) inputManager.registerInputDeviceListener(this, handler);
        refresh();
    }

    void release() {
        if (inputManager != null) inputManager.unregisterInputDeviceListener(this);
        wanted = false;
        handler.removeCallbacks(tryAttach);
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
        if (wanted) {
            handler.post(tryAttach);
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
        // D-pad: a ring with four arms; the held direction lights up.
        canvas.drawCircle(dpadX, dpadY, dpadRadius, fill);
        canvas.drawCircle(dpadX, dpadY, dpadRadius, outline);
        float arm = dpadRadius * 0.62f, knob = dpadRadius * 0.22f;
        drawArrow(canvas, dpadX, dpadY - arm, knob, pressed[UP]);
        drawArrow(canvas, dpadX, dpadY + arm, knob, pressed[DOWN]);
        drawArrow(canvas, dpadX - arm, dpadY, knob, pressed[LEFT]);
        drawArrow(canvas, dpadX + arm, dpadY, knob, pressed[RIGHT]);

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

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        int action = event.getActionMasked();
        int index = event.getActionIndex();
        switch (action) {
            case MotionEvent.ACTION_DOWN:
            case MotionEvent.ACTION_POINTER_DOWN: {
                int id = event.getPointerId(index);
                float x = event.getX(index), y = event.getY(index);
                fingers.put(id, onDpad(x, y, 1.15f) ? DPAD : hit(x, y));
                break;
            }
            case MotionEvent.ACTION_MOVE:
                for (int i = 0; i < event.getPointerCount(); i++) {
                    int id = event.getPointerId(i);
                    Integer held = fingers.get(id);
                    // Fingers on buttons may slide from one button to the next.
                    if (held != null && held != DPAD) fingers.put(id, hit(event.getX(i), event.getY(i)));
                }
                break;
            case MotionEvent.ACTION_UP:
            case MotionEvent.ACTION_POINTER_UP:
                fingers.remove(event.getPointerId(index));
                break;
            case MotionEvent.ACTION_CANCEL:
                fingers.clear();
                break;
            default:
                break;
        }
        update(event, action == MotionEvent.ACTION_POINTER_UP || action == MotionEvent.ACTION_UP ? index : -1);
        return true;  // the game itself has no use for touches
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
        for (int i = 0; i < event.getPointerCount(); i++) {
            if (i == liftedIndex) continue;
            Integer held = fingers.get(event.getPointerId(i));
            if (held == null || held == NONE) continue;
            if (held == DPAD) {
                float dx = event.getX(i) - dpadX, dy = event.getY(i) - dpadY;
                float len = (float) Math.sqrt(dx * dx + dy * dy);
                if (len < dpadRadius * 0.2f) continue;  // dead zone in the middle
                // Eight directions: a component counts once it is past ~22 degrees of its axis.
                if (dx > len * 0.38f) next[RIGHT] = true;
                if (dx < -len * 0.38f) next[LEFT] = true;
                if (dy > len * 0.38f) next[DOWN] = true;
                if (dy < -len * 0.38f) next[UP] = true;
            } else {
                next[held] = true;
            }
        }
        apply(next);
    }

    private void releaseAll() {
        fingers.clear();
        apply(new boolean[pressed.length]);
    }

    private void apply(boolean[] next) {
        boolean changed = false;
        for (int i = 0; i < next.length; i++) {
            if (next[i] == pressed[i]) continue;
            pressed[i] = next[i];
            changed = true;
            if (!attached) continue;
            if (i >= TRIGGER_BASE) {
                nativeSetAxis(i - TRIGGER_BASE, next[i] ? 32767 : -32768);
            } else {
                nativeSetButton(i, next[i]);
            }
        }
        if (changed) invalidate();
    }
}
