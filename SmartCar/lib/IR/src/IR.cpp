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
        //this->irrecv->blink13(1);
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
        uint32_t value = 999999;
        if (this->irrecv->decode(&results))
        {
            this->irrecv->resume();
            if (this->results.isRepeat)
            {
                return lastValue;
            }
            else
            {
                return lastValue = this->results.value;
            }
        }
        return value;
    }
} // namespace Modules