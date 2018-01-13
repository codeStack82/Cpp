/*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   OCCCPerson.cpp
*/

#include "OCCCPerson.h"
#include "Person.h"
 
 
OCCCPerson::OCCCPerson() : Person(){}
 
OCCCPerson::OCCCPerson(string firstName, string lastName, OCCCDate dob, string id) : Person(){
    studentID = id;
    setFirstName(firstName);
    setLastName(lastName);
    this->dob = dob;
}
 
OCCCPerson::OCCCPerson(Person person, string id) : Person(){
    setFirstName(person.getFirstName());
    setLastName(person.getLastName());
    studentID = id;
    this->dob = person.getDate();
}
 
OCCCPerson::OCCCPerson(OCCCPerson &occcP) : studentID(occcP.studentID), Person() {
    firstName = occcP.getFirstName();
    lastName = occcP.getLastName();
    this->dob = occcP.getDate();
}
 
 
string OCCCPerson::getStudentID()
{
    return this->studentID;
}
 
string OCCCPerson::toString()
{
  return this->getLastName() + ", " + this->getFirstName() + "(" + getDate().toString() + ") [" + this->studentID + "]";
}
 
bool icompare_pred(unsigned char a, unsigned char b)
{
    return std::tolower(a) == std::tolower(b);
}
 
bool icompare(std::string const& a, std::string const& b)
{
    if (a.length()==b.length()) {
        return std::equal(b.begin(), b.end(),
                           a.begin(), icompare_pred);
    }
    else {
        return false;
    }
}
 
bool OCCCPerson::operator==(OCCCPerson occcP){
        return equals(occcP);
}
 
 
OCCCPerson &OCCCPerson::operator=( OCCCPerson& rhs )
{
    this->studentID = rhs.getStudentID();
    this->setFirstName(rhs.getFirstName()); 
    this->setLastName(rhs.getLastName());
    this->getDate().setDayOfMonth(rhs.getDate().getDayOfMonth());
    this->getDate().setMonth(rhs.getDate().getMonth());
    this->getDate().setYear(rhs.getDate().getYear());

    return *this;
}
 

//case insensitive
bool OCCCPerson::equals(OCCCPerson p)
{
    if(!icompare(this->getFirstName(), p.getFirstName()))
        return false;
 
    if(!icompare(this->getLastName(), p.getLastName()))
        return false;
 
    if(!this->getDate().equals(p.getDate()))
        return false;
 
    if(this->getStudentID() != p.getStudentID() )
        return false;
 
    return true;
 
}