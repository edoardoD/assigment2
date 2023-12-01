#ifndef __LIGHT__
#define __LIGHT__
namespace components
{
    class Light
    {
    public:
        virtual void switchOn() = 0;
        virtual void switchOff() = 0;
    };
} // namespace componets
#endif