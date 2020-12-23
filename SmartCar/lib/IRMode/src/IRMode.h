#pragma once
#ifndef __IRMode_H__
#define __IRMode_H__

#include <stdint.h>
#include "BaseMode.h"
#include "IR.h"
#include "Engine.h"
#include "voice.h"

namespace Mode
{
    class IRMode : public Mode::BaseMode
    {
    public:
        Modules::IR *ir;
        Modules::Engine *engine;
        Modules::Voice *voice;
        const uint8_t mode = 0;

    private:
        uint32_t irData;

    public:
        IRMode(Modules::IR *ir, Modules::Engine *engine, Modules::Voice *voice);
        ~IRMode();
        virtual void run();
        virtual void stop();
        virtual void irDataRecieved(uint32_t data);
    };
} // namespace Mode
#endif