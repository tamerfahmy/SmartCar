#include <stdint.h>
#include <arduino.h>
#include "CarOs.h"
#include "OSConstants.h"
#include "LcdConsole.h"
#include "SerialConsole.h"
#include <Vector.h>

// Public
Vector<Modules::BaseModule *> CarOs::modules;
BaseConsole *CarOs::console;
Modules::Lcd *CarOs::lcd;
Modules::Engine *CarOs::carEngine;
Modules::Voice *CarOs::voice;
Modules::Ultrasonic *CarOs::buttomUltrasonicSensor;
Modules::Ultrasonic *CarOs::topRightUltrasonicSensor;
Modules::Ultrasonic *CarOs::topLeftUltrasonicSensor;

// Private
Modules::BaseModule *CarOs::modulesArray[10];

void CarOs::boot()
{
    // initialize OS Console
    initConsole();
    initLcd();

    // Show loading window
    lcd->display->drawWindow(0, 0, 0, 0, "CAR OS", true);
    size_t progress = 0;
    lcd->display->drawProgressBar(progress);
    createModulesInstances();
    size_t maxSteps = modules.size() + 1; // +1, To add the create modules instances steps
    progress += 100 / maxSteps;
    lcd->display->drawProgressBar(progress);

    for (auto &module : modules)
    {
        module->init();
        module->test();
        progress += 100 / maxSteps;
        lcd->display->drawProgressBar(progress);
        lcd_delay(20);
    }

    modules.push_back(lcd);

    lcd->display->clear();
    lcd->display->printFixed(40, 22, "READY", STYLE_BOLD);
}

bool CarOs::initConsole()
{
    if (lcd->initialized)
        console = new LcdConsole(lcd);
    else
        console = new SerialConsole();

    console->writeMessage((char *)"message");

    return true;
}

bool CarOs::initLcd()
{
    lcd = new Modules::Lcd();
    return lcd->init();
}

void CarOs::createModulesInstances()
{
    modules.setStorage(modulesArray, 0);

    carEngine = new Modules::Engine();
    modules.push_back(carEngine);

    buttomUltrasonicSensor = new Modules::Ultrasonic(TRIG_PIN_S0, ECHO_PIN, U_BUTTOM);
    modules.push_back(buttomUltrasonicSensor);

    // topLeftUltrasonicSensor = new Modules::Ultrasonic(TRIG_PIN_S1, ECHO_PIN, U_TOP_LEFT);
    // modules.push_back(topLeftUltrasonicSensor);

    // topRightUltrasonicSensor = new Modules::Ultrasonic(TRIG_PIN_S2, ECHO_PIN, U_TOP_RIGHT);
    // modules.push_back(topRightUltrasonicSensor);

    voice = new Modules::Voice();
    modules.push_back(voice);
}

void CarOs::main()
{
    Serial.println(buttomUltrasonicSensor->getDistance());
    delay(500);
}