//#include "CarOs.h"
#include <Arduino.h>
//#include "OS.h"
#include "CarOs.h"

//CarOs *carOS;

void setup()
{
  // pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

  // Builtin LED configuration
  pinMode(LED_BUILTIN, OUTPUT);

  // Ultrasonic Sensor configuration
  // pinMode(TRIG_PIN_S0, OUTPUT);
  // pinMode(ECHO_PIN, INPUT);

  // Car OS
  CarOs::boot();
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);
  delay(50);
  digitalWrite(LED_BUILTIN, LOW);
  delay(50);

  CarOs::main();
}