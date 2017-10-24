 /*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   Class code
*   Clock.h
*/

#pragma once

class Clock{
    private:
        static const int CLOCK_DEFAULT_TIME = 1200;
        int theTime:

    public: 
        Clock();

        Clock(int);
        int getTime();
        int setTime(int);

        void doSomething();

}; //Classes must be closed out by semi-colon
