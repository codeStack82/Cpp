 /*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   Class code
*   Radio.cpp
*/

#include "Radio.h"
#include <iostream>
using namespace std;

//Constructor
Radio::Radio(){
    this->theStation = RADIO_DEFAULT_STATION;
}

//Constructor
Radio::Radio((int theStation){
    this->theStation = theStation;
}

int Radio::getStation(){
    return theStation;
}

void Radio::setStation(int theStation){
    this->theStation = theStation;
}

void Radio::doSomething(){
    cout << "Radio is doing something now..." < ,endl;
}
