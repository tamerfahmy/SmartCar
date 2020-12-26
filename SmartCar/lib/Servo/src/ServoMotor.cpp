#include <arduino.h>
#include "ServoMotor.h"

namespace Modules
{
    ServoMotor::ServoMotor(uint8_t pin, uint8_t minAngle, uint8_t maxAngle)
    {
        this->pin = pin;
        this->minAngle = minAngle;
        this->maxAngle = maxAngle;

        this->Motor = new Servo();
    }

    ServoMotor::~ServoMotor()
    {
    }

    bool ServoMotor::init()
    {
        return initialized = true;
    }

    void ServoMotor::test()
    {
        this->moveToAngle(70);
        this->moveToAngle(110);
        this->moveToAngle(90);
    }

    void ServoMotor::moveToAngle(uint8_t angle)
    {
        if (angle > this->maxAngle)
            angle = this->maxAngle;
        else if (angle < this->minAngle)
            angle = this->minAngle;

        //sets the servo position according to the  value
        this->Motor->attach(3);
        this->Motor->write(angle);
        delay(500);
        this->Motor->detach();
    }
} // namespace Modules
