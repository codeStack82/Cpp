/*
* Tyler Hunt
* Advanved C++
* OCCC Fall 2017
* Assignment 1
* Due: 8/28/17
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <exception>
#include <vector>

using namespace std;

//Function Prototypes
void introMessage();

bool isCMD(int params);

// string [] getManualInput();

// string [] getParams(String [] params);

//Main
int main(int argc, char** argv)
{
    introMessage();
    bool hasCMD = isCMD(argc);
    cout << hasCMD << endl;
    cout << argc << endl;

    return 0;
}

void introMessage(){
    cout << "\nHello, World!" << endl;
}

bool isCMD(int count){
    //Contract
        // @Notes:  Check if user entered cmd inputs
        // @params  param(argc)
        // @return  boolean 
        // assert(int count);

    bool isValid = (count == 0 )? isValid = true: false;
    return isValid;
}
     








// string [] getManualInput(){
//     //TODO: build out for user input
// }

// String [] getParams(int count, String [] params){
//     //Contract
//         // note:    check if user entered cmd inputs
//         // @params  param(argc)
//         // @return  array 

//         bool is_CMD = isCMD(count);

//         // if(is_CMD){
//         //     return params;
//         // }else{
//         //     //TODO: get input manually from propmt
//         //     return params;
//         // }

// }
