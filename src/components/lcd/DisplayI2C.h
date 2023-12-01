#ifndef __DISPLAY__
#define __DISPLAY__

#include <LiquidCrystal_I2C.h>
#include "Lcd.h"
#include <Arduino.h>
namespace components
{
    class DisplayI2C : public Lcd
    {

    protected:
        LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
        int row = 0, col = 0;

    public:
        DisplayI2C(unsigned short I2CAddress = 0x27, int columns = 16, int rows = 2, unsigned short sdaPin = A4, unsigned short sclPin = A5);
        virtual void displayText(const char *text);
        virtual void newLine();
        virtual void clearScreen();
    };

}

#endif