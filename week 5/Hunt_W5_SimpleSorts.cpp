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
#include <fstream>
#include <ctime>

using namespace std;

//Prototypes
void displayArray(int * theArray, int theArraySize);
void print_Top_and_Btm_Array(int * a, int size);
void copyArray(int * source, int * destination, int size);
void reverseArray(int * theArray, int size);
bool inOrder(int a , int b);
void exchange(int & a, int & b);
void exchangeSort(int * a, int s);

//Still need to build these functions
void insertionSort(int * a, int f, int l);  // from first to last - 1
void insertionSort(int * a, int s);         // call the internal array;
void selectionSort(int * a, int s);         

//Global variables
int exchangeCounter;
int comparrisonCounter;

int main(int argc, char * argv[]){

    cout << "\n~~~~~~~~~~~~ Simple Sorts Homework - Advanced C++ Week 5 ~~~~~~~~~~~~" << endl;
    
    string fileName;

    // Get file name - test cmd input 
    if(argc >= 2){     
       fileName = argv[1];
       cout << "\tFile name: " << fileName << endl;;
    }else{
        cout << "Please, enter a file name: ";
        getline(cin, fileName);
        cout << "\tFile name: " << fileName << endl;;
    }

    // Open file stream
    ifstream fin;
    fin.open(fileName);

    // Check if file is open
    if(!fin){
        cout <<"Error Opening File, Sorry!" << endl;
        exit(0);
    }

    // Get file size from first line
    int theArraySize;
    fin >> theArraySize;

    // Create new array with the size of the first int in the file
    int * theArray = new int[theArraySize];

    // Get the rest of the file
    for(int i = 0; i< theArraySize; ++i){
        fin >> theArray[i];
    }

    cout << "\nText file input Array~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
    print_Top_and_Btm_Array(theArray, theArraySize);


    // Copy the array and run exchange sort
    int * exchangeSortArray = new int[theArraySize];
    copyArray(theArray,exchangeSortArray, theArraySize);

    cout << "\nExchange Sort~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<< endl;
    exchangeSort(exchangeSortArray, theArraySize);
    cout << "Exchange sort the array" << endl;
    print_Top_and_Btm_Array(exchangeSortArray, theArraySize);
    cout << "\t# of comaprrisons:\t"     << comparrisonCounter   << endl;
    cout << "\t# of exchanges:\t\t"      << exchangeCounter      << endl;
    //zero counters
    comparrisonCounter = 0;
    exchangeCounter = 0;

    exchangeSort(exchangeSortArray, theArraySize);
    cout << "\nExchange sort the already sorted array" << endl;
    print_Top_and_Btm_Array(exchangeSortArray, theArraySize);
    cout << "\t# of comaprrisons:\t"     << comparrisonCounter   << endl;
    cout << "\t# of exchanges:\t\t"      << exchangeCounter      << endl;
    //zero counters
    comparrisonCounter = 0;
    exchangeCounter = 0;

    cout << "\nReverse array the already sorted array" << endl;
    reverseArray(exchangeSortArray,theArraySize);
    print_Top_and_Btm_Array(exchangeSortArray, theArraySize);
      cout << "\nExchange sort the reversed sorted array" << endl;
    exchangeSort(exchangeSortArray, theArraySize);
    print_Top_and_Btm_Array(exchangeSortArray, theArraySize);
    cout << "\t# of comaprrisons:\t"     << comparrisonCounter   << endl;
    cout << "\t# of exchanges:\t\t"      << exchangeCounter      << endl;
    //zero counters
    comparrisonCounter = 0;
    exchangeCounter = 0;

    int * insertSortArray = new int[theArraySize];
    copyArray(theArray,insertSortArray, theArraySize);

    cout << "\nInsertion Sort~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<< endl;
    // insertionsSort(insertSortArray, theArraySize);
    // cout << "Insertion sort the array" << endl;
    // print_Top_and_Btm_Array(insertSortArray, theArraySize);
    // cout << "\t# of comaprrisons:\t"     << comparrisonCounter   << endl;
    // cout << "\t# of exchanges:\t\t"      << exchangeCounter      << endl;
    // //zero counters
    // comparrisonCounter = 0;
    // exchangeCounter = 0;

    // insertionSort(insertSortArray, theArraySize);
    // cout << "\nInsertion sort the already sorted array" << endl;
    // displayArray(insertSortArray, theArraySize);
    // cout << "\t# of comaprrisons:\t"     << comparrisonCounter   << endl;
    // cout << "\t# of exchanges:\t\t"      << exchangeCounter      << endl;
    // //zero counters
    // comparrisonCounter = 0;
    // exchangeCounter = 0;

    // cout << "\nReverse Array and insert sort the already sorted array" << endl;
    // reverseArray(insertSortArray,theArraySize);
    // displayArray(insertSortArray, theArraySize);
    // exchangeSort(insertSortArray, theArraySize);
    // displayArray(insertSortArray, theArraySize);
    // cout << "\t# of comaprrisons:\t"     << comparrisonCounter   << endl;
    // cout << "\t# of exchanges:\t\t"      << exchangeCounter      << endl;
    // //zero counters
    // comparrisonCounter = 0;
    // exchangeCounter = 0;


    // int * selectionSortArray = new int[theArraySize];
    // copyArray(theArray,insertSortArray, theArraySize);

    // cout << "\nSelection Sort~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<< endl;
    // selectionSort(selectionSortArray, theArraySize);
    // cout << "Selection sort the array" << endl;
    // displayArray(selectionSortArray, theArraySize);
    // cout << "\t# of comaprrisons:\t"     << comparrisonCounter   << endl;
    // cout << "\t# of exchanges:\t\t"      << exchangeCounter      << endl;
    // //zero counters
    // comparrisonCounter = 0;
    // exchangeCounter = 0;

    // selectionSort(selectionSortArray, theArraySize);
    // cout << "\nInsertion sort the already sorted array" << endl;
    // displayArray(selectionSortArray, theArraySize);
    // cout << "\t# of comaprrisons:\t"     << comparrisonCounter   << endl;
    // cout << "\t# of exchanges:\t\t"      << exchangeCounter      << endl;
    // //zero counters
    // comparrisonCounter = 0;
    // exchangeCounter = 0;

    // cout << "\nReverse Array and insert sort the already sorted array" << endl;
    // reverseArray(selectionSortArray,theArraySize);
    // displayArray(selectionSortArray, theArraySize);
    // selectionSort(selectionSortArray, theArraySize);
    // displayArray(selectionSortArray, theArraySize);
    // cout << "\t# of comaprrisons:\t"     << comparrisonCounter   << endl;
    // cout << "\t# of exchanges:\t\t"      << exchangeCounter      << endl;

    return EXIT_SUCCESS;      
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

void copyArray(int * source, int * destination, int size){
    for(int i = 0; i < size; ++i){
        destination[i]= source[i];
    }
}

void reverseArray(int * theArray, int size)
{
    for (int i = 0; i < (size / 2); i++) {
        int temporary = theArray[i];               
        theArray[i] = theArray[(size - 1) - i];
        theArray[(size - 1) - i] = temporary;
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
    ++exchangeCounter;
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

void print_Top_and_Btm_Array(int * a, int size){   
    if ( size <= 200 ){
        for(int i = 0; i < size; ++i){
            if ( i%10 == 0 ){
            cout << endl;
            }
            cout << setw(10) << a[i];
        }
    }
        else{
        //print first 100
        for(int i = 0; i < 100; ++i){
            if ( i%10 == 0 ){
            cout << endl;
            }
            cout << setw(10) << a[i]; 
        }
        //print last 100
        cout << endl;
        cout << "-----------------------------------------------------------------------------------------------------" << endl;
        for(int i = size - 100; i < size; ++i){
            if ( i%10 == 0 ){
                cout << endl;
            }
            cout << setw(10) << a[i]; 
        }
    }
        cout << endl;
}


