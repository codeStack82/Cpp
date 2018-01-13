/*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   Hunt_W8_HW.cpp
*/
#include <iostream>
#include "Person.h"
#include "OCCCDate.h"
 
using namespace std;
 
 
int main(int argc, char * argv[]){
 
    cout << "Hello World" << endl;
 
     //Create 2 date objects
    OCCCDate d1 = OCCCDate();
    OCCCDate d2 (20,9,1982);
 
    //Test Person
    Person p1 = Person();
    Person p2 = Person("Tyler", "Hunt");
    Person p3 = Person ("Tyler", "Hunt", d2);
 
 //    //test OCCCDate def constructor
    cout << "** OCCCDate constructed with default constructor **" << endl;
    cout << d1.toString() << endl << endl;
 
    //test setDateFormat and toString function
    cout << "Implementation of OCCCDate.setDateFormat() and OCCCDate.toString() functions:" << endl;
    d1.setDateFormat(true);
    cout << d1.toString() << endl;
 
     
    //test default person constructor and toString function
    cout << "** Person created with default constructor - Person() **" << endl;
    cout << p1.toString() << endl << endl;
 
    cout << "default OCCCDate constructor - OCCCDate() and Person.toString() functions" <<endl;
    cout << p1.toString() << endl;
 
    return EXIT_SUCCESS;
}