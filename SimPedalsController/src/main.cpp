#include <Arduino.h>
#include <Joystick.h>
#include "Filter.h"
#include "IADC.h"
#include "AdcTest.h"
#include "AdcDualADS1015.h"
#include "AdcInternal.h"
#include "Debug.h"

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_MULTI_AXIS, 0, 0, true, true, true, false, false, false, false, false, false, false, true);
SignalFilter signalFilters[3];
unsigned int filterSampleSize = 25;

enum AdcType
{
    Test,
    Internal,
    DualAds1015
};

/*
 * Factory for building the ADC abstraction layer
 */
IADC* AdcFactory(AdcType adcType)
{
    switch(adcType)
    {
        case DualAds1015:
            return new AdcDualADS1015();
            break;
        case Internal:
            return new AdcInternal();
            break;
        default:
            DebugPrint("Error: Unknown ADC type, defaulting to Test ADC");
        case Test:
            return new AdcTest();
            break;
    }
}
IADC *adc = AdcFactory(AdcType::DualAds1015);

/*
 * Program one time configuration and setup
 */
void setup()
{
#ifdef SERIAL_DEBUG_ENABLED    
    Serial.begin(115200);
    while (!Serial);
    DebugPrint("Debug enabled")
#endif

    adc->Setup();

    Joystick.setXAxisRange(0, 4096);
    Joystick.setYAxisRange(0, 4096);
    Joystick.setZAxisRange(0, 4096);
    Joystick.begin(false);
}

/*
 * Main loop that runs continuously
 */
void loop() 
{
    if(adc != nullptr)
    {
        // Read Throttle position
        unsigned int throttleValue = adc->GetThrottle();
        //unsigned int acceleratorValue = apply_filter(&signalFilters[0], filterSampleSize, adc->GetThrottle());
        Joystick.setXAxis(throttleValue);

        // Read Brake position
        unsigned int brakeValue = adc->GetBrake();
        //unsigned int brakeValue = apply_filter(&signalFilters[1], filterSampleSize, adc->GetBrake());
        Joystick.setYAxis(brakeValue);

        // Read clutch position
        unsigned int clutchValue = adc->GetClutch();
        //unsigned int clutchValue = apply_filter(&signalFilters[2], filterSampleSize, adc->GetClutch());
        Joystick.setZAxis(clutchValue);

        // Send all states
        Joystick.sendState();

        // Print some debug if its enabled
        DebugPrint(throttleValue);
        DebugPrint("\t");
        DebugPrint(brakeValue);
        DebugPrint("\t");
        DebugPrintln(clutchValue);
    }
    else
    {
        DebugPrint("Error: ADC is NULL");
    }
}
