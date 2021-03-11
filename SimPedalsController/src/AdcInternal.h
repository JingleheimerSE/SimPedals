#ifndef ADC_INTERNAL_H
#define ADC_INTERNAL_H

#include "IADC.h"
#include "Arduino.h"

class AdcInternal : public IADC
{
    public:
        AdcInternal();

        void Setup();
        unsigned int  GetThrottle();
        unsigned int  GetBrake();
        unsigned int  GetClutch();

    private:
        unsigned int  throttleCount;
        unsigned int  brakeCount;
        unsigned int  clutchCount;

        const int THROTTLE_PIN = A1;
        const int BRAKE_PIN = A2;
        const int CLUTCH_PIN = A3;
};

#endif
