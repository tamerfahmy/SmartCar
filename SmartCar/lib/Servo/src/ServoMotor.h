#pragma once
#ifndef __SERVOMOTOR_H__
#define __SERVOMOTOR_H__

#include "BaseModule.h"
#include "Servo.h"

namespace Modules
{
    class ServoMotor : public Modules::BaseModule
    {
    private:
        uint8_t pin;
        uint8_t minAngle;
        uint8_t maxAngle;

    public:
        Servo *Motor;
        bool initialized;

    public:
        ServoMotor(uint8_t pin, uint8_t minAngle, uint8_t maxAngle);
        ~ServoMotor();
        virtual bool init();
        virtual void test();
        void moveToAngle(uint8_t angle);
    };
} // namespace Modules
#endif