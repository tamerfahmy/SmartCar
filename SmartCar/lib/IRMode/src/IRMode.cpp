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

    void IRMode::run()
    {
        switch (this->irData)
        {
        case IR_FORWARD:
            this->voice->player->playFolder(1, 11);
            engine->forward(200);
            break;
        case IR_BACKWARD:
            this->voice->player->playFolder(1, 12);
            engine->back(200);
            break;
        case IR_LEFT:
            this->voice->player->playFolder(1, 14);
            engine->left(200);
            break;
        case IR_RIGHT:
            this->voice->player->playFolder(1, 13);
            engine->right(200);
            break;
        case IR_STOP:
            this->voice->player->playFolder(1, 15);
            engine->stop();
            break;

        default:
            break;
        }
    }

    void IRMode::stop()
    {
        engine->stop();
    }
} // namespace Mode