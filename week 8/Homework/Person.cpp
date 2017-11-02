 /*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   Person.cpp
*/
#include "Person.h"
#include <string>
#include <iostream>
using namespace std;

Person::Person(string firstName, string lastName){
    this->firstName = firstName;
    this->lastName = lastName;
}

// Person::Person(string firstName, string lastName, OCCCDate d){
//     this->firstName = firstName;
//     this->lastName - lastName;
//     this->dob = dob;
// }

    string getFirstName(){
        return this->firstName;
    }

    string getLastName(){
        return this->lastName;
    }

    //TODO: need to update OCCCDate info
    // OCCCDate getDate();
    // int getYearsInAge(){
    //     return this->
    // }

    void setFirstName(string fname){
        this->firstName = fname;
    }
    void setLastName(string lName){
        this->lastName = lName;
    }

    // bool equals(Person P);
    // bool equalsIgnorecase(string s1, string s2);

    // string toUpperCase(string s);
    string toString(){
      return "First name: " + this->firstName->getFirstName() + " Last name: " + this->lastName->getLastName();
    }