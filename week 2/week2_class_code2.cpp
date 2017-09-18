 /*
* Tyler Hunt
* Advanved C++
* OCCC Fall 2017
* Class code examples
*/
//Notes:    // C++ has a singe pass compiler
			// Java has a double pass compiler
			// C++ does not know the size of its array so u must send it's size'

#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <exception>
#include <vector>
using namespace std;

//Prototype functions
void randomizeArray(int theArray [], int size );
void displayArray(const int theArray [], int size);
void zeroArray(int theArray [], int size);
void copyArray(const int sourceArray [], int tempArray [], int size);

int main(){
	//Seed array
	srand((unsigned) time(0));

	//Intro message
	cout << "Welcome to Array Demo!" << endl;
	cout << "Please enter array size: ";

	//Get input 
	int s;
	cin >> s;

	//Create array  
	int * theArray = new int [s];
	displayArray(theArray, s);

    //int count = 8;
    int * tempArray;

	s = 100;
	while(true){
        tempArray = new int[s*2];
		zeroArray(tempArray, s);
		copyArray(theArray, tempArray, s);
		delete [] theArray;
		theArray = tempArray;
		s *= 2;
		cout << "count is " << s << endl;
	}
    //displayArray(theArray,s);

	return 0; //default successful execution
}

//Display Array function
void displayArray(const int theArray [], int theArraySize){
	cout << endl;
	for(int i = 0; i < theArraySize; ++i){
		if(i%10 == 0){
			cout << endl;
		}
		cout << setw(7) << theArray[i];
	}
	cout << endl;
	cout << endl;
}

void randomizeArray(int theArray [], int theArraySize){
	for(int i = 0; i < theArraySize; ++i){
	   theArray[i] = rand()%1000;
		}
}

void zeroArray(int theArray [], int theArraySize){
	for(int i = 0; i < theArraySize; ++i){
	   theArray[i] = 0;
		}
}

void copyArray(int sourceArray [], int destination [], int theArraySize, int s){
	//copies first 'size' elements from sourceArray to detination
	//destination array must be atleast as large as the source array
    for(int i = 0; i < theArraySize; ++i){
        destination[i] = sourceArray[i];
    }
}