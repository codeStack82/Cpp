 /*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   Week 8 - Homework
*/

// #include "Person.h"
#include "OCCCDate.h"
#include <iostream>
using namespace std;


int main(int argc, char * argv[]){

    //Test Person
    // Person p = Person("Tyler", "Hunt");
    // string test = p.toString();
    // cout << test << endl;

    //Test OCCCDate
    OCCCDate d = new OCCCDate(20,9,1982);
    cout << d.getMonth() << endl;


    return EXIT_SUCCESS;
}