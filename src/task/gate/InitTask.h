
#ifndef __INIT_TASK__
#define __INIT_TASK__

#include "kernel/Task.h"
#include "kernel/Gateway.h"
#include "components/proximity/Pir.h"
using namespace kernel;
using namespace components;

namespace tasks
{
    class InitTask : Task
    {
    private:
        enum
        {
            DETECTING,
            SLEEPING
        } state;
        Gateway* gateway;
        void sleepNow(){}
    public:
        InitTask(Gateway* gateway);
        ~InitTask();
        void init(int period);
        void tick();
    };
    
};

#endif