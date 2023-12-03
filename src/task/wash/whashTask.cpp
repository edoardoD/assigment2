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
    
}

