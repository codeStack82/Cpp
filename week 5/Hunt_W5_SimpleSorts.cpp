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
        cout << "File name: " << fileName << endl;;
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
    //theArraySize = 1000;  //used to test for HW problems

    // Create new array with the size of the first int in the file
    int * theArray = new int[theArraySize];

    // Get the rest of the file
    for(int i = 0; i< theArraySize; ++i){
        fin >> theArray[i];
    }

    cout << "\nText file input Array~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
    print_Top_and_Btm_Array(theArray, theArraySize);


    // Copy the array and run exchange sort
    int * exchangeSortArray = new int[theArraySize];
    copyArray(theArray, exchangeSortArray, theArraySize);

    cout << "\nExchange Sort~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<< endl;
    
    auto start = chrono::steady_clock::now();
        exchangeSort(exchangeSortArray, theArraySize);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;

    cout << "Exchange sort the array" << endl;
    print_Top_and_Btm_Array(exchangeSortArray, theArraySize);
    cout << "\t# of comaprrisons:\t"     << comparrisonCounter   << endl;
    cout << "\t# of exchanges:\t\t"      << exchangeCounter      << endl;
    cout << "\tElapsed time:\t\t"        << chrono::duration <double, milli> (diff).count() <<  " ms"  << endl;
    zeroCounters(comparrisonCounter, exchangeCounter);

    auto s1 = chrono::steady_clock::now();
        exchangeSort(exchangeSortArray, theArraySize);
    auto e1 = chrono::steady_clock::now();
    auto d1 = e1 - s1;

    cout << "\nExchange sort the already sorted array" << endl;
    print_Top_and_Btm_Array(exchangeSortArray, theArraySize);
    cout << "\t# of comaprrisons:\t"     << comparrisonCounter   << endl;
    cout << "\t# of exchanges:\t\t"      << exchangeCounter      << endl;
    cout << "\tElapsed time:\t\t"<< chrono::duration <double, milli> (d1).count() <<  " ms"  << endl;
    zeroCounters(comparrisonCounter, exchangeCounter);

    cout << "\nReverse the already sorted array" << endl;
    reverseArray(exchangeSortArray,theArraySize);
    print_Top_and_Btm_Array(exchangeSortArray, theArraySize);

    cout << "\nExchange sort the reversed sorted array" << endl;
    auto s2 = chrono::steady_clock::now();
        exchangeSort(exchangeSortArray, theArraySize);
    auto e2 = chrono::steady_clock::now();
    auto d2 = e2 - s2;

    print_Top_and_Btm_Array(exchangeSortArray, theArraySize);
    cout << "\t# of comaprrisons:\t"     << comparrisonCounter   << endl;
    cout << "\t# of exchanges:\t\t"      << exchangeCounter      << endl;
    cout << "\tElapsed time:\t\t"<< chrono::duration <double, milli> (d2).count() <<  " ms"  << endl;
    zeroCounters(comparrisonCounter, exchangeCounter);

    int * insertSortArray = new int[theArraySize];
    copyArray(theArray, insertSortArray, theArraySize);

    cout << "\nInsertion Sort~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<< endl;

    cout << "Insertion sort the array" << endl;
    auto s3 = chrono::steady_clock::now();
       insertionSort(insertSortArray, theArraySize);
    auto e3 = chrono::steady_clock::now();
    auto d3 = e3 - s3;

    print_Top_and_Btm_Array(insertSortArray, theArraySize);
    cout << "\t# of comaprrisons:\t"     << comparrisonCounter   << endl;
    cout << "\t# of exchanges:\t\t"      << exchangeCounter      << endl;
    cout << "\tElapsed time:\t\t"<< chrono::duration <double, milli> (d3).count() << " ms"  << endl;
    zeroCounters(comparrisonCounter, exchangeCounter);

    cout << "\nInsertion sort the already sorted array" << endl;
    auto s4 = chrono::steady_clock::now();
        insertionSort(insertSortArray, theArraySize);
    auto e4 = chrono::steady_clock::now();
    auto d4 = e4 - s4;

    print_Top_and_Btm_Array(insertSortArray, theArraySize);
    cout << "\t# of comaprrisons:\t"     << comparrisonCounter   << endl;
    cout << "\t# of exchanges:\t\t"      << exchangeCounter      << endl;
    cout << "\tElapsed time:\t\t"<< chrono::duration <double, milli> (d4).count() <<  " ms"  << endl;
    zeroCounters(comparrisonCounter, exchangeCounter);

    cout << "\nReverse the already sorted array" << endl;
    reverseArray(insertSortArray,theArraySize);
    print_Top_and_Btm_Array(insertSortArray, theArraySize);
    
    cout << "\nInsertion Sort the already sorted/reversed array" << endl;
    auto s5 = chrono::steady_clock::now();
        insertionSort(insertSortArray, theArraySize);
    auto e5 = chrono::steady_clock::now();
    auto d5 = e5 - s5;
    print_Top_and_Btm_Array(insertSortArray, theArraySize);
    cout << "\t# of comaprrisons:\t"     << comparrisonCounter   << endl;
    cout << "\t# of exchanges:\t\t"      << exchangeCounter      << endl;
    cout << "\tElapsed time:\t\t"<< chrono::duration <double, milli> (d5).count() <<  " ms"  << endl;
    zeroCounters(comparrisonCounter, exchangeCounter);

    cout << "\nSelection Sort~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<< endl;
    //Copy the original array
    int * selectionSortArray = new int[theArraySize];
    copyArray(theArray,selectionSortArray, theArraySize);

    cout << "Selection sort the array" << endl;
    auto s6 = chrono::steady_clock::now();
        selectionSort(selectionSortArray, theArraySize);
    auto e6 = chrono::steady_clock::now();
    auto d6 = e6 - s6;
    print_Top_and_Btm_Array(selectionSortArray, theArraySize);
    cout << "\t# of comaprrisons:\t"     << comparrisonCounter   << endl;
    cout << "\t# of exchanges:\t\t"      << exchangeCounter      << endl;
    cout << "\tElapsed time:\t\t"<< chrono::duration <double, milli> (d6).count() << " ms"  << endl;
    zeroCounters(comparrisonCounter, exchangeCounter);

    cout << "\nSelection sort the already sorted array" << endl;
    auto s7 = chrono::steady_clock::now();
        selectionSort(selectionSortArray, theArraySize);
    auto e7 = chrono::steady_clock::now();
    auto d7 = e7 - s7;

    print_Top_and_Btm_Array(selectionSortArray, theArraySize);
    cout << "\t# of comaprrisons:\t"     << comparrisonCounter   << endl;
    cout << "\t# of exchanges:\t\t"      << exchangeCounter      << endl;
    cout << "\tElapsed time:\t\t"<< chrono::duration <double, milli> (d7).count() <<  " ms"  << endl;
    zeroCounters(comparrisonCounter, exchangeCounter);

    cout << "\nReverse the already sorted array" << endl;
    reverseArray(selectionSortArray,theArraySize);
    print_Top_and_Btm_Array(selectionSortArray, theArraySize);

    cout << "\nSelection Sort the already sorted/reversed array" << endl;
    auto s8 = chrono::steady_clock::now();
        selectionSort(selectionSortArray, theArraySize);
    auto e8 = chrono::steady_clock::now();
    auto d8 = e8 - s8;
    print_Top_and_Btm_Array(selectionSortArray, theArraySize);
    cout << "\t# of comaprrisons:\t"     << comparrisonCounter   << endl;
    cout << "\t# of exchanges:\t\t"      << exchangeCounter      << endl;
    cout << "\tElapsed time:\t\t"<< chrono::duration <double, milli> (d8).count() << " ms" << endl;
    zeroCounters(comparrisonCounter, exchangeCounter);
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<< endl;
    //Copy the original array

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
void zeroCounters(int &comparrisonCounter, int &exchangeCounter){
    comparrisonCounter = 0;
    exchangeCounter= 0;
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

void insertionSort(int * arr, int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
            comparrisonCounter++;
        }
        arr[j+1] = key;
        exchangeCounter++;
        //print_Top_and_Btm_Array(arr, 21) ;
    }
}

void swap(int *a, int *b){
    int temp = *a;
	*a = *b;
	*b = temp;
    exchangeCounter++;
}

void selectionSort(int * arr, int n){
    int i, j, min_idx;
     //print_Top_and_Btm_Array(arr, 21);
	for (i = 0; i < n-1; i++){
		min_idx = i;
		for (j = i + 1; j < n; j++){
            if (arr[j] < arr[min_idx])
                min_idx = j;
                comparrisonCounter++;
        }

		swap(&arr[min_idx], &arr[i]);
        //print_Top_and_Btm_Array(arr, 21);

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


