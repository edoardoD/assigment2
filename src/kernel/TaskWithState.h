#ifndef __TASK_WITH_STATE__
#define __TASK_WITH_STATE__

#include "Task.h"
namespace kernel
{
  class TaskWithState : public Task
  {

  public:
    TaskWithState() : Task()
    {
    }

    void setState(int s)
    {
      state = s;
      stateTimestamp = millis();
    }

    long elapsedTimeInState()
    {
      return millis() - stateTimestamp;
    }

  private:
    int state;
    long stateTimestamp;
  };
}
#endif
