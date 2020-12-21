#include <Joystick.h>
#include "Filter.h"
#include "IADC.h"
#include "AdcDualADS1015.h"


//#define DEBUG // Enable this to turn on Serial printing

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_MULTI_AXIS, 0, 0, true, true, true, false, false, false, false, false, false, false, true);
SignalFilter signalFilters[3];
unsigned int filterSampleSize = 25;
IADC *adc = new AdcDualADS1015();

void setup() 
{
    //analogReadResolution(12);

    
#ifdef DEBUG    
    Serial.begin(115200);
    while (!Serial);
#endif

    //IADC *adc = new AdcDualADS1015();

    Joystick.setXAxisRange(0, 4096);
    Joystick.setYAxisRange(0, 4096);
    Joystick.setZAxisRange(0, 4096);
    Joystick.begin(false);
}

void loop() 
{
    // Read Throttle position
    unsigned int throttleValue = adc->GetThrottle();
    //unsigned int acceleratorValue = apply_filter(&signalFilters[1], filterSampleSize, adc->GetThrottle());
    Joystick.setXAxis(throttleValue);

    // Read Brake position
    unsigned int brakeValue = adc->GetBrake();
    //unsigned int brakeValue = apply_filter(&signalFilters[2], filterSampleSize, adc->GetBrake());
    Joystick.setYAxis(brakeValue);

    // Read clutch position
    unsigned int clutchValue = adc->GetClutch();
    //unsigned int clutchValue = apply_filter(&signalFilters[0], filterSampleSize, adc->GetClutch());
    Joystick.setZAxis(clutchValue);

    // Send all states
    Joystick.sendState();
        
#ifdef DEBUG
    // Print some debug if it helps
    Serial.print("T: ");
    Serial.print(throttleValue);
    Serial.print(" B: ");
    Serial.print(brakeValue);
    Serial.print(" C: ");
    Serial.println(clutchValue);
#endif
}
