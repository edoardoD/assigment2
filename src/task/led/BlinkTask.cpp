#include "task/led/BlinkTask.h"

using namespace tasks;

BlinkTask::BlinkTask(Gateway* gateway)
{
    this->gateway = gateway;
}

void BlinkTask::init(int period)
{
    Task::init(period);
    
    state = OFF;
}
/**ad ogni giro il task valuta se deve eseguire il blink o meno
 * 
*/
void BlinkTask::tick()
{
    if (gateway->isAccessing())
    {
        switch (state)
        {
        case OFF:
            gateway->accessLedOff();
            state = ON;
            break;
        case ON:
            gateway->accessLedOn();
            state = OFF;
            break;
        }
    }
}