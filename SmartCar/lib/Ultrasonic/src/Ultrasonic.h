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
        uint8_t trg_pin;
        uint8_t echo_pin;
        uint8_t position;

    public:
        bool initialized;

    public:
        Ultrasonic(uint8_t trg_pin, uint8_t echo_pin, uint8_t position);
        ~Ultrasonic();
        virtual bool init();
        virtual void test();
        unsigned int getDistance();
    };
} // namespace Modules
#endif