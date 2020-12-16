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
#include "Ultrasonic.h"
#include "ServoMotor.h"

class CarOs
{
public:
    static Vector<Modules::BaseModule *> modules;
    static BaseConsole *console;
    static Modules::Lcd *lcd;
    static Modules::Engine *carEngine;
    static Modules::Voice *voice;
    static Modules::Ultrasonic *ultrasonicArray;
    static Modules::ServoMotor *servoMotor;

private:
    static Modules::BaseModule *modulesArray[10];

public:
    static void boot();
    static void shutdown();
    static void restart();
    static void main();

private:
    static bool initConsole();
    static bool initLcd();
    static void createModulesInstances();
    static void echoCheck();
};
#endif