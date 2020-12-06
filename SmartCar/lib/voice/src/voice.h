#pragma once
#ifndef __VOICE_H__
#define __VOICE_H__

#include <stdint.h>
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include "BaseModule.h"
#include "OSConstants.h"

namespace Modules
{
    class Voice : public Modules::BaseModule
    {
    public:
        SoftwareSerial *mySoftwareSerial;
        DFRobotDFPlayerMini *player;
        bool initialized;

    public:
        Voice();
        ~Voice();
        virtual bool init();
        virtual void test();
    };
} // namespace Modules
#endif