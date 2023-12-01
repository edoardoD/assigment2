#include "DisplayI2C.h"
using namespace components;

DisplayI2C::DisplayI2C(unsigned short I2CAddress, int columns, int rows, unsigned short sdaPin, unsigned short sclPin) {
    lcd = LiquidCrystal_I2C(I2CAddress, columns, rows);
    lcd.begin(columns, rows);
    lcd.clear();
}

void DisplayI2C::displayText(const char* text) {
    this->lcd.setCursor(col, row);
    lcd.print(text);
}

void DisplayI2C::newLine() {
   this->lcd.setCursor(0, ++col);
}

void DisplayI2C::clearScreen() {
    lcd.clear();
    row = 0;
    col = 0;
}
