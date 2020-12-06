#include "SerialConsole.h"
#include <Arduino.h>

SerialConsole::SerialConsole()
{
}

SerialConsole::~SerialConsole()
{
}

void SerialConsole::writeMessage(char *msg)
{
    Serial.println(msg);
}