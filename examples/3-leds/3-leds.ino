// for Arduino LEONARD

#include "led.h"

#define LED_LEN 3

LED *leds[LED_LEN];
int led_pins[] = { 3, 5, 6 };

void setup() {
    // initialize 3 leds
    for (int i=0; i<LED_LEN; i++) leds[i] = new LED(led_pins[i], 75, i * 60);
}

void loop() {
    // call each main loop
    for (int i=0; i<LED_LEN; i++) leds[i]->run();
}
