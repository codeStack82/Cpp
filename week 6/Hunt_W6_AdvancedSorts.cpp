 /*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   Due: 10/15/17
*   Details: Simple Sorts Homework
*   Reference Timer code: https://solarianprogrammer.com/2012/10/14/cpp-11-timing-code-performance/
*   Reference Timer code: http://www.informit.com/articles/article.aspx?p=1881386&seqNum=2
*/

#include <iostream>
#include <typeinfo>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>
#include <ctime>
#include <chrono>

using namespace std;

//Prototypes
void displayArray(int * theArray, int theArraySize);
void print_Top_and_Btm_Array(int * a, int size);
void copyArray(int * source, int * destination, int size);
void reverseArray(int * theArray, int size);
void swap(int *a, int *b);
bool inOrder(int a , int b);
void zeroCounters(int &comparrisonCounter, int &exchangeCounter);
void exchange(int & a, int & b);
void exchangeSort(int * a, int s);
void insertionSort(int * a, int s);         // helper - call the internal array;
//void insertionSort(int * a, int f, int l);  // worker - from first to last - 1
void selectionSort(int * a, int s);         

int * getInputData(string fileName);


//Global variables
int exchangeCounter;
int comparrisonCounter;

int main(int argc, char * argv[]){

    cout << "\n~~~~~~~~~~~~ Simple Sorts Homework - Advanced C++ Week 5 ~~~~~~~~~~~~" << endl;
    string fileName1, fileName2, fileName3;
    
    // Get file name - test cmd input 
    if(argc >= 4){     
        fileName1 = argv[1];
        fileName2 = argv[2];
        fileName3 = argv[3];
        cout << "\nFile names " << fileName1 << ", "<< fileName2 << ", " << fileName3 << endl;

    }else{
        cout << "\nPlease, enter 3 file names. (ex: list1.txt) " << endl;
        cout << "File name: ";
        cin >> fileName1;
        cout << "File name: ";
        cin >> fileName2;
        cout << "File name: ";
        cin >> fileName3;
        cout << "\nFile names " << fileName1 << ", "<< fileName2 << ", " << fileName3 << endl;
        
    }
    
    int size = 10000; //todo: fix the input size.

    // Read in data files (3 files)
    int * list1 = getInputData(fileName1);
    int * list2 = getInputData(fileName2);
    int * list3 = getInputData(fileName3);

    cout << "\nInput array #1~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
    print_Top_and_Btm_Array(list1, size);
    cout << "\nInput array #2~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
    print_Top_and_Btm_Array(list2, size);
    cout << "\nInput array #3~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
    print_Top_and_Btm_Array(list3, size);
 

    
    
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<< endl;
    return EXIT_SUCCESS;      
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
void zeroCounters(int &comparrisonCounter, int &exchangeCounter){
    comparrisonCounter = 0;
    exchangeCounter= 0;
}

int * getInputData(string fileName){ //TODO: fix file input size here <<----

    // Open file stream
    ifstream fin;
    fin.open(fileName);

    // Check if file is open
    if(!fin){
        cout <<"Error Opening File, Sorry!" << endl;
        return 0;
    }

    // Get file size from first line
    int theArraySize;
    fin >> theArraySize;

    // Create new array with the size of the first int in the file
    int * theArray = new int[theArraySize];

    // Get the rest of the file
    for(int i = 0; i < theArraySize; ++i){
        fin >> theArray[i];
    }
    return theArray;
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
        cout <<"      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        for(int i = size - 100; i < size; ++i){
            if ( i%10 == 0 ){
                cout << endl;
            }
            cout << setw(10) << a[i]; 
        }
    }
        cout << endl;
}
