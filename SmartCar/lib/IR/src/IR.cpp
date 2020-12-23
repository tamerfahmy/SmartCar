#include <stdint.h>
#include <arduino.h>
#include "IR.h"

namespace Modules
{
    IR::IR(uint8_t ir_rcv_pin)
    {
        this->ir_rcv_pin = ir_rcv_pin;
    }

    IR::~IR()
    {
        this->irrecv->disableIRIn();
        delete this->irrecv;
    }

    bool IR::init()
    {
        this->irrecv = new IRrecv(this->ir_rcv_pin);
        this->irrecv->enableIRIn();
        return initialized = true;
    }

    void IR::test()
    {
        if (!initialized)
            Serial.println("Failed initializing IR");
    }

    /**
     * Returns the IR code otherwise 999999
     */
    uint32_t IR::read()
    {
        if (this->irrecv->decode(&results))
        {
            this->irrecv->resume();
            uint32_t value = this->results.value;
            return value;
        }
        return 999999;
    }
} // namespace Modules