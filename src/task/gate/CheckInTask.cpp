#include "CheckInTask.h"
#include "kernel/config.h"

using namespace tasks;

CheckInTask::CheckInTask(Gateway *gateway)
{
    this->gateway = gateway;
}

void CheckInTask::init(int period)
{
    Task::init(period);
    state = DENIED;
    
}

void CheckInTask::tick()
{
    switch (state)
    {
    case DENIED:
        if (gateway->getLastDetect() + T1 >= millis() && !gateway->isWashing())
        {
            state = ALLOWED;
            gateway->checkinAllowed();
        }
        break;
    case ALLOWED:
        if (gateway->isWashing())
        {
            state = DENIED;
        }
        break;
    
    default:
        break;
    }
    
}