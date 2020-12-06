#pragma once
#ifndef __SERIALCONSOLE_H__
#define __SERIALCONSOLE_H__
#include "BaseConsole.h"

class SerialConsole : public BaseConsole
{
public:
    SerialConsole();
    ~SerialConsole();
    virtual void writeMessage(char *msg);
}; // namespace OS

#endif