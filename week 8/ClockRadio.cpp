 /*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   Class code
*   StereoRadio.h
*/

//Preprocessor assignments
#include <iostream>
#include "ClockRadio.h"
using namespace std;

ClockRadio::ClockRadio():Clock(),StereoRadio(){}

ClockRadio::ClockRadio(int theTime, double theStation):Clock(),Radio(){
    Clock(theTime), StereoRadio(theStation)
}