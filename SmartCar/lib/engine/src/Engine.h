#pragma once
#ifndef __ENGINE_H__
#define __ENGINE_H__

#include <stdint.h>
#include "BaseModule.h"

#define FORWARD 0
#define BACKWARD 0
#define RIGHT 0
#define LEFT 0
#define FORWARD_LEFT 0
#define FORWARD_RIGHT 0
#define BACKWARD_LEFT 0
#define BACKWARD_RIGHT 0
#define STOP 0

namespace Modules
{
    class Engine : public Modules::BaseModule
    {

    private:
        int8_t ena;
        int8_t enb;
        int8_t in1;
        int8_t in2;
        int8_t in3;
        int8_t in4;

    public:
        int8_t direction;

    public:
        Engine();
        ~Engine();
        void forward(int16_t carSpeed, unsigned int period_ms = 0);
        void back(int16_t carSpeed, unsigned int period_ms = 0);
        void left(int16_t carSpeed, unsigned int period_ms = 0);
        void right(int16_t carSpeed, unsigned int period_ms = 0);
        void forwardLeft(int16_t carSpeed, unsigned int period_ms = 0);
        void forwardRight(int16_t carSpeed, unsigned int period_ms = 0);
        void backLeft(int16_t carSpeed, unsigned int period_ms = 0);
        void backRight(int16_t carSpeed, unsigned int period_ms = 0);
        void stop();
        void delayPeriod(unsigned int period_ms);
        virtual void test();
        virtual bool init();

    private:
        void setDirection(char direction);
        void accelerate(int16_t maxSpeed, int16_t aFactor = 1, int16_t bFactor = 1);
    };
} // namespace Modules
#endif