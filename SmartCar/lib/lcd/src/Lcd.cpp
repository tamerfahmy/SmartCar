#include <stdint.h>
#include <arduino.h>
#include "OSConstants.h"
#include "Lcd.h"

namespace Modules
{
    Lcd::Lcd()
    {
    }

    Lcd::~Lcd()
    {
    }

    bool Lcd::init()
    {
        display = new DisplaySSD1306_128x64_I2C(-1);
        display->begin();
        display->clear();
        if (FLIP_SCREEN)
        {
            display->getInterface().flipHorizontal(1);
            display->getInterface().flipVertical(1);
        }
        display->invertColors();
        display->fill(0x00);
        display->setFixedFont(ssd1306xled_font8x16);
        initialized = true;

        // Show the splash screen
        splash();
        return initialized;
    }

    void Lcd::test()
    {
        if (!initialized)
            Serial.println("Failed initializing Lcd");
    }

    void Lcd::splash()
    {
        if (initialized)
        {
            display->printFixed(40, 22, "CAR OS", STYLE_BOLD);
            display->printFixed(45, 35, CAR_OS_VERSION, STYLE_NORMAL);
            delay(2000);
        }
    }

    void Lcd::printFixedCenter(lcdint_t y, char *text, EFontStyle style)
    {
        lcduint_t x = (128 - display->getFont().getTextSize(text)) / 2;
        if (x < 0)
            x = 0;
        display->printFixed(x, y, text, style);
    }
    
    void Lcd::printLine(char *msg, bool clearDisplay, int x, int y, int iSize)
    {
        // if (clearDisplay)
        //     obdFill(&obd, 0, 1);

        // obdSetCursor(&obd, x, y);
        // obdWriteString(&obd, 0, 0, 0, msg, iSize, 0, 1);
    }
} // namespace Modules