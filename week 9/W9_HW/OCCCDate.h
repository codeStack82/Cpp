/*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   OCCCDate.h
*/

#pragma once
 
#include <string>
#include <iostream>
 
using namespace std;
 
class OCCCDate{
 
    private:
        int dayOfMonth;
        int monthOfYear;
        int year;
        bool dateFormat;
 
    public: 
 
        OCCCDate(); 
        OCCCDate(int, int, int);
 
        int getDayOfMonth();
        int getMonth();
        int getYear();
 
        void setDayOfMonth(int day);
        void setMonth(int month);
        void setYear(int year);
 
 
        string getNameOfMonth();
 
        int getDifference(OCCCDate d);
        int getDifference();
 
        void setDateFormat(bool df);
        bool equals(OCCCDate d);
        string toString();
 
        bool operator==(OCCCDate d);
};