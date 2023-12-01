#ifndef __LCD__
#define __LCD__

namespace components
{
    class Lcd
    {
    public:
        Lcd();
        virtual void displayText(const char *text) = 0;
        virtual void newLine() = 0;
        virtual void clearScreen() = 0;
    };
} // namespace lcd

#endif