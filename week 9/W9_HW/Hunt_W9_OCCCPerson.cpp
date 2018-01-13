/*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   Hunt_W9_OCCCPerson.cpp
*/

#include <iostream>
#include "Person.h"
#include "OCCCDate.h"
#include "OCCCPerson.h"
#include <string>
#include <ctime>
 
 
// #include "OCCCPerson"
 
using namespace std;
 
 
int main(int argc, char * argv[])
{
 
    string firstName = "";
    string lastName = "";
    string studentID = "";
 
    int day = 0;
    int month = 0;
    int year = 0;
    int currentDay = 0;
    int currentMonth = 0;
    int currentYear = 0;
 
    time_t timeObject;
    struct tm *timeNow;
 
    time(&timeObject);
    timeNow = localtime(&timeObject);
 
    //• Display a friendly greeting to the user
    cout << "Hello user!" << endl;
     
    //• Prompt the user for the following information:
        //o First name
    cout << "Enter first name: ";
    cin >> firstName;
        //o Last name
    cout << "Enter last name: ";
    cin >> lastName;
        //o Birth Year
    cout << "Enter the year you were born: ";
    cin >> year;
        //o Birth Month
    cout << "Enter the month you were born: ";
    cin >> month;
        //o Birth Day
    cout << "Enter the day you were born: ";
    cin >> day;
     
    //• Create an instance of OCCCDate, d1, using the current time.
    OCCCDate d1(timeNow->tm_mday, (timeNow->tm_mon + 1), (timeNow->tm_year + 1900));
     
    //• Display that date using d1.toString()
    cout << "\nd1: " << d1.toString() << endl << endl;
     
    //• Create an instance of OCCCDate, d2, using the information provided.
    OCCCDate d2(day, month, year);
     
    //• Display that date using d2.toString()
    cout << "d2: " << d2.toString() << endl << endl;
     
    //• Prompt the user for today’s date(month, day, year).
    cout << "Enter the current month: ";
    cin >> currentMonth;
 
    cout << "Enter the current day: ";
    cin >> currentDay;
 
    cout << "Enter the current year: ";
    cin >> currentYear;
     
    //• Create an OCCCDate d3 using today’s date as provided by the user.
    OCCCDate d3(currentDay, currentMonth, currentYear);
    cout << "\nd3: " << d1.toString() << endl << endl;
 
    //• Display the results of d1 == d3 and d1.equals(d3).
    cout << "Does d1 == d3? " << (d1 == d3 ? "Yes" : "No") << endl;
    cout << "Does d1.equals(d3)? " << (d1.equals(d3)? "Yes" : "No") << endl << endl;
     
    //• Create a Person p1 using only the first and last name.
    Person p1(firstName, lastName);
    cout << "p1: " << p1.toString() << endl << endl;
     
    //• Create a Person p2 using the first name, last name, and OCCCDate d2.
    Person p2(firstName, lastName, d2);
    cout << "p2: " << p2.toString() << endl << endl;
     
    //• Display the first name, last name, and age of that person as above.
    cout << "First Name: " << p2.getFirstName() << " Last name: " << p2.getLastName() << " Age in years: " << p2.getAgeInYears() << endl << endl;
     
    //• Display the results of p1.equals(p2).
    cout << "Does p1.equals(p2)? " << (p1.equals(p2) ? "Yes" : "No") << endl << endl;
     
    //• Create a Person p3 using the same name as p1 but date d3.
    Person p3(firstName, lastName, d3);
    cout << "p3: " << p3.toString() << endl << endl;
     
    //• Display the results of p1.equals(p3).
    cout << "Does p1.equals(p3)? " << (p1.equals(p3) ? "Yes" : "No") << endl << endl;
     
    //• Prompt the user for a new last name.
    cout << "Enter new last name for p3: ";
    cin >> lastName;
     
    //• Change the last name of p3 to that provided using setLastName().
    p3.setLastName(lastName);
 
    //• Display the state of p3 using the toString() function.
    cout << "p3 last name: " << p3.getLastName() << endl << endl;
     
    //• Prompt the user for a student ID
    cout << "Enter a student ID for p4: ";
    cin >> studentID;
     
    //• Create an OCCCPerson p4 using p3 and that student ID
    OCCCPerson p4(p3, studentID);
    cout << "p4: " << p4.toString() << endl << endl;
     
    //• Create an OCCCPerson p5 using the first name, last name, d2, and the student ID
    //  (but make the first and last name in ALL CAPS)
    string tempFirstName = firstName;
    string tempLastName = lastName;
 
    for (int i = 0; i < tempFirstName.size(); i++){
        tempFirstName[i] = toupper(tempFirstName[i]);
    }
     
    for (int i = 0; i < tempLastName.size(); i++){
        tempLastName[i] = toupper(tempLastName[i]);
    }
    OCCCPerson p5(tempFirstName, tempLastName, d2, studentID);
    cout << "p5: " << p5.toString() << endl << endl;
     
    //• Display the results of p4.equals(p5)
    cout << "Does p4.equals(p5)? " << (p4.equals(p5) ? "Yes" : "No") << endl << endl;
     
    //• Create an OCCCPerson p6 by simply stating that p6 = p5.
    OCCCPerson p6 = p5;
    cout << "p6: " << p6.toString() << endl << endl;
     
    //• Display the results of p5 == p6 and p5.equals(p6).
    cout << "Does p5 == p6? " << (p5 == p6 ? "Yes" : "No") << endl;
    cout << "Does p5.equals(p6) " << (p5.equals(p6) ? "Yes" : "No") << endl << endl;
     
    //• Prompt the user for a new last name.
    cout << "Enter new last name for p6: ";
    cin >> lastName;
     
    //• Set the last name of p6 to that new last name using the setLastName() function.
    p6.setLastName(lastName);
     
    //• Display the state of both p5 and p6 using the toString() function.
    cout << "p5: " << p5.toString() << endl;
    cout << "p6: " << p6.toString() << endl << endl;
     
    //• Create an OCCCPerson p7 using p6(a copy constructor).
    OCCCPerson p7(p6);
    cout << "p7: " << p6.toString() << endl << endl;
 
    //• Display the results of p6 == p7 and p6.equals(p7).
    cout << "Does p6 == p7? " << (p6 == p7 ? "Yes" : "No") << endl;
    cout << "Does p6.equals(p7) " << (p6.equals(p7) ? "Yes" : "No") << endl << endl;
     
    //• Change the last name of p6.
    cout << "Enter new last name for p6: ";
    cin >> lastName;
    p6.setLastName(lastName);
     
    //• Display the state of p6 and p7 using the toString() function.
    cout << "p6: " << p6.toString() << endl;
    cout << "p7: " << p7.toString() << endl;
 
    return 0;
}