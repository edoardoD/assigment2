#ifndef __LED__
#define __LED__
#include "Light.h"
namespace components
{
    class Led : public Light
    {
    public:
        Led(int pin);
        void switchOn();
        void switchOff();

    protected:
        int pin;
    };
} // namespace componets
#endif