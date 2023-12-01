#ifndef __TEMP_SENSOR__
#define __TEMP_SENSOR__

namespace components
{
  class TempSensor
  {

  public:
    virtual float getTemperature() = 0;
  };
} // namespace

#endif
