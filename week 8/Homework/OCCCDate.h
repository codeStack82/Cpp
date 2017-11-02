 /*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   OCCCDate.h
*/

#ifndef OCCCDATE_H
#define OCCCDATE_H

#include <string>
#include <iostream>
using namespace std;

//Preprocessor assignments
// #pragma once

class OCCCDate{
    private:
        int dayOfMonth;
        int monthOfYear;
        int year;
        bool dateFormat;

    public: 
        // OCCCDate(); 
        OCCCDate(int, int, int);

        int getDayOfMonth();
        int getMonth();
        int getYear();
        // string getNameOfMonth();
        // int getDifference(OCCCDate d);
        // int getDifference();

        // void setDateFormatt();
        // bool equals(OCCCDate d);
        string toString();
};

#endif  
