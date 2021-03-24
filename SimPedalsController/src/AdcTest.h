#ifndef ADC_TEST_H
#define ADC_TEST_H

#include "IADC.h"
#include "Arduino.h"

class AdcTest : public IADC
{
    public:
        AdcTest();

        void Setup();
        unsigned int  GetThrottle();
        unsigned int  GetBrake();
        unsigned int  GetClutch();

    private:
        unsigned int  throttleCount;
        unsigned int  brakeCount;
        unsigned int  clutchCount;
};

#endif
