 /*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   Due: 10/15/17
*   Details: Simple Sorts Homework
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <regex>

using namespace std;


int main(int argc, char * argv[]){

    cout << "\n~~~~~~~~~~~~ Simple Sorts Homework - Advanced C++ Week 5 ~~~~~~~~~~~~" << endl;

    string fileName;   //string to hold the file name

    //Test if file name was added to the cmd line
    if(argc >= 2){     
       fileName = argv[1];
       cout << "The file name you entered is: " << fileName << endl;;
    }else{
        cout << "Please, enter a file name: ";
        getline(cin, fileName);
        cout << "The file name you entered is: " << fileName << endl;;
    }


    return EXIT_SUCCESS;      
}
