/*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   Person.cpp
*/
#include "Person.h"
#include <iostream>
using namespace std;
 
Person::Person()
{
    firstName = "N/A";
    lastName = "N/A";
    dob = OCCCDate();
}
 
 
Person::Person(string firstName, string lastName)
{
    this->firstName = firstName;
    this->lastName = lastName;
    dob = OCCCDate();
}
 
Person::Person(string firstName, string lastName, OCCCDate dob)
{
    this -> firstName = firstName;
    this -> lastName = lastName;
    this -> dob = dob;
}
 
 
string Person::getFirstName(){
    return this->firstName;
}
 
string Person::getLastName(){
    return this->lastName;
}
 
 
void Person::setFirstName(string fname){
    this->firstName = fname;
}
void Person::setLastName(string lName){
    this->lastName = lName;
}
 
OCCCDate Person::getDate()
{
    return dob;
}
 
//getter for person's age
int Person::getAgeInYears()
{
    return dob.getDifference(); 
}
 
 
//compare a person object with another person object
bool Person::equals(Person p)
{
    bool result = false;
    string tempFirstName = firstName;
    string tempFirstName2 = p.firstName;
    string tempLastName = lastName;
    string tempLastName2 = p.lastName;
 
    for (int i = 0; i < (signed)tempFirstName.size(); i++){
        tempFirstName = toupper(tempFirstName[i]);
    }
    for (int i = 0; i < (signed)tempFirstName2.size(); i++){
        tempFirstName2 = toupper(tempFirstName2[i]);
    }
    for (int i = 0; i < (signed)tempLastName.size(); i++){
        tempLastName = toupper(tempLastName[i]);
    }
    for (int i = 0; i < (signed)tempLastName2.size(); i++){
        tempLastName2 = toupper(tempLastName2[i]);
    }
 
    if (firstName == p.firstName && lastName == p.lastName && dob.getDifference() == p.dob.getDifference()) {
        result = true;
    }
    if (tempFirstName == tempFirstName2 && tempLastName == tempLastName2 && dob.getDifference() == p.dob.getDifference()){
        result = true;
    }
     
    return result;
}
 
string Person::toString(){
  return "First name: " + this->getFirstName() + " Last name: " + this->getLastName() + "(" + getDate().toString() + ")";
}
 
 
// int main(int argc, char * argv[])
// {
//     Person p1 = Person();
//     Person p2 = Person("Tyler", "Hunt");
//     // Person p3 = Person ("Tyler", "Hunt");
 
//          //test default person constructor and toString function
//     cout << "** Person created with default constructor - Person() **" << endl;
//     cout << p1.toString() << endl << endl;
 
 
//     cout << "** Default OCCCDate constructor - OCCCDate() and Person.toString() functions" <<endl;
//     cout << p2.toString() << endl << endl;
 
// }