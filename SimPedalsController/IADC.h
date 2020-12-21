#ifndef I_ADC_H
#define I_ADC_H

class IADC {
  public:
    virtual ~IADC() {}
    
    virtual int GetThrottle() = 0;
    virtual int GetBrake() = 0;
    virtual int GetClutch() = 0;
};

#endif
