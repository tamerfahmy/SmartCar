#pragma once
#ifndef __ULTRASONIC_H__
#define __ULTRASONIC_H__

#include <stdint.h>
#include "BaseModule.h"

namespace Modules
{
    class Ultrasonic : public Modules::BaseModule
    {
    private:
        uint8_t *trgPins;
        uint8_t echoPin;
        uint8_t numberOfSensors;

    public:
        bool initialized;

    public:
        Ultrasonic(uint8_t *trgPins, uint8_t echoPin, uint8_t numberOfSensors);
        ~Ultrasonic();
        virtual bool init();
        virtual void test();
        double getDistance(uint8_t i, float temperature = U_TEMPRTURE);
        double *getDistances(float temperature = U_TEMPRTURE);
        double getAvgDistance(float temperature = U_TEMPRTURE);
    };
} // namespace Modules
#endif