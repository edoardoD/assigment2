#ifndef __WASHING__
#define __WASHING__

#include "kernel/Gateway.h"
using namespace kernel;

namespace task
{
    class WhashTask
    {
        Gateway *gateway;
        enum
        {
            ENTERING,
            WASHING,
            EXITING
        } state;

    public:
        WhashTask(Gateway *gateway);
        void init(int period);
        void tick();
    };
} // namespace task


