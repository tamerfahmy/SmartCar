#include <stdint.h>
#include <arduino.h>
#include "OSConstants.h"
#include "IRMode.h"

namespace Mode
{
    IRMode::IRMode(Modules::IR *ir, Modules::Engine *engine, Modules::Voice *voice)
    {
        this->engine = engine;
        this->ir = ir;
        this->voice = voice;
    }

    IRMode::~IRMode()
    {
    }

    void IRMode::irDataRecieved(uint32_t data)
    {
        this->irData = data;
    }

    void IRMode::ultrasonicRecieved(double *distances)
    {
        this->ultrasonicDistances = distances;
    }

    void IRMode::run()
    {
        switch (this->irData)
        {
        case IR_FORWARD:
        case IR_UNKNOWN_FORWARD:
            if (ultrasonicDistances[0] != -1 && ultrasonicDistances[0] < IR_AVG_DIST_THRSHOLD)
            {
                engine->stop();
                return;
            }
            else
            {
                startActionMillis = millis();
                if (engine->direction != FORWARD)
                {
                    this->voice->player->playFolder(V_SYSTEM_FOLDER, V_MOVE_FORWARD);
                    engine->forward(IR_MODE_CAR_SPEED);
                }
            }
            break;
        case IR_BACKWARD:
        case IR_UNKNOWN_BACKWARD:
            startActionMillis = millis();
            if (engine->direction != BACKWARD)
            {
                this->voice->player->playFolder(V_SYSTEM_FOLDER, V_MOVE_BACKWARD);
                engine->back(IR_MODE_CAR_SPEED);
            }
            break;
        case IR_RIGHT:
        case IR_UNKNOWN_RIGHT:
            startActionMillis = millis();
            if (engine->direction != RIGHT)
            {
                this->voice->player->playFolder(V_SYSTEM_FOLDER, V_MOVE_RIGHT);
                engine->right(IR_MODE_CAR_SPEED);
            }
            break;
        case IR_LEFT:
        case IR_UNKNOWN_LEFT:
            startActionMillis = millis();
            if (engine->direction != LEFT)
            {
                this->voice->player->playFolder(V_SYSTEM_FOLDER, V_MOVE_LEFT);
                engine->left(IR_MODE_CAR_SPEED);
            }
            break;
        case IR_STOP:
        case IR_UNKNOWN_STOP:
            this->voice->player->playFolder(V_SYSTEM_FOLDER, V_STOP);
            engine->stop();
            break;

        default:
            break;
        }

        if (startActionMillis < millis() - IR_KEY_HOLD_TIMEOUT)
        {
            engine->stop();
        }
    }

    void IRMode::stop()
    {
        engine->stop();
    }
} // namespace Mode