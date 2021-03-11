#include "AdcDualADS1015.h"
#include "Arduino.h"
#include "Debug.h"

AdcDualADS1015::AdcDualADS1015() :
    throttleClutchADS(0x48),
    brakeADS(0x49),
    throttleReading(0),
    brakeReading(0),
    clutchReading(0)
{
}

void AdcDualADS1015::Setup()
{
    throttleClutchADS.setGain(GAIN_TWO);
    throttleClutchADS.begin();

    brakeADS.setGain(GAIN_FOUR);
    brakeADS.begin();
}

unsigned int AdcDualADS1015::GetThrottle()
{   
    throttleReading = throttleClutchADS.readADC_Differential_0_1() + FIVE_VOLT_SIGNED_OFFSET;

    return static_cast<unsigned int>(throttleReading);
}

unsigned int AdcDualADS1015::GetBrake()
{
    brakeReading = brakeADS.readADC_Differential_0_1() + FIVE_VOLT_SIGNED_OFFSET;

    return static_cast<unsigned int>(brakeReading);
}

unsigned int AdcDualADS1015::GetClutch()
{
    clutchReading = throttleClutchADS.readADC_Differential_2_3() + FIVE_VOLT_SIGNED_OFFSET;

    return static_cast<unsigned int>(clutchReading);
}