/**
 * LED utilizing library
 *
 * This provides a function that makes LED on and off like doing breath.
 */

#ifndef LED_H
#define LED_H

#include "arduino.h"

class LED
{
    private:
        int      pin_id_    =  0;
        uint32_t p_counter_ =  0;
        uint32_t interval_  = 10;

        int degree_ = 0;

    public:
        /**
         * Constructor
         *
         * @param pin_id    PIN number
         * @param interval  Controlling breath spead. unit is loop cycle not millisecond.
         */
        LED(int pin_id, uint32_t interval = 10, int ini_deg = 0);

        /**
         * main loop
         *
         * Being called from loop() to make LED breathed.
         */
        void run();
};

#endif
