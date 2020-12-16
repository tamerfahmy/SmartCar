//#include "CarOs.h"
#include <Arduino.h>
//#include "OS.h"
#include "CarOs.h"

//CarOs *carOS;

void setup()
{
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