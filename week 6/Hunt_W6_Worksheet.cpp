 /*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   Due: 10/15/17
*   Details: Simple Sorts Homework
*   Reference Timer code: https://solarianprogrammer.com/2012/10/14/cpp-11-timing-code-performance/
*   Reference Timer code: http://www.informit.com/articles/article.aspx?p=1881386&seqNum=2
*   Reference Material: http://www.geeksforgeeks.org/quick-sort/
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

//Prototypes
void print_Top_and_Btm_Array(int * a, int size, int n);
void copyArray(int * source, int * destination, int size);
void reverseArray(int * theArray, int size);
void zeroCounters(int &comparrisonCounter, int &exchangeCounter);
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
int exchangeCounter;
int comparrisonCounter;

int main(int argc, char * argv[]){

    cout << "\n~~~~~~~~ Advanced Sorts Homework Worksheet - Advanced C++ Week 6 ~~~~~~~~~~" << endl;
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

    cout << "\nInput array #1~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
    print_Top_and_Btm_Array(list1, size, numToPrint);
    cout << "\nInput array #2~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
    print_Top_and_Btm_Array(list2, size, numToPrint);
    cout << "\nInput array #3~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
    print_Top_and_Btm_Array(list3, size, numToPrint);


    cout << "Quick Sort Without setOfMedianThree~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<< endl;
    // Quick sort - random
    size = 5000;
    while(size < 50000){
        int * quickSortArray = new int[size];
        copyArray(list1 , quickSortArray, size);

        auto s = chrono::steady_clock::now();                   // timer code
            quickSort_Call(quickSortArray, size, 2);            // quickSort 
        auto e = chrono::steady_clock::now();                   // timer code
        auto d = e - s;                                         // timer code

        cout << "\nQuick Sort - Random Array ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        cout << "Array Size: " << size << endl;
        //print_Top_and_Btm_Array(quickSortArray, size, numToPrint);
        cout << "\n\t# of comparisons:\t"      << comparrisonCounter   << endl;
        cout << "\t# of exchanges:\t\t"        << exchangeCounter      << endl;
        cout << "\tElapsed time:\t\t"<< chrono::duration <double, milli> (d).count() <<  " ms"  << endl; zeroCounters(comparrisonCounter, exchangeCounter);
        size +=5000;
    }   

    // Merge Sort
    size = 50000;
    while (size < 100000){
        int * mergeSortArray = new int[size];
        copyArray(list1 , mergeSortArray, size);

        auto s2 = chrono::steady_clock::now();      //timer code
            mergeSort(mergeSortArray, 0, size);
        auto e2 = chrono::steady_clock::now();      //timer code
        auto d2 = e2 - s2;                          //timer code
        cout << "\nMerge Sort~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        //print_Top_and_Btm_Array(mergeSortArray, size, numToPrint);
        cout << "\n\t# of comaprrisons:\t"     << comparrisonCounter   << endl;
        cout << "\t# of exchanges:\t\t"        << exchangeCounter      << endl;
        cout << "\tElapsed time:\t\t"<< chrono::duration <double, milli> (d2).count() <<  " ms"  << endl; zeroCounters(comparrisonCounter, exchangeCounter);
        size += 50000;
    }

    // Radix Sort
    size = 50000;
    while(size <= 1000000){
        int * radixSortArray = new int[size];
        copyArray(list1 , radixSortArray, size);

        auto s3 = chrono::steady_clock::now();      //timer code
            radixSort(radixSortArray, size);
        auto e3 = chrono::steady_clock::now();      //timer code
        auto d3 = e3 - s3;                          //timer code
        cout << "\nRadix Sort~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        //print_Top_and_Btm_Array(radixSortArray, size, numToPrint);
        cout << "\n\t# of comaprrisons:\t"     << comparrisonCounter   << endl;
        cout << "\t# of exchanges:\t\t"        << exchangeCounter      << endl;
        cout << "\tElapsed time:\t\t"<< chrono::duration <double, milli> (d3).count()/1000 <<  " sec"  << endl; zeroCounters(comparrisonCounter, exchangeCounter);
        size += 50000;
    }
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<< endl;

    return EXIT_SUCCESS;      
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

void zeroCounters(int &comparrisonCounter, int &exchangeCounter){
    comparrisonCounter = 0;
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
            cout << setw(10) << a[i];
        }
    }
        else{
        //print first 100
        for(int i = 0; i < n/2; ++i){
            if ( i%10 == 0 ){
            cout << endl;
            }
            cout << setw(10) << a[i]; 
        }
        //print last 100
        cout << endl;
        cout <<"\n      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        for(int i = size - (n/2); i < size; ++i){
            if ( i%10 == 0 ){
                cout << endl;
            }
            cout << setw(10) << a[i]; 
        }
    }
        cout << endl;
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
        comparrisonCounter++;
	    return;
	}else if( lo == hi - 1 ) {
         comparrisonCounter++;
        if (a[lo] > a[hi]) {
            comparrisonCounter++;
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

        comparrisonCounter++;
        while( lo < hi ) {
            /*
             *  Search forward from a[lo] until an element is found that
             *  is greater than the pivot or lo >= hi 
             */
            while (a[lo] <= pivot && lo < hi) {
                comparrisonCounter += 2;
		        lo++;
	        }

            /*
             *  Search backward from a[hi] until element is found that
             *  is less than the pivot, or lo >= hi
             */
            while (pivot <= a[hi] && lo < hi ) {
                comparrisonCounter += 2;
                hi--;
            }

            /*
             *  Swap elements a[lo] and a[hi]
             */
            comparrisonCounter++;
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
    if (size <= 28){
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
        comparrisonCounter++;  
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
        comparrisonCounter++;  
        swap(&a[left], &a[center]);
    }

    if (a[left] > a[right]){
        comparrisonCounter++;  
        swap(&a[left], &a[right]);
    }

    if (a[center] > a[right]){
        comparrisonCounter++;  
        swap(&a[center], &a[right]);
    }
    comparrisonCounter++;  
    swap(&a[center], &a[right - 1]);
    return a[right - 1];
}

void swap(int *a, int *b){
    int temp = *a;
	*a = *b;
	*b = temp;
    exchangeCounter++;
}

 
void mergeSort(int * arr, int l, int r){
    if (l < r){
        comparrisonCounter++;
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        exchangeCounter++;
        // Merge arrays together
        merge(arr, l, m, r);
    }
}

void merge(int * a, int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++){
        L[i] = a[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = a[m + 1+ j];
    }
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            a[k] = L[i];
            i++;
        }else{
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        a[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2){
        a[k] = R[j];
        j++;
        k++;
    }
}

void radixSort(int arr[], int n){
    int m = getMax(arr, n);

    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);

}

void countSort(int arr[], int n, int exp){
    int output[n]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++){
        count[ (arr[i]/exp)%10 ]++;
    }

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }

    // Build the output array
    for (i = n - 1; i >= 0; i--){
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++){
        arr[i] = output[i];
        exchangeCounter++;
    }
}

int getMax(int arr[], int n){
    int mx = arr[0];
    for (int i = 1; i < n; i++){
        comparrisonCounter++;
        if (arr[i] > mx)
            mx = arr[i];
    }
    return mx;
}
