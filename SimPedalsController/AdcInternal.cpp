#include "AdcInternal.h"
#include "Arduino.h"
#include "debug.h"

AdcInternal::AdcInternal()
{
}

void AdcInternal::Setup()
{
// Enable 12 bit readings 
#if defined(ARDUINO_ARCH_SAMD)
    DebugPrint("Enabling 12-bit resolution");
    analogReadResolution(12);
#endif
}

int AdcInternal::GetThrottle()
{
    return analogRead(THROTTLE_PIN);
}

int AdcInternal::GetBrake()
{
    return analogRead(BRAKE_PIN);
}

int AdcInternal::GetClutch()
{
    return analogRead(CLUTCH_PIN);;
}