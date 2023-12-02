#include <Arduino.h>
#include "kernel/Task.h"
#include "kernel/Scheduler.h"
#include "components/led/Light.h"
#include "components/led/Led.h"
#include "task/led/BlinkTask.h"

using namespace kernel;
using namespace components;
using namespace tasks;


Scheduler *sched = new Scheduler();
void setup() {
  Scheduler *sched = new Scheduler();
}

void loop() {
  sched->schedule();
}

