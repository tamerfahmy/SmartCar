#include <stdint.h>
#include <arduino.h>
#include "OSConstants.h"
#include "Ultrasonic.h"

namespace Modules
{
    Ultrasonic::Ultrasonic(uint8_t *trgPins, uint8_t echoPin, uint8_t numberOfSensors)
    {
        this->echoPin = echoPin;
        this->numberOfSensors = numberOfSensors;

        for (uint8_t i = 0; i < numberOfSensors; i++)
        {
            this->trgPins[i] = trgPins[i];
        }
    }

    Ultrasonic::~Ultrasonic()
    {
    }

    bool Ultrasonic::init()
    {

        for (uint8_t i = 0; i < this->numberOfSensors; i++)
            pinMode(this->trgPins[i], OUTPUT);

        pinMode(this->echoPin, INPUT);

        return initialized = true;
    }

    void Ultrasonic::test()
    {
        if (!initialized)
            Serial.println("Failed initializing ultrsonic");
        else
        {
            double distance = this->getDistance(0);
            Serial.print("Testing distance for ultrasonice sensor at position (");
            Serial.print("): ");
            Serial.print(distance);
            Serial.println(" cm");
        }
    }

    /**
     * Gets specific Ultrasonic sensor distance
     */
    double Ultrasonic::getDistance(uint8_t i, float temperature)
    {
        //delay(50);
        // Make sure that trigger pin is LOW.
        digitalWrite(this->trgPins[i], LOW);
        delayMicroseconds(2);
        // Hold trigger for 10 microseconds, which is signal for sensor to measure distance.
        digitalWrite(this->trgPins[i], HIGH);
        delayMicroseconds(10);
        digitalWrite(this->trgPins[i], LOW);
        // Measure the length of echo signal, which is equal to the time needed for sound to go there and back.
        unsigned long durationMicroSec = pulseIn(this->echoPin, HIGH);
        double speedOfSoundInCmPerMs = 0.03313 + 0.0000606 * temperature; // Cair ≈ (331.3 + 0.606 ⋅ ϑ) m/s
        double distanceCm = durationMicroSec / 2.0 * speedOfSoundInCmPerMs;
        if (distanceCm > U_MAX_DISTANCE)
            return -1.0;
        else
            return distanceCm;
    }

    /**
     * Get Ultrasonic array distances
     */
    double *Ultrasonic::getDistances(float temperature)
    {
        double *distances = new double[this->numberOfSensors];

        for (uint8_t i = 0; i < this->numberOfSensors; i++)
        {
            distances[i] = getDistance(i, temperature);
        }

        return distances;
    }

    double Ultrasonic::getAvgDistance(float temperature = U_TEMPRTURE)
    {
        double *dist = getDistances(temperature);
        double avgDistance = 0;
        for (uint8_t i = 0; i < 3; i++)
        {
            avgDistance += dist[i];
        }
        return avgDistance / 3;
    }
} // namespace Modules