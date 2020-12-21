#ifndef ADC_DUAL_ADS1015_H
#define ADC_DUAL_ADS1015_H

#include "IADC.h"

class AdcDualADS1015 : public IADC
{
  public:
    AdcDualADS1015();

    int GetThrottle();
    int GetBrake();
    int GetClutch();
    
  private:
    int throttleCount;
    int brakeCount;
    int clutchCount;
};

#endif
