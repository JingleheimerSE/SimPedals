#include "AdcInternal.h"
#include "Arduino.h"

AdcInternal::AdcInternal()
{
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