 /*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   Class code
*   Clock.cpp
*/

#include "Clock.h"
#include <iostream>
using namespace std;

//Scope resolution profiler --> ::
//Constructor
Clock::Clock(){
    theTime = CLOCK_DEFAULT_TIME;
}

//Constructor
Clock::Clock(int theTime){
    this->theTime = theTime;
}

int Clock::getTime(){
    return theTime;
}

void Clock::setTime(int theTime){
    this->theTime = theTime;
}

void Clock::doSomething(){
    cout << "Clock is doing something now..." << endl;
}
