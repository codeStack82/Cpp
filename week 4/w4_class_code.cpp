/*
* Tyler Hunt
* Advanved C++
* OCCC Fall 2017
* Assignment 2 - PostFix Calculator
* Class Demo Code: 9/25/17
*/

#include <iostream>
#include <climits> 
#include <cctype> //use for char checking
#include <ctime>
using namespace std;

uint64_t fact_loop(int n);
uint64_t fact_rec(int n);
uint64_t fib_loop(int n);
uint64_t fib_rec(int n);
uint64_t fib_memo(int n);

uint64_t * memo; // memo pointer array - dynamic array

//main accepts int size (argc) and array of argv
int main(int argc, const char* argv[]){

    // Read in values from the main (i.e. from the command prompt)
        // cout << "argc is: " << argc << endl;
        // for(int i = 0; i < argc; ++i){
        //     cout << argv[i] << endl;
        // }
    // Note: This test show that argv[0] print your current working directory....so the first value from the
    // command prompt is actually the second argv array value....silly, if you ask me!

    
    //Note: ignore the below commented code, I was just testing different int type on my mac
        // uint64_t x;
        // cout << "size of uint64_t is " << sizeof(x) << endl;

    int n;  
    if(argc == 2){         //if user gave one cmd line prompt
        n = atoi(argv[1]);
    }else{
        cout << "Enter a number: ";
        cin >> n;
    }

    //Build timer using <ctime> library
    clock_t start;
    clock_t finish;
    start = clock();        //Start timer

    // cout << n << " != " << fact_loop(n) << endl;
    // cout << n << " != " << fact_rec(n) << endl;
    // cout << "fib loop: " << fib_loop(n) << endl;
    // cout << "fib rec: " << fib_rec(n) << endl;

    memo = new uint64_t[n+1];

    //initialize array with zero's 
    for(int i = 0; i < n+1; i++){
        memo[i] = 0;
    } 

    cout << "fib memo: " << fib_memo(n) << endl;

    finish = clock();       //Stop timer
    cout << "Elapsed time is: ~" << ((finish-start) / CLOCKS_PER_SEC) << endl;

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

uint64_t fib_memo(int n){
    uint64_t result = 1;

    if(n > 2){
        if(memo[n] != 0){
            result = memo[n];
        }else{
            result = fib_rec(n - 1) + fib_rec(n - 2);
            memo[n] = result;               //make a note of the last fib num
        }
    }
    return result;
}

/* Notes
    - Very big numbers in c++ use unsigned long long 64 bit ints (__int64 for windows) and (uint64_t for Unix) 
        -int types have to be changed out from __int64 to uint64_t 
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
    fib_rec     Theta(2^n)      Theta(2^n)
    fib_memo    Thete(n)        Theta(1)


    Homework - Palindromes use recursive algorythm - preprocess ()
        -1) figure out what the base cases are (if length is 0 or 1)
        -2) check first and last char (then compare them)
        -3) if true then then pop them off and continue, if false then false
        use pointers to solve  <cctype> isalnum.....
            basically same as the adv java hw
*/