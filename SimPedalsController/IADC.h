#ifndef I_ADC_H
#define I_ADC_H

class IADC {
    public:
        virtual ~IADC() {}
    
        virtual void Setup() {}
        virtual unsigned int GetThrottle() = 0;
        virtual unsigned int GetBrake() = 0;
        virtual unsigned int GetClutch() = 0;
};

#endif
