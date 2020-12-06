#pragma once
#ifndef __LCDCONSOLE_H__
#define __LCDCONSOLE_H__

#include "Lcd.h"
#include "BaseConsole.h"

class LcdConsole : public BaseConsole
{
private:
    Modules::Lcd *lcd;

public:
    LcdConsole(Modules::Lcd *lcd);
    ~LcdConsole();
    virtual void writeMessage(char *msg);
};

#endif