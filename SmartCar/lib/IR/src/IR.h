#pragma once
#ifndef __IR_H__
#define __IR_H__

#include <stdint.h>
#include "IRremote.h"
#include "BaseModule.h"

namespace Modules
{
    class IR : public Modules::BaseModule
    {
    private:
        uint8_t ir_rcv_pin;

    public:
        IRrecv *irrecv;
        decode_results results;
        bool initialized;

    public:
        IR(uint8_t ir_rcv_pin);
        ~IR();
        virtual bool init();
        virtual void test();
        uint32_t read();
    };
} // namespace Modules
#endif