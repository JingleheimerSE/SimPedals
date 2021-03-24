#include "AdcTest.h"
#include "Arduino.h"
#include "debug.h"

AdcTest::AdcTest():
    throttleCount(0),
    brakeCount(0),
    clutchCount(0)
{
}

void AdcTest::Setup()
{
}

unsigned int AdcTest::GetThrottle()
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

unsigned int AdcTest::GetBrake()
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

unsigned int AdcTest::GetClutch()
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