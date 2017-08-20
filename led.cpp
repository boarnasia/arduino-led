#include "led.h"

LED::LED(int pin_id, uint32_t interval, int ini_deg) {
    pin_id_ = pin_id;
    interval_ = interval;
    degree_ = ini_deg;
    pinMode(pin_id_, OUTPUT);
}

void LED::run() {
    // Doing process step by interval.
    if ((p_counter_++ % interval_) == 0.0f) {
        // Tuning brightness along with sin wave.
        degree_ += 1;
        if (degree_ >= 360) degree_ = 0;
        float rad = degree_ * M_PI / 180;
        int lvl = (int) 255.0 * ((sin(rad) + 1) / 2);

        analogWrite(pin_id_, lvl);
    }

    // Overflow gard
    if ((UINT32_MAX - p_counter_) < (UINT32_MAX % interval_)) {
        p_counter_ = 0;
    }
}
