#include "InitTask.h"
#include "kernel/config.h"

using namespace tasks;

InitTask::InitTask(Gateway *gateway)
{
    this->gateway = gateway;
}

void InitTask::init(int period)
{
    Task::init(period);
    state = DETECTING;
}



void InitTask::tick()
{
    switch (state)
    {
    case DETECTING:

        if (gateway->detectedPresence())
        {
            gateway->setLastDetect(millis());
            gateway->accessLedOn();
        }
        if (gateway->getLastDetect() + T0 < millis() && !gateway->isWashing())
        {
            state = SLEEPING;
        }

        break;
    case SLEEPING:
        
            gateway->sleepSys();
            state = DETECTING;

        
        break;
    }
}
