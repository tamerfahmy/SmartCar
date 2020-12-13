#pragma once
#ifndef __ULTRASONIC_H__
#define __ULTRASONIC_H__

#include <stdint.h>
#include "BaseModule.h"
#include <HCSR04.h>
namespace Modules
{
    class Ultrasonic : public Modules::BaseModule
    {
    private:
        uint8_t trg_pin;
        uint8_t echo_pin;
        uint8_t position;
        //NewPing *distanceSensor;
        HCSR04 *distanceSensor;
        //UltraSonicDistanceSensor *distanceSensor;

    public:
        unsigned long dist;
        bool initialized;

    public:
        Ultrasonic(uint8_t trg_pin, uint8_t echo_pin, uint8_t position);
        ~Ultrasonic();
        virtual bool init();
        virtual void test();
        float getDistance();
    };
} // namespace Modules
#endif