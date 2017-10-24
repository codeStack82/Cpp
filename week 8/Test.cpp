 /*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   Class code
*   Test.cpp
*/


#include "Clock.h"
#include "Radio.h"
#include "StereoRadio.h"
#include <iostream>
using namespace std;

int main(){
    Clock c1 = Clock();
    Clock c2(1000);
    Clock *c3 = new Clock();
    Clock c4 = Clock(100);
    Clock c5;

    cout << "Clock 1 time: " << c1.getTime()  << endl;
    cout << "Clock 2 time: " << c2.getTime()  << endl;
    cout << "Clock 3 time: " << c3->getTime() << endl;
    cout << "Clock 4 time: " << c4.getTime()  << endl;
    cout << "Clock 5 time: " << c5.getTime()  << endl;

    Radio r1 = Radio();
    Radio r2(100);

    cout << "Radio 1 station: " << r1.getStation() << endl;
    cout << "Radio 2 station: " << c2.getStation() << endl;

    StereoRadio sr1 = StereoRadio();
    StereoRadio sr2 - StereoRadio(1234);

    cout << "Radio 1 station: " << sr1.getStation() << endl;
    cout << "Radio 2 station: " << sr2.getStation() << endl;

    return 0;
}