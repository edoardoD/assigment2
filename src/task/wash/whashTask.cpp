#include "whashTask.h"

using namespace task;

WhashTask::WhashTask(Gateway *gateway)
{
    this->gateway = gateway;
    this->state = ENTERING;
}


WhashTask::~WhashTask()
{
}  
 
void WhashTask::init(int period)
{
    init(period);
}

void WhashTask::tick()
{
    switch (state)
    {
    case ENTERING:
        if (gateway->inWhashingArea())
        {
            gateway->startWash();
            state = WASHING;
        }
        break;
    case WASHING:
        if (gateway->isFishWashing())
        {
            state = EXITING;
            gateway->setLastWash(millis());
        }
        break;
    case EXITING:
        state = ENTERING;
        gateway->openGate();
        break;
    default:
        break;
    }
}

