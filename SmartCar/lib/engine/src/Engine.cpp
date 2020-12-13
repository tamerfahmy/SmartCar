//    Left motor truth table
//  ENA         IN1               IN2         Description
//  LOW   Not Applicable    Not Applicable    Motor is off
//  HIGH        LOW               LOW         Motor is stopped (brakes)
//  HIGH        HIGH              LOW         Motor is on and turning forwards
//  HIGH        LOW               HIGH        Motor is on and turning backwards
//  HIGH        HIGH              HIGH        Motor is stopped (brakes)

//    Right motor truth table
//  ENB         IN3             IN4         Description
//  LOW   Not Applicable   Not Applicable   Motor is off
//  HIGH        LOW             LOW         Motor is stopped (brakes)
//  HIGH        LOW             HIGH        Motor is on and turning forwards
//  HIGH        HIGH            LOW         Motor is on and turning backwards
//  HIGH        HIGH            HIGH        Motor is stopped (brakes)

//    The direction of the car's movement
//  Left motor    Right motor     Description
//  stop(off)     stop(off)       Car is stopped
//  forward       forward         Car is running forwards
//  forward       backward        Car is turning right
//  backward      forward         Car is turning left
//  backward      backward        Car is running backwards

#include <stdint.h>
#include <arduino.h>
#include "Engine.h"
#include "OSConstants.h"

namespace Modules
{
  Engine::Engine()
  {
  }

  Engine::~Engine()
  {
  }

  bool Engine::init()
  {
    this->ena = ENA;
    this->enb = ENB;
    this->in1 = IN1;
    this->in2 = IN2;
    this->in3 = IN3;
    this->in4 = IN4;

    initPinMode();

    direction = STOP;
    return true;
  }

  void Engine::initPinMode()
  {
    // Motor-driven port configuration
    pinMode(this->in1, OUTPUT);
    pinMode(this->in2, OUTPUT);
    pinMode(this->in3, OUTPUT);
    pinMode(this->in4, OUTPUT);
    pinMode(this->ena, OUTPUT);
    pinMode(this->enb, OUTPUT);
  }

  void Engine::test()
  {
    direction = FORWARD;
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(ena, 150);
    analogWrite(enb, 150);
    delay(100);
    stop();

    direction = BACKWARD;
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(ena, 150);
    analogWrite(enb, 150);
    delay(100);
    stop();
  }

  /*
  Control motor：Car movement forward
  */
  void Engine::forward(int16_t carSpeed, unsigned int period_ms)
  {
    direction = FORWARD;
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    accelerate(carSpeed);
    delayPeriod(period_ms);
  }
  /*
  Control motor：Car moving backwards
  */
  void Engine::back(int16_t carSpeed, unsigned int period_ms)
  {
    direction = BACKWARD;
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    accelerate(carSpeed);
    delayPeriod(period_ms);
  }
  /*
  Control motor：The car turns left and moves forward
  */
  void Engine::left(int16_t carSpeed, unsigned int period_ms)
  {
    direction = LEFT;
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    accelerate(carSpeed);
    delayPeriod(period_ms);
  }
  /*
  Control motor：The car turns right and moves forward
  */
  void Engine::right(int16_t carSpeed, unsigned int period_ms)
  {
    direction = RIGHT;
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    accelerate(carSpeed);
    delayPeriod(period_ms);
  }

  /*
  Control motor：The car turns right
  */
  void Engine::forwardLeft(int16_t carSpeed, unsigned int period_ms)
  {
    direction = FORWARD_LEFT;
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(ena, carSpeed / 2);
    analogWrite(enb, carSpeed);
    //accelerate(carSpeed, 1, 2);
    delayPeriod(period_ms);
  }

  /*
  Control motor：The car turns right
  */
  void Engine::forwardRight(int16_t carSpeed, unsigned int period_ms)
  {
    direction = FORWARD_RIGHT;
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(ena, carSpeed);
    analogWrite(enb, carSpeed / 2);
    //accelerate(carSpeed / 2, 2, 1);
    delayPeriod(period_ms);
  }

  /*
  Control motor：The car turns right
  */
  void Engine::backLeft(int16_t carSpeed, unsigned int period_ms)
  {
    direction = BACKWARD_LEFT;
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(ena, carSpeed / 2);
    analogWrite(enb, carSpeed);
    //accelerate(carSpeed / 2, 1, 2);
    delayPeriod(period_ms);
  }

  /*
  Control motor：The car turns back right
  */
  void Engine::backRight(int16_t carSpeed, unsigned int period_ms)
  {
    direction = BACKWARD_RIGHT;
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(ena, carSpeed);
    analogWrite(enb, carSpeed / 2);
    //accelerate(carSpeed, 2, 1);
    delayPeriod(period_ms);
  }

  /*
  Stop motor control：Turn off the motor drive
  */
  void Engine::stop()
  {
    direction = STOP;
    digitalWrite(ena, LOW);
    digitalWrite(enb, LOW);
  }

  void Engine::accelerate(int16_t maxSpeed, int16_t aFactor, int16_t bFactor)
  {
    for (int i = 0; i <= maxSpeed; i += 2)
    {
      analogWrite(ena, i * aFactor);
      analogWrite(enb, i * bFactor);
      delay(20);
    }
  }

  void Engine::delayPeriod(unsigned int period_ms)
  {
    if (period_ms != 0)
    {
      delay(period_ms);
      stop();
    }
  }
} // namespace Modules