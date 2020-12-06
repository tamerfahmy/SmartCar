#pragma once
#ifndef __CAR_OS_H__
#define __CAR_OS_H__

#include "BaseConsole.h"
#include "SerialConsole.h"
#include "LcdConsole.h"
#include "BaseModule.h"
#include "Vector.h"
#include "Engine.h"
#include "lcd.h"
#include "voice.h"

class CarOs
{
public:
    Vector<Modules::BaseModule *> modules;
    BaseConsole *console;
    Modules::Lcd *lcd;
    Modules::Engine *carEngine;
    Modules::Voice *voice;

private:
    Modules::BaseModule *modulesArray[10];

public:
    CarOs();
    ~CarOs();

    void boot();
    void shutdown();
    void restart();

private:
    bool initConsole();
    bool initLcd();
    void createModulesInstances();
};
#endif