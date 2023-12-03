#ifndef __BLINK_TASK__
#define __BLINK_TASK__

#include "kernel/Task.h"
#include "components/led/Light.h"
#include "components/led/Led.h"
#include "kernel/Gateway.h"

using namespace kernel;
using namespace components;

namespace tasks
{
    bool blinkNow = false;
    class BlinkTask : Task
    {
        int pin;
        Gateway *gateway;
        enum
        {
            ON,
            OFF,
            DFT
        } state;

    public:
        BlinkTask(Gateway* gate);
        void init(int period);
        void tick();
    };
} // namespace 

#endif
