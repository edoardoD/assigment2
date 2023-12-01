#include "ButtonImpl.h"
#include "Arduino.h"

using namespace components;

ButtonImpl::ButtonImpl(int pin){
  this->pin = pin;
  pinMode(pin, INPUT);     
} 
  
bool ButtonImpl::isPressed(){
  return digitalRead(pin) == HIGH;
}


