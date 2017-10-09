 /*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   Due: 10/7/17
*   Details: Tower of Hanoi
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

int[] getInputs(int argc, char * argv[]);

int main(int argc, char * argv[]){

    cout << "\n~~~~~~~~~~~~ Tower of Hanoi Homework - Advanced C++ Week 4 ~~~~~~~~~~~~" << endl;

    int[] inputs = getInputs(int argc, char * argv[]);     



    return 0;
}

int[] getInputs(int argc, char * argv[]){
    int[] inputs = new int[3];

      if(argc == 4){     
        for(int i = 1; i < argc; i++){
            inputs[i-1] = (int)argv[i]-48;
        }
    }else{
        cout << "Please, enter a number of disks: ";
        cin >> inputs[0];

        int spindle1;
        cout << "Please, enter a start spindle: ";
        cin >> inputs[1];;

        int spindle2;
        cout << "Please, enter a end spindle: ";
        cin >> inputs[2];
    }
    return inputs;
}



