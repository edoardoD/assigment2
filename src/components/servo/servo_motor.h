#ifndef __SERVO_MOTOR__
#define __SERVO_MOTOR__

namespace components
{
  class ServoMotor
  {

  public:
    virtual void on() = 0;
    virtual void setPosition(int angle) = 0;
    virtual void off() = 0;
  };
} // namespace components

#endif
