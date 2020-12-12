#include "CarOs.h"
#include <Arduino.h>

CarOs *carOS;

void setup()
{
  // pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

  // Builtin LED configuration
  pinMode(LED_BUILTIN, OUTPUT);

  // Motor-driven port configuration
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Ultrasonic Sensor configuration
  pinMode(TRIG_PIN_S0, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Car OS
  carOS = new CarOs();
  carOS->boot();
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}