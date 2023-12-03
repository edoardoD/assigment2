#ifndef __CHECK_IN_TASK__
#define __CHECK_IN_TASK__


#include "kernel/Task.h"
#include "kernel/Gateway.h"
#include "components/proximity/Pir.h"

using namespace kernel;
using namespace components;

namespace tasks
{
    class CheckInTask : Task
    {
    private:
        enum
        {
            ALLOWED,
            DENIED
        } state;

        Gateway* gateway;         
    public:
        CheckInTask(Gateway *gateway);
        ~CheckInTask();
        void init(int period);
        void tick();
    };
    
    
} // namespace 



#endif