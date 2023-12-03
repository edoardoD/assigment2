#include "Gateway.h"
#include "avr/sleep.h"
#include "config.h"

using namespace kernel;

Gateway::Gateway()
{
    this->pPir = new Pir(PIR_PIN);
    this->accessLight = new Led(ACCESS_LED);
    this->finishWashLed = new Led(ERROR_LED);
}
static void wakeUpNow() {}
void Gateway::sleepSys()
{
    detachInterrupt(PIR_PIN);
    Serial.println("GOING TO SLEEP");
    delay(30);
    digitalWrite(ERROR_LED, HIGH);

    set_sleep_mode(SLEEP_MODE_PWR_DOWN); // sleep mode is set here
    sleep_enable();                      // enables the sleep bit in the mcucr register
    // so sleep is possible. just a safety pin
    attachInterrupt(PIR_PIN, wakeUpNow, CHANGE); // use interrupt 0 (pin 2) and run function
    // wakeUpNow when pin 2 gets LOW
    sleep_mode(); // here the device is actually put to sleep!!
    // THE PROGRAM CONTINUES FROM HERE AFTER WAKING UP
    sleep_disable(); // first thing after waking from sleep:
    // disable sleep...
    detachInterrupt(PIR_PIN); // wakeUpNow code will not be executed
                              // during normal running time.
    /***aggiorna l'ultimo detect */
    this->setLastDetect(millis());
}

void Gateway::checkinAllowed()
{
    this->accessing = true;
}

bool Gateway::isAccessing()
{
    return this->accessing;
}

bool Gateway::detectedPresence(){
    return this->pPir->isDetected();
}
bool Gateway::isWashing(){
    return this->isWhashing;
}
void Gateway::openGate(){
    this->gate->setPosition(180);
}
void Gateway::closeGate(){
    this->gate->setPosition(0);
}
void Gateway::accessLedOff(){
    this->accessLight->switchOff();
}
void Gateway::accessLedOn(){
    this->accessLight->switchOn();
}

unsigned long Gateway::getLastDetect(){
    return this->lastDetect;
}
void Gateway::setLastDetect(unsigned long lastDetect){
    this->lastDetect = lastDetect;
}

unsigned long Gateway::getLastWash(){
    return this->lastWash;

}
void Gateway::setLastWash(unsigned long lastWash){
    this->lastWash = lastWash;
}

bool Gateway::btnPressed(){
    return this->btn->isPressed();
}
