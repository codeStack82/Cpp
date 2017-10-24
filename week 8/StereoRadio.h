 /*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   Class code
*   StereoRadio.h
*/
#pragma once

//Preprocessor assignments
#include "Radio.h"


class StereoRadio : public Radio{
    private:
        bool stereo;
    public:
        StereoRadio();
        StereoRadio(int theStation);
        void setStereo(bool = true);
        void doSomething();
};