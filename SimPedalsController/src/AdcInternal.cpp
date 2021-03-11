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

unsigned int AdcInternal::GetThrottle()
{
    return analogRead(THROTTLE_PIN);
}

unsigned int AdcInternal::GetBrake()
{
    return analogRead(BRAKE_PIN);
}

unsigned int AdcInternal::GetClutch()
{
    return analogRead(CLUTCH_PIN);;
}