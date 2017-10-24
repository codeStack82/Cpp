 /*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   Class code
*   ClockRadio.h
*/
#pragma once

//Preprocessor assignments
#include "Clock.h"
#include "StereoRadio.h"

class ClockRadio : public Clock(), public StereoRadio(){
    public:
        ClockRadio();
        ClockRadio(int theTime, double theStation);
    
};