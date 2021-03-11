#ifndef ADC_DUAL_ADS1015_H
#define ADC_DUAL_ADS1015_H

#include "IADC.h"
#include <Adafruit_ADS1015.h>

class AdcDualADS1015 : public IADC
{
  public:
    AdcDualADS1015();

    void Setup();
    unsigned int GetThrottle();
    unsigned int GetBrake();
    unsigned int GetClutch();
    
  private:
    Adafruit_ADS1015 throttleClutchADS;
    Adafruit_ADS1015 brakeADS;
    int16_t throttleReading;
    int16_t brakeReading;
    int16_t clutchReading;

    const unsigned int FIVE_VOLT_SIGNED_OFFSET = 2048;
};

#endif
