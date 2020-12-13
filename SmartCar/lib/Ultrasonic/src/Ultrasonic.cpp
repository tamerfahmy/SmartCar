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
        pinMode(this->trg_pin, OUTPUT);
        pinMode(this->echo_pin, INPUT);

        distanceSensor = new HCSR04(this->trg_pin, this->echo_pin);
        initialized = true;
        return initialized;
    }

    void Ultrasonic::test()
    {
        if (!initialized)
            Serial.println("Failed initializing ultrsonic");
        else
        {
            unsigned int distance = distanceSensor->dist(0);
            Serial.print("Testing distance for ultrasonice sensor at position (");
            Serial.print(position);
            Serial.print("): ");
            Serial.print(distance);
            Serial.println(" cm");
        }
    }

    float Ultrasonic::getDistance()
    {
        if (distanceSensor->dist(0) < 400)
            return distanceSensor->dist(0);
        else
            return 400;
    }

    // double measureDistanceCm(float temperature)
    // {
    //     // Make sure that trigger pin is LOW.
    //     digitalWrite(triggerPin, LOW);
    //     delayMicroseconds(2);
    //     // Hold trigger for 10 microseconds, which is signal for sensor to measure distance.
    //     digitalWrite(triggerPin, HIGH);
    //     delayMicroseconds(10);
    //     digitalWrite(triggerPin, LOW);
    //     // Measure the length of echo signal, which is equal to the time needed for sound to go there and back.
    //     unsigned long durationMicroSec = pulseIn(echoPin, HIGH);

    //     double speedOfSoundInCmPerMs = 0.03313 + 0.0000606 * temperature; // Cair ≈ (331.3 + 0.606 ⋅ ϑ) m/s
    //     double distanceCm = durationMicroSec / 2.0 * speedOfSoundInCmPerMs;
    //     if (distanceCm == 0 || distanceCm > 400)
    //     {
    //         return -1.0;
    //     }
    //     else
    //     {
    //         return distanceCm;
    //     }
    // }

    // float HCSR04::dist(int n) const
    // {
    //     digitalWrite(this->out, LOW);
    //     delayMicroseconds(2);
    //     digitalWrite(this->out, HIGH);
    //     delayMicroseconds(10);
    //     digitalWrite(this->out, LOW);
    //     noInterrupts();
    //     float d = pulseIn(this->echo[n], HIGH);
    //     interrupts();
    //     return d / 58.0;
    // }
} // namespace Modules