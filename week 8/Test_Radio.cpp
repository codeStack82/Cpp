 /*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   Class code
*   Test_Radio.cpp
*/


#include "Clock.h"
#include <iostream>
using namespace std;

int main(){
    Radio c1 = Radio();
    Radio c2(1000);
    Radio *c3 = new Radio();
    Radio c4 = Radio(100);
    Radio c5;

    cout << "Radio 1 station: " << c1.getStation() << endl;
    cout << "Radio 2 station: " << c2.getStation() << endl;
    cout << "Radio 3 station: " << c3->getStation() << endl;
    cout << "Radio 4 station: " << c4.getStation() << endl;
    cout << "Radio 5 station: " << c5.getStation() << endl;


    return 0;
}