#ifndef ADC_INTERNAL_H
#define ADC_INTERNAL_H

#include "IADC.h"
#include "Arduino.h"

class AdcInternal : public IADC
{
    public:
        AdcInternal();

        void Setup();
        int GetThrottle();
        int GetBrake();
        int GetClutch();

    private:
        int throttleCount;
        int brakeCount;
        int clutchCount;

        const int THROTTLE_PIN = A1;
        const int BRAKE_PIN = A2;
        const int CLUTCH_PIN = A3;
};

#endif
