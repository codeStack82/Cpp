 /*
* Tyler Hunt
* Advanved C++
* OCCC Fall 2017
* Due: 10/1/17
*/


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

void f(int p[]);

int main(){
    string i1 = "\t";
    string i2 = "\t\t";

    cout << "\n~~~~~~~~~~~~ Pointers Homework - Advanced C++ Week 3 ~~~~~~~~~~~~" << endl;

    cout << "\nChapter 7 : R7.2 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;//~~~~~Done
        cout << "Write the code that create and set four pinter variables " << endl;
        cout << "a, b, c, and d to show each of these posibilities.\n" << endl;
        int validObj = 1981838;
        int randomObj =  rand() % 100;

        int* a = &validObj;
        //delete a;  //comment out causes error
        int* b = a;

        int * c = NULL;
        int * d = &randomObj;

        cout << "\tint * a = " << a << endl;
        cout << "\tint * b = " << "error: Abort trap: 6" << endl;
        cout << "\tint * c = " << c << endl;
        cout << "\tint * d = " << d << endl;

    cout << "\nChapter 7 : R7.3 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;//~~~~~Done
        cout << i1 << "What happens if you dereference each of the four pointers that you" << endl;
        cout << i1 << "created in Exercise R7:2? Write a test program if your not sure." << endl;

        cout << "\t*a = " << *a << endl;
        cout << "\t*b = " << *b << endl;
        cout << "\t*c = " << "error: Segmentation fault: 11" << endl;
        cout << "\t*d = " << *d << endl;

    cout << "\nChapter 7 : R7.4 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl; //~~~~~Done
         cout << "What happens if you forget to delete an object that you obtain from the heap?" << endl;
            cout << i1 << "Conceptually, if you don't delete an object it would stay in memory until you program " << endl;
            cout << i1 << "terminates. Then afterwords the OS would have to clean up the used memory on the heap\n" << endl;

         cout << i1 << "What happens if you delete it twice?" << endl;
            cout << i1 << "When an object is deleted twice is what is called undefined behavior." << endl;
            cout << i1 << "There are no guarantees, it might not crash in one instance and in another it might" << endl;
            

    cout << "\nChapter 7 : R7.6 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;//~~~~~Done
        cout << "Pointers are values that have a numerical value. You can print out the " << endl;
        cout << "value of a pointer as cout << (unsigned long)(p). Write a program to " << endl;
        cout << "compare p, p + 1, and q + 1, where p is an int and q is a double*.\n " << endl;
       
            int m = 645459;
            int* p = &m;
            cout << i1 << "p   = " << (unsigned long)(p) << endl;
            cout << i1 << "p+1 = " << (unsigned long)(p+1) << endl;
                cout << i1 << "Difference of: " << (unsigned long)(p+1) - (unsigned long)(p) << " bits\n"<< endl;

            double n = 71.2393;
            double* q = &n;
            cout << i1 << "q   = " << (unsigned long)(q) << endl;
            cout << i1 << "q+1 = " << (unsigned long)(q+1) << endl;
            cout << i1 << "Difference of: " << (unsigned long)(q+1) - (unsigned long)(q) << " bits\n" << endl;

        cout << "Explain the results" << endl;
            cout << i1 << "Show's the size differences between the int* pointers(p and p+1) and the double* pointer(q and q+1)." << endl;

    cout << "\nChapter 7 : R7.8 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;//~~~~~Done
        cout << "\tWhich of the folowing assiginments are legal in C++" << endl;
           int values[] = {1,2,3,4,5,5,6,7,8,9,10,11,12,13,14,15};
           f(values);

    cout << "\nChapter 7 : R7.9 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;//~~~~~Done
         cout << "Given the definitions, double values_9[] = {2,3,5,7,11,13} and double* p = values + 3, " << endl;
         cout << "explain the meaning of the following expressions:" << endl;

         double values_R79[] = {2,3,5,7,11,13};
         double* p_R79 = values_R79 + 3;

        cout << i1 << "a) values_R79[1] \t"     << values_R79[1]        << ", is the value in the array at index 1" << endl;
        cout << i1 << "b) values_R79 + 1\t"     << values_R79 + 1       << ", uses point arithmatic to move to the next memory in that location " << endl;
        cout << i1 << "c) *(values_R79 + 1)\t"  << *(values_R79 + 1)    << ", dereferences the pointer at the array index of 1 " << endl;
        cout << i1 << "d) p[1]\t\t\t"           << p_R79[1]             << ", p is a pointer to the 3 index in the array and p[1] is the value at index 1 in the array" << endl;
        cout << i1 << "e) p + 1\t\t"            << p_R79 + 1            << ", p + 1 is a pointer to the next index" << endl;
        cout << i1 << "f) p - values_R79\t"                             << ", error: 'int *' and 'double *' are not pointers to compatible types" << endl;


    cout << "\nChapter 7 : R7.10 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;//~~~~~Done
        cout << "Explain the meaning of the following expressions:" << endl;  
            cout << i1 << "a) \"Harry\" + 1\t\t" << "Harry" + 1             << "\t, moves the pointer to the first index in the string" << endl;
            cout << i1 << "b) *(\"Harry\" + 2)\t"     << *("Harry" + 2)     <<  "\t, is a dereferenced pointer the value at the second index " << endl;
            cout << i1 << "c) \"Harry\"[3]\t\t" << "Harry"[3]               <<  "\t, is the value at the third index in the string" << endl;
            cout << i1 << "d) [4]\"Harry\" \t\t"<< "error->"                             <<  "\t, expected expression" << endl;


    cout << "\n~~~~~~~~~~~~ Pointers Homework - Advanced C++ Week 3  Complete ~~~~~~~~~~~~" << endl;

    return EXIT_SUCCESS; 
}

// Chapter 7 : R7.8
void f(int p[])
{
    int* q;
    const int* r;
    int s[10];
    //p = q;
    cout << "\t\tp = q: " << "Legal\t\t" << &p <<  endl;
    //p = r;
    cout << "\t\tp = r: " << "Not Legal\t" << "error: assigning to 'int *' from incompatible type 'const int *'" <<endl;
    //p = s;
    cout << "\t\tp = s: " << "Legal\t\t" << &p << endl;
    //q = p;
    cout << "\t\tq = p: " << "Legal\t\t" << &q << endl;
    //q = r;
    cout << "\t\tq = r: " << "Not Legal\t" << "error: assigning to 'int *' from incompatible type 'const int *'" << endl;
    //q = s;
    cout << "\t\tq = s: " << "Legal\t\t" << &q << endl;
    //r = p;
    cout << "\t\tr = p: " << "Legal\t\t" << &r << endl;
    //r = q;
    cout << "\t\tr = q: " << "Legal\t\t" << &r << endl;
    //r = s;
    cout << "\t\tr = s: " << "Legal\t\t" << &r << endl;
    //s = p;
    cout << "\t\ts = p: " << "Not Legal\t" << "error: array type 'int [10]' is not assignable" <<  endl;
    //s = q;
    cout << "\t\ts = p: " << "Not Legal\t" << "error: array type 'int [10]' is not assignable" <<  endl;
    //s = r;
    cout << "\t\tr = s: " << "Legal\t\t" << "error: array type 'int [10]' is not assignable" << endl;

}