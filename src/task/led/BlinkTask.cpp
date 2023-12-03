#include "task/led/BlinkTask.h"

using namespace tasks;

BlinkTask::BlinkTask(Gateway *gateway)
{
    this->gateway = gateway;
}

void BlinkTask::init(int period)
{
    Task::init(period);

    state = DFT;
}
/**ad ogni giro il task valuta se deve eseguire il blink o meno
 *
 */
void BlinkTask::tick()
{

    switch (state)
    {
    case DFT:
        if (gateway->isAccessing())
        {
            state = OFF;
        }
       
        break;
    case OFF:
        if (gateway->isAccessing())
        {
            gateway->accessLedOff();
            state = ON;
        }
        else
        {
            state = DFT;
        }
        
        break;
    case ON:
        if (gateway->isAccessing())
        {
            gateway->accessLedOn();
            state = OFF;
        }
        else
        {
            state = DFT;
        }
        break;
    }
}