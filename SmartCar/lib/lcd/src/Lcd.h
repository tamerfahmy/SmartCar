#pragma once
#ifndef __LCD_H__
#define __LCD_H__

#include <stdint.h>
#include "lcdgfx.h"
#include "BaseModule.h"

namespace Modules
{
    class Lcd : public Modules::BaseModule
    {
    public:
        DisplaySSD1306_128x64_I2C *display;
        bool initialized;

    public:
        Lcd();
        ~Lcd();
        void splash();
        void printLine(char *msg, bool clearDisplay, int x, int y, int iSize);
        virtual bool init();
        virtual void test();
    };
} // namespace Modules
#endif