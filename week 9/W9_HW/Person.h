/*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   Person.h
*/
#pragma once
 
#include <string>
#include "OCCCDate.h"
 
using namespace std;
 
class Person{
 
protected:
    string firstName;
    string lastName;
    OCCCDate dob;
 
public: 
    Person();
    Person(string, string);
    Person(string firstName, string lastName, OCCCDate dob);
 
    string getFirstName();
    string getLastName();
    OCCCDate getDate();
    int getAgeInYears();
 
 
    void setFirstName(string);
    void setLastName(string);
    void setDate(OCCCDate dob);
 
    bool equals(Person);
    bool equalsIgnorecase(string, string);
 
    string toUpperCase(string);
    string toString();
};