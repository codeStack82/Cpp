/*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   OCCCPerson.h
*/

#pragma once
 
#include <string>
#include "Person.h"
 
class OCCCPerson: public Person
{
    protected:
        string studentID;
 
    public:
         
        OCCCPerson();
        OCCCPerson(string firstName, string lastName, OCCCDate dob, string id);
        OCCCPerson(Person person, string id);
        OCCCPerson(OCCCPerson &occcP);
 
        string getStudentID();
        string toString();
        bool equals(OCCCPerson p); 
 
        bool operator==(OCCCPerson occcP);
 
        OCCCPerson& operator=( OCCCPerson& rhs );
};