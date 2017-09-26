/*
* Tyler Hunt
* Advanved C++
* OCCC Fall 2017
* Assignment 2 - PostFix Calculator
* Class Demo Code: 9/25/17
*/

#include <iostream>
#include <climits> 
using namespace std;

uint64_t fact_loop(int n);
uint64_t fact_rec(int n);
uint64_t fib_loop(int n);
uint64_t fib_rec(int n);

//main accepts int size (argc) and array of argv
int main(int argc, const char* argv[]){

    ////Read in values from the main (i.e. from the command prompt)
    // cout << "argc is: " << argc << endl;
    // for(int i = 0; i < argc; ++i){
    //     cout << argv[i] << endl;
    // }

    int n;    

    // uint64_t x;
    // cout << "size of uint64_t is " << sizeof(x) << endl;

    if(argc == 2){         //if user gave one cmd line prompt
        n = atoi(argv[1]);
    }else{
        cout << "Enter a number: ";
        cin >> n;
    }

    // cout << n << " != " << fact_loop(n) << endl;
    // cout << n << " != " << fact_rec(n) << endl;
    // cout << "fib loop: " << fib_loop(n) << endl;
    cout << "fib rec: " << fib_rec(n) << endl;

    return 0;
}
//Note: replace uint64_t with __int64 in windows

uint64_t fact_loop(int n){
    //assert(n > 0);
    uint64_t result = 1;
    if(n > 1){
        for(int i = 1; i <= n; ++i){
            result *= i;
        }
    }
    return result;
}

uint64_t fact_rec(int n){
    uint64_t result; 
    if(n > 0){
        result = n * fact_rec(n - 1);
    }
    return result;
}

uint64_t fib_loop(int n){
    uint64_t result = 1;
    uint64_t num1   = 1;
    uint64_t num2   = 1;
    if(n > 2){
        for (uint64_t i = 3; i <= n; i++) {
            num1 = num1 + num2;
            num2 = num1 - num2;
            
            result = num1;
        }
    }

     return result;
}

uint64_t fib_rec(int n){
    uint64_t result = 1;
    if(n > 2){
        result = fib_rec(n -1) + fib_rec(n -2);
    }
   
    return result;
}



/* Notes
    - Very big numbers in c++ use unsigned Long long 
    - #include <climits>  <-Library where the limits and standard sizes for various types are stored
    - The factorial of 0 is 1  (0! = 1)
    - Possibly submit .exe file with future assignment if it has cmd line input params
    
    ***What is recursion - a method that calls itself with a subset of the original problem!!! Test question!
        ** What are the 2 pieces of a recursive algorythm 
            ** Base case and the recursive case
    
    Sequential search O(n)  - linear algorythm
    Bubble sort theta(n^2)  - Quadratic algorythm


                temporial       spatial
    fact_loop   Thete(n)        Theta(1)
    fact_rec    Theta(n)        Theta(n)
    fib_loop    Theta(n)        Theta(1)
*/