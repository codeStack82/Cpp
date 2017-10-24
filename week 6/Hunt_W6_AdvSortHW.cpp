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
#pragma comment(linker, "/STACK: 80000000");
#define DIM1_SZ 1000
#define DIM2_SZ 1000000

//Prototypes
void print_Top_and_Btm_Array(int * a, int size, int n);
void copyArray(int * source, int * destination, int size);
void reverseArray(int * theArray, int size);
void zeroCounters(long long int  &comparisonsCounter, long long int &exchangeCounter);
int * getInputData(string fileName);

void quickSort_Call(int * a, int s, int n);
void quickSort_Sub(int a[], int low, int high);
void quickSort_Main(int * a, int low, int high);
int  partition(int a [], int i, int j, int p);
int  medianOf3(int a[], int left, int right);
void swap(int *a, int *b);

void mergeSort(int * a, int l, int r);
void merge(int * a, int l, int m, int r);

void radixSort(int arr [], int n);
void countSort(int arr [], int n, int exp);
int  getMax(int arr [], int n);
void insertionSort(int arr [], int n);   

//Global variables
long long int exchangeCounter;
long long int comparisonsCounter;

int main(int argc, char * argv[]){

    cout << "\n~~~~~~~~~~~~ Advanced Sorts Homework - Advanced C++ Week 6 ~~~~~~~~~~~~~~" << endl;
    string fileName1, fileName2, fileName3;
    int numToPrint = 40;
    int size = 1000000; 

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
    
    // Read in data files (3 files)
    int * list1 = getInputData(fileName1);
    int * list2 = getInputData(fileName2);
    int * list3 = getInputData(fileName3);

    // cout << "\nInput array #1~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        // print_Top_and_Btm_Array(list1, size, numToPrint);
        // cout << "\nInput array #2~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        // print_Top_and_Btm_Array(list2, size, numToPrint);
        // cout << "\nInput array #3~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        // print_Top_and_Btm_Array(list3, size, numToPrint);

        cout << "\nAnalysis 1~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<< endl;

        // cout << "Quick Sort Without setOfMedianThree~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<< endl;
        // // Quick sort - random
        // size = 1000000;
        // int * quickSortArray = new int[size];
        // copyArray(list1 , quickSortArray, size);

        // auto s = chrono::steady_clock::now();                   // timer code
        //      quickSort_Call(quickSortArray, size, 1);           // quickSort 
        // auto e = chrono::steady_clock::now();                   // timer code
        // auto d = e - s;                                         // timer code

        // cout << "\nQuick Sort - Random Array ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        // cout << "Array Size: " << size << endl;
        // print_Top_and_Btm_Array(quickSortArray, size, numToPrint);
        // cout << "\n\t# of comparisons:\t"      << comparisonsCounter   << endl;
        // cout << "\t# of exchanges:\t\t"        << exchangeCounter      << endl;
        // cout << "\tElapsed time:\t\t"<< chrono::duration <double, milli> (d).count()/ 1000 <<  " sec"  << endl; zeroCounters(comparisonsCounter, exchangeCounter);

        // // Quick sort - sorted
        // size = 1000000;
        // auto s1 = chrono::steady_clock::now();                  // timer code
        //     quickSort_Call(quickSortArray, size, 1);            // quickSort
        // auto e1 = chrono::steady_clock::now();                  // timer code
        // auto d1 = e1 - s1;                                      // timer code

        // cout << "\nQuick Sort - Sorted Array ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        // cout << "Array Size: " << size << endl;
        // print_Top_and_Btm_Array(quickSortArray, size, numToPrint);
        // cout << "\n\t# of comparisons:\t"      << comparisonsCounter   << endl;
        // cout << "\t# of exchanges:\t\t"        << exchangeCounter      << endl;
        // cout << "\tElapsed time:\t\t"<< chrono::duration <double, milli> (d1).count()/1000 <<  " sec"  << endl; zeroCounters(comparisonsCounter, exchangeCounter);

        // // Quick sort - reversed
        // size = 1000000;
        // reverseArray(quickSortArray, size);
        // cout << "\nArray Reversed" << endl;
        // auto s2 = chrono::steady_clock::now();                  // timer code
        //      quickSort_Call(quickSortArray, size, 1);           // quickSort
        // auto e2 = chrono::steady_clock::now();                  // timer code
        // auto d2 = e2 - s2;                                      // timer code

        // cout << "\nQuick sort - Reversed Array ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        // cout << "Array Size: " << size << endl;
        // print_Top_and_Btm_Array(quickSortArray, size, numToPrint);
        // cout << "\n\t# of comparisons:\t"      << comparisonsCounter   << endl;
        // cout << "\t# of exchanges:\t\t"        << exchangeCounter      << endl;
        // cout << "\tElapsed time:\t\t"<< chrono::duration <double, milli> (d2).count() /1000 <<  " sec"  << endl; zeroCounters(comparisonsCounter, exchangeCounter);

        // // Quick sort - Identical Array
        // size = 10000;
        // int * identicalList = new int[size];
        // copyArray(list2 , identicalList, size);

        // auto s3 = chrono::steady_clock::now();                  // timer codes
        //     quickSort_Call(identicalList, size, 2);             // quickSort 
        // auto e3 = chrono::steady_clock::now();                  // timer code
        // auto d3 = e3 - s3;                                      // timer code

        // cout << "\nQuick sort - Identical Array~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        // cout << "Array Size: " << size << endl;
        // print_Top_and_Btm_Array(identicalList, size, numToPrint);
        // cout << "\n\t# of comparisons:\t"      << comparisonsCounter   << endl;
        // cout << "\t# of exchanges:\t\t"        << exchangeCounter      << endl;
        // cout << "\tElapsed time:\t\t"<< chrono::duration <double, milli> (d3).count()/1000 <<  " sec"  << endl; zeroCounters(comparisonsCounter, exchangeCounter);

        // cout << "\nQuick Sort With setOfMedianThree~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<< endl;

        // // Quick sort - random
        // size = 100000;
        // int * quickSortArray1 = new int[size];
        // copyArray(list3, quickSortArray1, size);
    
        // auto s4 = chrono::steady_clock::now();              // timer code
        //     quickSort_Call(quickSortArray1, size, 2);       // quickSort
        // auto e4 = chrono::steady_clock::now();              // timer code
        // auto d4 = e4 - s4;                                  // timer code

        // cout << "\nQuick Sort - Random Array ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        // cout << "Array Size: " << size << endl;
        // print_Top_and_Btm_Array(quickSortArray1, size, numToPrint);
        // cout << "\n\t# of comparisons:\t"      << comparisonsCounter   << endl;
        // cout << "\t# of exchanges:\t\t"        << exchangeCounter      << endl;
        // cout << "\tElapsed time:\t\t"<< chrono::duration <double, milli> (d4).count()/ 1000 <<  " sec"  << endl; zeroCounters(comparisonsCounter, exchangeCounter);

        // // Quick sort - sorted
        // size = 10000;
        // auto s5 = chrono::steady_clock::now();              // timer code
        //      quickSort_Call(quickSortArray1, size, 2);      // quickSort
        // auto e5 = chrono::steady_clock::now();              // timer code
        // auto d5 = e5 - s5;                                  // timer code

        // cout << "\nQuick Sort - Sorted Array ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        // cout << "Array Size: " << size << endl;
        // print_Top_and_Btm_Array(quickSortArray1, size, numToPrint);
        // cout << "\n\t# of comparisons:\t"      << comparisonsCounter   << endl;
        // cout << "\t# of exchanges:\t\t"        << exchangeCounter      << endl;
        // cout << "\tElapsed time:\t\t"<< chrono::duration <double, milli> (d5).count()/1000 <<  " sec"  << endl; zeroCounters(comparisonsCounter, exchangeCounter);

        // // Quick sort - reversed
        // reverseArray(quickSortArray1, size);
        // size = 10000;

        // auto s6 = chrono::steady_clock::now();                  // timer code
        //       quickSort_Call(quickSortArray1, size, 2);         // quickSort
        // auto e6 = chrono::steady_clock::now();                  // timer code
        // auto d6 = e6 - s6;                                      // timer code
        // cout << "\nQuick sort - Reversed Array ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        // cout << "Array Size: " << size << endl;
        // print_Top_and_Btm_Array(quickSortArray1, size, numToPrint);
        // cout << "\n\t# of comparisons:\t"      << comparisonsCounter   << endl;
        // cout << "\t# of exchanges:\t\t"        << exchangeCounter      << endl;
        // cout << "\tElapsed time:\t\t"<< chrono::duration <double, milli> (d6).count() /1000 <<  " sec"  << endl; zeroCounters(comparisonsCounter, exchangeCounter);

        // // Quick sort - Identical Array
        // size = 1000000;
        // int * identicalList1 = new int[size];
        // copyArray(list2 , identicalList1, size);

        // auto s7 = chrono::steady_clock::now();                      // timer code
        //      quickSort_Call(identicalList1, size, 2);               // quickSort
        // auto e7 = chrono::steady_clock::now();                      // timer code
        // auto d7 = e7 - s7;                                          // timer code

        // cout << "\nQuick sort - Identical Array~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        // cout << "Array size: " << size << endl;
        // print_Top_and_Btm_Array(identicalList1, size, numToPrint);
        // cout << "\n\t# of comparisons:\t"      << comparisonsCounter   << endl;
        // cout << "\t# of exchanges:\t\t"        << exchangeCounter      << endl;
        // cout << "\tElapsed time:\t\t"<< chrono::duration <double, milli> (d7).count()/1000 <<  " sec"  << endl; zeroCounters(comparisonsCounter, exchangeCounter);

    cout << "\nAnalysis 2~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<< endl;

    // Quick sort with insertion Sort - random
    size = 1000000;
    int * quickSortArray2 = new int[size];
    copyArray(list3, quickSortArray2, size);
  
    // Quick sort - sorted
    size = 1000000;
    auto s8 = chrono::steady_clock::now();              // timer code
         quickSort_Call(quickSortArray2, size, 2);      // quickSort
    auto e8 = chrono::steady_clock::now();              // timer code
    auto d8 = e8 - s8;                                  // timer code

    cout << "\nQuick Sort with InsertSort on Random Array ~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
    cout << "Array Size: " << size << endl;
    print_Top_and_Btm_Array(quickSortArray2, size, numToPrint);
    cout << "\n\t# of comparisons:\t"      << comparisonsCounter   << endl;
    cout << "\t# of exchanges:\t\t"        << exchangeCounter      << endl;
    cout << "\tElapsed time:\t\t"<< chrono::duration <double, milli> (d8).count()/1000 <<  " sec"  << endl; zeroCounters(comparisonsCounter, exchangeCounter);

    cout << "\nQuick Sort - Sorted Array ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
    cout << "Array Size: " << size << endl;
    print_Top_and_Btm_Array(quickSortArray, size, numToPrint);
    cout << "\n\t# of comparisons:\t"      << comparisonsCounter   << endl;
    cout << "\t# of exchanges:\t\t"        << exchangeCounter      << endl;
    cout << "\tElapsed time:\t\t"<< chrono::duration <double, milli> (d1).count()/1000 <<  " sec"  << endl; zeroCounters(comparisonsCounter, exchangeCounter);

    // Quick sort - reversed
    size = 1000000;
    reverseArray(quickSortArray, size);
    cout << "\nArray Reversed" << endl;
    auto s2 = chrono::steady_clock::now();                  // timer code
        quickSort_Call(quickSortArray, size, 1);           // quickSort
    auto e2 = chrono::steady_clock::now();                  // timer code
    auto d2 = e2 - s2;                                      // timer code



    return EXIT_SUCCESS;      
}

void insertionSort(int * arr, int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
            comparisonsCounter++;
        }
        arr[j+1] = key;
        exchangeCounter++;
    }
}

void quickSort_Call(int * a, int size, int n){
    int low = 0;
    int high = size;

    if(n == 1){
        quickSort_Sub(a, low, high);
    }else if(n == 2){
        quickSort_Main(a, low, high);
    }
}

void quickSort_Sub(int a[], int low, int high) {
    //http://people.cs.ubc.ca/~harrison/Java/QSortAlgorithm.java.html
	int lo = low;
	int hi = high;

	if (lo >= hi) {
        comparisonsCounter++;
	    return;
	}else if( lo == hi - 1 ) {
         comparisonsCounter++;
        if (a[lo] > a[hi]) {
            comparisonsCounter++;
            int T = a[lo];
            a[lo] = a[hi];
            a[hi] = T;
        }
        return;
	}
    /*
    *  Pick a pivot and move it out of the way
    */
	int pivot = a[(lo + hi) / 2];
        a[(lo + hi) / 2] = a[hi];
        a[hi] = pivot;

        comparisonsCounter++;
        while( lo < hi ) {
            /*
             *  Search forward from a[lo] until an element is found that
             *  is greater than the pivot or lo >= hi 
             */
            while (a[lo] <= pivot && lo < hi) {
                comparisonsCounter += 2;
		        lo++;
	        }

            /*
             *  Search backward from a[hi] until element is found that
             *  is less than the pivot, or lo >= hi
             */
            while (pivot <= a[hi] && lo < hi ) {
                comparisonsCounter += 2;
                hi--;
            }

            /*
             *  Swap elements a[lo] and a[hi]
             */
            comparisonsCounter++;
            if( lo < hi ) {
                int T = a[lo];
                a[lo] = a[hi];
                a[hi] = T;
                exchangeCounter++;
            }
	}

    a[high] = a[hi];
    a[hi] = pivot;

	quickSort_Sub(a, low, lo-1);
	quickSort_Sub(a, hi+1, high);
}

void quickSort_Main(int * a, int low, int high){
    int size = high - low + 1;
    if (size <= 7500){
        insertionSort(a, high);
    }else {
        int median = medianOf3(a, low, high); 
        int pivot = partition(a, low, high, median);

        quickSort_Main(a, low, pivot - 1);
        quickSort_Main(a, pivot + 1, high);
   }
}

int partition(int * a , int low, int high, int pivot){
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++){
        comparisonsCounter++;  
        if (a[j] <= pivot){
            i++;   
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

int medianOf3(int a[], int left, int right) {
    int center = (left + right) / 2;

    if (a[left] > a[center]){
        comparisonsCounter++;  
        swap(&a[left], &a[center]);
    }

    if (a[left] > a[right]){
        comparisonsCounter++;  
        swap(&a[left], &a[right]);
    }

    if (a[center] > a[right]){
        comparisonsCounter++;  
        swap(&a[center], &a[right]);
    }
    comparisonsCounter++;  
    swap(&a[center], &a[right - 1]);
    return a[right - 1];
}

void swap(int *a, int *b){
    int temp = *a;
	*a = *b;
	*b = temp;
    exchangeCounter++;
}

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

int * getInputData(string fileName){ //TODO: fix file input size here <<---- possible with a ref var

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
