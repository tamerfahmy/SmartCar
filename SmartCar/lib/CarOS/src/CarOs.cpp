#include <stdint.h>
#include <arduino.h>
#include "CarOs.h"
#include "OSConstants.h"
#include "LcdConsole.h"
#include "SerialConsole.h"
#include <Vector.h>

CarOs::CarOs()
{
}

CarOs::~CarOs()
{
}

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

    voice = new Modules::Voice();
    modules.push_back(voice);
}