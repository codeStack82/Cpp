 /*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   Class code
*   StereoRadio.h
*/

//Preprocessor assignments
#include <iostream>
#include "StereoRadio.h"
using namespace std;

StereoRadio::StereoRadio():Radio(){
    stereo = false;
}

StereoRadio::StereoRadio(double theStation):Radio(){ //:Radio is the call to the parent class Radio() 
    stereo = false;
}

void StereoRadio::setStereo(bool stereo){
    this->stereo = stereo;
}

void StereoRadio::doSomething(){
    cout  << "Stereo Radio is doign something" << endl;
}

