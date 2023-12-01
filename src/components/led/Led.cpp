#include <Arduino.h>
#include "Led.h"

using namespace components;

Led::Led(int pin)
{
    this->pin = pin;
    pinMode(pin, OUTPUT);
}
void Led::switchOn()
{
    digitalWrite(pin, HIGH);
}
void Led::switchOff()
{
    digitalWrite(pin, LOW);
};
// namespace componets