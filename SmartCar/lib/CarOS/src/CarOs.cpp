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
Modules::Ultrasonic *CarOs::ultrasonicArray;
Modules::ServoMotor *CarOs::servoMotor;

Modules::BaseModule *CarOs::modulesArray[10];

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

    // Create Voice
    voice = new Modules::Voice();
    modules.push_back(voice);
}

void CarOs::main()
{
    double *dist = ultrasonicArray->getDistances();
    double avgDistance = 0;
    for (uint8_t i = 0; i < 3; i++)
    {
        avgDistance += dist[i];

        Serial.print(i);
        Serial.print(":");
        Serial.println(dist[i]);
    }
    avgDistance = avgDistance / 3;
    if (avgDistance > 0 && avgDistance < 10)
    {
        carEngine->back(150);
        carEngine->stop();
        avgDistance = 0;
    }
    delay(500);
}