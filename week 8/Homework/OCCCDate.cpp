 /*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   OCCCDate.cpp
*/
#include "OCCCDate.h"
#include <string>
#include <ctime>

#include <iostream>
using namespace std;

// OCCCDate::OCCCDate(){
//     time_t now = time(0);
//     tm *ltm = localtime(&now);

//     this->dayOfMonth = ltm->tm_year;
//     this->monthOfYear = ltm->tm_mon;
//     this->year = ltm->tm_mday;
// }

    OCCCDate::OCCCDate(int day, int month, int year){
    this->dayOfMonth = day;
    this->monthOfYear = month;
    this->year = year;
    }

    int getDayOfMonth(){
        return this->dayOfMonth;
    }

    int getMonth(){
        return this->monthOfYear;
    }

    int getYear(){
        return year;
    }

    // string getNameOfMonth();

    // int getDifference(OCCCDate d){
    //     return d->
    // }

    // int getDifference(){

    // }
     
    // void setDateFormatt(){

    // }

    // bool equals(OCCCDate d){

    // }

    string toString(){
        return "Test OCCCDate";
    }