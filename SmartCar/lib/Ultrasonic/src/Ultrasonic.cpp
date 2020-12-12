#include <stdint.h>
#include <arduino.h>
#include "OSConstants.h"
#include "Ultrasonic.h"

namespace Modules
{
    Ultrasonic::Ultrasonic(uint8_t trg_pin, uint8_t echo_pin, uint8_t position)
    {
        this->trg_pin = trg_pin;
        this->echo_pin = echo_pin;
        this->position = position;
    }

    Ultrasonic::~Ultrasonic()
    {
    }

    bool Ultrasonic::init()
    {
        // pinMode(this->trg_pin, OUTPUT);
        // pinMode(this->echo_pin, INPUT);

        initialized = true;

        return initialized;
    }

    void Ultrasonic::test()
    {
        if (!initialized)
            Serial.println("Failed initializing ultrsonic");
        else
        {
            unsigned int distance = getDistance();
            Serial.print("Testing distance for ultrasonice sensor at position (");
            Serial.print(position);
            Serial.print("): ");
            Serial.print(distance);
            Serial.println(" cm");
        }
    }

    unsigned int Ultrasonic::getDistance()
    {
        digitalWrite(trg_pin, LOW);
        delayMicroseconds(2);
        digitalWrite(trg_pin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trg_pin, LOW);
        unsigned int tempda_x = 0;
        tempda_x = ((unsigned int)pulseIn(echo_pin, HIGH) / 58);

        // if greater than 150 cm set it to maximum of 150 cm
        if (tempda_x > 150)
            tempda_x = 150;

        // return tempda;
        return tempda_x;
    }
} // namespace Modules