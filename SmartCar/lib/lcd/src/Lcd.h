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
        virtual bool init();
        virtual void test();
        void splash();
        void printLine(char *msg, bool clearDisplay, int x, int y, int iSize);
        void printFixedCenter(lcdint_t y, char *text, EFontStyle style = STYLE_NORMAL);
    };
} // namespace Modules
#endif