 /*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   Class code
*   Radio.h
*/

//Preprocessor assignments
#pragma once
class Radio{
private:
    static const int RADIO_DEFAULT_STATION = 1000;
    int theStation:

public: 
    Radio();

    Radio(int);
    int getStation();
    int setStation(int);

    void doSomething();
 //Classes must be closed out by semi-colon
};

