#include "LcdConsole.h"

LcdConsole::LcdConsole(Modules::Lcd *lcd)
{
    this->lcd = lcd;
}

LcdConsole::~LcdConsole()
{
}

void LcdConsole::writeMessage(char *msg)
{
    this->lcd->printLine(msg, 1, 0, 0, 1);
    //obdWriteString(&obd, 0, 0, 0, msg, 2, 0, 1);
}