#ifndef __CHECK_IN_TASK__
#define __CHECK_IN_TASK__


#include "kernel/Task.h"
#include "components/proximity/Pir.h"

using namespace kernel;
using namespace components;

namespace tasks
{
    class CheckInTask : Task
    {
    private:
        
        
    public:
        CheckInTask(/* args */);
        ~CheckInTask();
    };
    
    CheckInTask::CheckInTask(/* args */)
    {
    }
    
    CheckInTask::~CheckInTask()
    {
    }
    
} // namespace 



#endif