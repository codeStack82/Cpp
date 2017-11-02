 /*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   Person.h
*/
// #ifndef PERSON_H
// #define PERSON_H
#include <string>
using namespace std;

//Preprocessor assignments
// #pragma 
#ifndef PERSON_H
#define PERSON_H

class Person{
private:
    string firstName;
    string lastName;
    // OCCCDate dob;

public: 
    Person(string, string);
    // Person(string firstName, string lastName, OCCCDate dob);

    string getFirstName();
    string getLastName();
    // OCCCDate getDate();
    int getYearsInAge();

    void setFirstName(string);
    void setLastName(string);

    bool equals(Person);
    bool equalsIgnorecase(string, string);

    string toUpperCase(string);
    string toString();
};

#endif  
