#include "AdcDualADS1015.h"
#include "Arduino.h"

AdcDualADS1015::AdcDualADS1015() :
    throttleCount(0),
    brakeCount(0),
    clutchCount(0)
{
}

int AdcDualADS1015::GetThrottle()
{
    if(throttleCount > 4096)
    {
        throttleCount = 0;
    }
    else
    {
        throttleCount++;
    }
    
    return throttleCount;
}

int AdcDualADS1015::GetBrake()
{
    if(brakeCount > 4096)
    {
        brakeCount = 0;
    }
    else
    {
        brakeCount++;
    }

    return brakeCount;
}

int AdcDualADS1015::GetClutch()
{
    if(clutchCount > 4096)
    {
        clutchCount = 0;
    }
    else
    {
        clutchCount++;
    }

    return clutchCount;
}