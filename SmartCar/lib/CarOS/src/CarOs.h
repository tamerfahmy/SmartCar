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
#include "IR.h"
#include "IRMode.h"

class CarOs
{
public:
    static Vector<Modules::BaseModule *> modules;
    static Vector<Mode::BaseMode *> modes;
    static BaseConsole *console;

    // Modules
    static Modules::Lcd *lcd;
    static Modules::Engine *carEngine;
    static Modules::Voice *voice;
    static Modules::Ultrasonic *ultrasonicArray;
    static Modules::ServoMotor *servoMotor;
    static Modules::IR *ir;

    // Modes
    static Mode::IRMode *irMode;

private:
    static uint8_t currentModeIndex;
    static Mode::BaseMode *currentMode;
    static Modules::BaseModule *modulesArray[10];
    static Mode::BaseMode *modesArray[10];

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
    static void initModes();
    static void runCarMode();
    static void switchMode(uint32_t mode);
    static uint32_t readIR();
    static double *readUltrasonic();
};
#endif