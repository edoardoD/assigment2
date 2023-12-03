#ifndef __GATWAY__
#define __GATWAY__

#include <Arduino.h>
#include "components/led/Led.h"
#include "components/proximity/Pir.h"
#include "components/servo/servo_motor.h"
#include "components/button/Button.h"

using namespace components;
namespace kernel
{
    class Gateway
    {
    public:
        Gateway();
        ~Gateway();

        bool detectedPresence();
        bool isWashing();

        void openGate();
        void closeGate();

                void accessLedOff();
        void accessLedOn();

        unsigned long getLastDetect();
        void setLastDetect(unsigned long lastDetect);

        unsigned long getLastWash();
        void setLastWash(unsigned long lastWash);
        bool btnPressed();
        void sleepSys();
        void checkinAllowed();
        bool isAccessing();

    private:
        unsigned long lastDetect;
        unsigned long lastWash;
        double carDedected;
        double isWhashing;
        double accessing;
        Led *accessLight;
        Led *errorLed;
        Led *finishWashLed;
        Pir *pPir;
        ServoMotor *gate;
        Button *btn;
    };
} // namespace kernel

#endif