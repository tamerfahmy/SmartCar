#include <stdint.h>
#include <arduino.h>
#include "CarOs.h"
#include "Ultilities.h"
#include "OSConstants.h"
#include "LcdConsole.h"
#include "SerialConsole.h"
#include <Vector.h>

// Public
Vector<Modules::BaseModule *> CarOs::modules;
Vector<Mode::BaseMode *> CarOs::modes;
BaseConsole *CarOs::console;

// Modules
Modules::Lcd *CarOs::lcd;
Modules::Engine *CarOs::carEngine;
Modules::Voice *CarOs::voice;
Modules::Ultrasonic *CarOs::ultrasonicArray;
Modules::ServoMotor *CarOs::servoMotor;
Modules::IR *CarOs::ir;

// Modes
Mode::IRMode *CarOs::irMode;

// Private
Modules::BaseModule *CarOs::modulesArray[10];
Mode::BaseMode *CarOs::modesArray[10];
Mode::BaseMode *CarOs::currentMode;
uint8_t CarOs::currentModeIndex = 10;

void CarOs::boot()
{
    // Builtin LED configuration
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);

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
    lcd->printFixedCenter(24, "READY", STYLE_BOLD);
    voice->player->playFolder(V_SYSTEM_FOLDER, V_READY);
    delay(1000);

    initModes();
    switchMode(CAR_DEFAULT_MODE);
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

    // Create Engine
    carEngine = new Modules::Engine();
    modules.push_back(carEngine);

    // Create Ultrasonic array
    uint8_t ultrasonicSensorsTriggerPins[U_NUMBER_OF_SENSORS] = {U_TRIG_PIN_S0, U_TRIG_PIN_S1, U_TRIG_PIN_S2};
    ultrasonicArray = new Modules::Ultrasonic(ultrasonicSensorsTriggerPins, U_ECHO_PIN, U_NUMBER_OF_SENSORS);
    modules.push_back(ultrasonicArray);

    // Create Servo
    servoMotor = new Modules::ServoMotor(SERVO_PIN, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE);
    modules.push_back(servoMotor);

    // Create IR
    ir = new Modules::IR(IR_PIN);
    modules.push_back(ir);

    // Create Voice
    voice = new Modules::Voice();
    modules.push_back(voice);
}

void CarOs::initModes()
{
    modes.setStorage(modesArray, 0);

    irMode = new Mode::IRMode(ir, carEngine, voice);
    modes.push_back(irMode);

    Mode::IRMode *irMode1 = new Mode::IRMode(ir, carEngine, voice);
    modes.push_back(irMode1);

    Mode::IRMode *irMode2 = new Mode::IRMode(ir, carEngine, voice);
    modes.push_back(irMode2);
}

void CarOs::switchMode(uint32_t mode)
{
    switch (mode)
    {
    case CAR_IR_MODE_KEY:
        if (currentModeIndex != 0)
        {
            currentModeIndex = 0;
            modes.at(currentModeIndex)->stop();
            lcd->display->clear();
            lcd->printFixedCenter(24, "IR Mode", STYLE_NORMAL);
            voice->player->playFolder(V_SYSTEM_FOLDER, V_IR_MODE);
            delay(1000);
        }
        break;
    case CAR_BLUETOOTH_MODE_KEY:
        if (currentModeIndex != 1)
        {
            currentModeIndex = 1;
            modes.at(currentModeIndex)->stop();
            lcd->display->clear();
            lcd->printFixedCenter(24, "Bluetooth Mode", STYLE_NORMAL);
            voice->player->playFolder(V_SYSTEM_FOLDER, V_BLUETOOTH_MODE);
            delay(1000);
        }
        break;
    case CAR_AUTO_MODE_KEY:
        if (currentModeIndex != 2)
        {
            currentModeIndex = 2;
            modes.at(currentModeIndex)->stop();
            lcd->display->clear();
            lcd->printFixedCenter(24, "Auto Mode", STYLE_NORMAL);
            voice->player->playFolder(V_SYSTEM_FOLDER, V_AUTO_MODE);
            delay(1000);
        }
        break;
    case CAR_LINE_MODE_KEY:
        if (currentModeIndex != 3)
        {
            currentModeIndex = 3;
            modes.at(currentModeIndex)->stop();
            lcd->display->clear();
            lcd->printFixedCenter(22, "Line Tracking Mode", STYLE_NORMAL);
            voice->player->playFolder(V_SYSTEM_FOLDER, V_LINE_TRACKING_MODE);
            delay(2000);
        }
        break;

    default:
        break;
    }
}

void CarOs::runCarMode()
{
    uint32_t data = readIR();
    switchMode(data);
    double *distances = readUltrasonic();
    modes.at(currentModeIndex)->run();
}

uint32_t CarOs::readIR()
{
    uint32_t data = ir->read();
    for (auto &mode : modes)
    {
        mode->irDataRecieved(data);
    }
    return data;
}

double *CarOs::readUltrasonic()
{
    double *distances = ultrasonicArray->getDistances(U_TEMPRTURE);
    for (auto &mode : modes)
    {
        mode->ultrasonicRecieved(distances);
    }
    return distances;
}

void CarOs::main()
{
    runCarMode();
}