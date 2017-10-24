 /*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   Due: 10/15/17
*   Details: Simple Sorts Homework
*   Reference Material https://solarianprogrammer.com/2012/10/14/cpp-11-timing-code-performance/
*   Reference Material: http://www.geeksforgeeks.org/quick-qSort/
*   Reference Material: http://homepage.divms.uiowa.edu/~hzhang/c31/notes/ch08.pdf 
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
#pragma comment(linker, "/STACK: 800000000");

//Prototypes - helper function - all work good
void print_Top_and_Btm_Array(int * a, int size, int n);
void copyArray(int * source, int * destination, int size);
void reverseArray(int * theArray, int size);
void zeroCounters(long long int  &comparisonsCounter, long long int &exchangeCounter);
int * getInputData(string fileName);

void quickSort(int a[], int left, int right);
int  medianOf3(int a[], int left, int right);
int  partitionIt(int a[], int left, int right, int pivot);
void manualSort(int a[], int left, int right);
void swap(int a[], int b, int c);



//Global variables
long long int exchangeCounter;
long long int comparisonsCounter;

int main(int argc, char * argv[]){

    cout << "\n~~~~~~~~~~~~ Advanced Sorts Homework - Advanced C++ Week 6 ~~~~~~~~~~~~~~" << endl;
    string fileName1;
    int numToPrint = 10;    //Used to adjust how many numbers are pinted in print func
    int size = 10;     //Using this so to input change the size if there are errors

    // Get file names from cmd line 
    if(argc >= 2){     
        fileName1 = argv[1];
        cout << "\nFile names " << fileName1 << endl;
    // Get file names from user input     
    }else{
        cout << "\nPlease, enter a file name. (ex: list1.txt) " << endl;
        cout << "File name: ";
        cin >> fileName1;
        cout << "\nFile names " << fileName1 << endl;
        
    }
    
    // Read in data files (3 files)
    int * list1 = getInputData(fileName1); // Random sorted file

    // Print the header of all input files - used for testing - can comment out
    cout << "\nInput array #1~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
    print_Top_and_Btm_Array(list1, size, numToPrint);

    // Quick sort - random
    size = 10;
    int * quickSortArray = new int[size];
    copyArray(list1 , quickSortArray, size);

    auto s = chrono::steady_clock::now();                   // timer code
         quickSort(quickSortArray, 0, size);                // Quick Sort
    auto e = chrono::steady_clock::now();                   // timer code
    auto d = e - s;                                         // timer code

    cout << "\nQuick Sort - Random Array ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
    cout << "Array Size: " << size << endl;
    print_Top_and_Btm_Array(quickSortArray, size, numToPrint);
    cout << "\n\t# of comparisons:\t"      << comparisonsCounter   << endl;
    cout << "\t# of exchanges:\t\t"        << exchangeCounter      << endl;
    cout << "\tElapsed time:\t\t"<< chrono::duration <double, milli> (d).count()/ 1000 <<  " sec"  << endl; zeroCounters(comparisonsCounter, exchangeCounter);

    return EXIT_SUCCESS;      
}

//http://people.cs.ubc.ca/~harrison/Java/QSortAlgorithm.java.html
void quickSort(int a[], int left, int right){
    int size = right - left + 1;
    if (size >= 10000){
        //manualSort(a, left, right);
    }else {
        int median = medianOf3(a, left, right); 
        int partition = partitionIt(a, left, right, median);    
            cout << "median " << median << " partition: "    << partition << endl;
        quickSort(a, left, partition - 1);
        quickSort(a, partition + 1, right);
    }
}

int medianOf3(int a[], int left, int right) {
    int center = (left + right) / 2;

    if (a[left] > a[center]){
        comparisonsCounter++;  
        swap(a, left, center);
    }

    if (a[left] > a[right]){
        comparisonsCounter++;  
        swap(a, left, right);
    }

    if (a[center] > a[right]){
        comparisonsCounter++;  
        swap(a, center, right);
    }
    comparisonsCounter++;  
    swap(a, center, right - 1);
    return a[right - 1];
}

int partitionIt(int a[], int left, int right, int pivot) {
    int i = (left - 1);

    for (int j = left; j <= right - 1; j++){
        comparisonsCounter++;  
        if (a[j] <= pivot){
            i++;   
            swap(a, left, right);
        }
    }
    swap(a, left + 1, right);
    return (i + 1);
}

void manualSort(int a[], int left, int right) {
    cout << "In Manual Sort" << endl;
    int size = right - left + 1;
    if (size <= 1){
        comparisonsCounter++; 
        return;
    }
    if (size == 2) {
        comparisonsCounter++; 
        if (a[left] > a[right]){
            comparisonsCounter++; 
            swap(a, left, right);
        }
    } else {
        if (a[left] > a[right - 1]){
                comparisonsCounter++; 
                swap(a,left,right - 1);
        }
        if (a[left] > a[right]){
                comparisonsCounter++; 
                swap(a,left, right - 1);
        }
        if (a[right - 1] > a[right]){
                comparisonsCounter++; 
                swap(a,right-1, right);
        }
    }
}

void swap(int a[], int b, int c) {
    cout << "In Swap" << endl;
    int temp = a[b];
    a[b] = a[c];
    a[c] = temp;
}



//Helper functions
void copyArray(int * source, int * destination, int size){
    for(int i = 0; i < size; ++i){
        destination[i]= source[i];
    }
}

void reverseArray(int * theArray, int size){
    for (int i = 0; i < (size / 2); i++) {
        int temporary = theArray[i];               
        theArray[i] = theArray[(size - 1) - i];
        theArray[(size - 1) - i] = temporary;
    }
}

void zeroCounters(long long int  &comparisonsCounter, long long int &exchangeCounter){
    comparisonsCounter = 0;
    exchangeCounter= 0;
}

int * getInputData(string fileName){

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

void print_Top_and_Btm_Array(int * a, int size, int n){   
    if ( size <= n ){
        for(int i = 0; i < size; ++i){
            
            if ( i%10 == 0 ){
            cout << endl;
            }
            cout << setw(7) << a[i];
        }
    }
        else{
        //print first 100
        for(int i = 0; i < n/2; ++i){
            if ( i%10 == 0 ){
            cout << endl;
            }
            cout << setw(7) << a[i]; 
        }
        //print last 100
        cout << endl;
        cout <<"\n      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        for(int i = size - (n/2); i < size; ++i){
            if ( i%10 == 0 ){
                cout << endl;
            }
            cout << setw(7) << a[i]; 
        }
    }
        cout << endl;
}


