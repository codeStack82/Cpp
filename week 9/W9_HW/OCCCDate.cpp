/*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   OCCCDate.cpp
*/

#include "OCCCDate.h"
#include <string>
#include <ctime>
#include <sstream>
#include <iostream>
 
 
using namespace std;
 
time_t timeObject;
struct tm *timeNow;
 
//OCCCDate Object: default constructor
OCCCDate:: OCCCDate()
{
    time(&timeObject);
    timeNow = localtime(&timeObject);
    dayOfMonth = timeNow ->tm_mday;
    monthOfYear = timeNow ->tm_mon + 1;
    year = timeNow ->tm_year + 1900;
 
    dateFormat = true;
}
 
 
OCCCDate::OCCCDate(int day, int month, int year){
    this->dayOfMonth = day;
    this->monthOfYear = month;
    this->year = year;
    this->dateFormat = true;
}
 
int OCCCDate::getDayOfMonth(){
    return this->dayOfMonth;
}
 
int OCCCDate::getMonth(){
    return this->monthOfYear;
}
 
int OCCCDate::getYear(){
    return this->year;
}
 
string OCCCDate::getNameOfMonth()
 
{
    switch(OCCCDate().getMonth())
    {
        case 1: 
            return "January"; 
        case 2: 
            return "Februay"; 
        case 3:
            return "March"; 
        case 4:
            return "April"; 
        case 5:
            return "May"; 
        case 6:
            return "June"; 
        case 7:
            return "July"; 
        case 8:
            return "August"; 
        case 9:
            return "September"; 
        case 10:
            return "October"; 
        case 11:
            return "November"; 
        case 12:
            return "December"; 
        default: 
            return "Error";
    }
}
 
bool OCCCDate::equals(OCCCDate d)
{
    if (d.getDayOfMonth() == dayOfMonth && d.getMonth() == monthOfYear && d.getYear() == year)
        return true;
     
    return false;
}
 
 
int OCCCDate::getDifference(OCCCDate d1)
{
    OCCCDate rightnow;
    return abs (d1.getYear() + ((d1.getMonth() - 1)/12) + (d1.getDayOfMonth()/365)) - (rightnow.getYear() +((rightnow.getMonth() - 1)/12) + (rightnow.getDayOfMonth()/365));
     
}
 
int OCCCDate::getDifference()
{
    OCCCDate rightnow;
    return abs (rightnow.getYear() +((rightnow.getMonth()-1)/12) + (rightnow.getDayOfMonth()/365)) - (getYear() + ((getMonth()-1)/12) + (getDayOfMonth()/365));
}
 
void OCCCDate::setDateFormat(bool df)
{
    this->dateFormat = df ;
     
}
 
bool OCCCDate::operator==(OCCCDate d)
{
    bool result = false;
 
    if (dayOfMonth == d.dayOfMonth && monthOfYear == d.monthOfYear && year == d.year) {
        result = true;
    }
 
    return result;
}
 
void OCCCDate::setDayOfMonth(int day)
{
    this->dayOfMonth = day;
}
 
void OCCCDate::setMonth(int month)
{
    this->monthOfYear = month;
}
 
void OCCCDate::setYear(int iyear)
{
    this->year = iyear;
}
 
 
string OCCCDate::toString()
{
     
    if (dateFormat) 
        return (to_string(this->monthOfYear) + "/" + to_string(this->dayOfMonth) + "/" + to_string(this->year));
     
    else
        return (to_string(this->dayOfMonth) + "/" + to_string(this->monthOfYear) + "/" + to_string(this->year));
}
 
 
// int main(int argc, char * argv[])
// {
//     //Create 2 date objects
//     OCCCDate d1 = OCCCDate();
//     OCCCDate d2 (20,9,1982);
 
//     cout << "** Using default OCCCDate constructor - OCCCDate() and OCCCDate.toString() functions" <<endl;
//     cout << d1.toString() << endl;
 
//     cout << "** Using amed OCCCDate constructor - OCCCDate(int, int, int) and OCCCDate.toString() functions" <<endl;
//     cout << d2.toString() << endl;
 
//     cout << "** Now Setting dateFormat(true)" << endl;
//     d2.setDateFormat(false);
//     cout << d2.toString() << endl;
// }