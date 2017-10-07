/*
* Tyler Hunt
* Advanved C++
* OCCC Fall 2017
* Class Demo Code: 10/2/17
*/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

void displayArray(int * theArray, int theArraySize);
void randomizeArray(int* a, int s,int m);
void exchange(int & a, int & b);
bool inOrder(int a , int b);
void exchangeSort(int * a, int s);
void insertionSort(int * a, int f, int l); // from first to last - 1
void insertionSort(int * a, int s); // call the internal array;
void copyArray(int * source, int * destination; int size);
    // Example call
    // insertionSort(a,s){
    //     insertionSort(a,o,s);
    // };

//Global variables
int excahngeCounter;
int comparrisonCounter;

int main(){
    //srand((unsigned) time(0));

    //Get data from file
    string fileName;
    cout << "Please enter file name: ";
    getline(cin, fileName);

    //Open file
    ifstream fin;
    fin.open(fileName);

    //Check if file is open
    if(!fin){
        cout <<"Error Opening File" << endl;
        exit(0);
    }

    //Get file size from first line
    int theArraySize;
    fin >> theArraySize;


    //int theArraySize = 100;
    int * theArray = new int[theArraySize];

    //Get the rest of the file
    for(int i = 0; i< theArraySize; ++i){
        fin >> theArray[i];
    }
     // cout << "\nText file input Array~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        displayArray(theArray, theArraySize);

    // cout << "\nText file input Array~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        exchangeSort(theArray,theArraySize);
        displayArray(theArray, theArraySize);

    // cout << "\nRandom Array~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        // randomizeArray(theArray, theArraySize,1000);
        // displayArray(theArray, theArraySize);

    // cout << "\nExchange Sort Sorted Array~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        // exchangeSort(theArray,theArraySize);
        // displayArray(theArray, theArraySize);

    cout << "Number of comaprrisons "   << comparrisonCounter   << endl;
    cout << "Number of exchanges "      << excahngeCounter      << endl;

    return 0;
}

void displayArray(int * theArray, int theArraySize)
{
	for(int i = 0; i < theArraySize; ++i){
        if(i%10 == 0){
            cout << endl;
        }
		cout << setw(10) << theArray[i];
	}
	cout << endl;
}

void randomizeArray(int* a, int s, int m){
    for(int i = 0; i < s; ++i){
		a[i] = rand()%m;
	}
}

bool inOrder(int a , int b){
    ++comparrisonCounter;
    return a<=b;
}

void exchange(int & a, int & b){
    int t = a;
    a = b;
    b = t;
    ++excahngeCounter;
}

void exchangeSort(int * a, int s){
    for(int k = 1; k < s; ++k){
        for(int i = 0; i < s - k; ++i){
            if(!inOrder(a[i], a[i+1])){
                exchange(a[i], a[i+1]);
            }
        }
    }
}

void copyArray(int * source, int * destination; int size){
    for(int i = 0; i < size; ++i){
        destination[i]= source[i];
    }
}

