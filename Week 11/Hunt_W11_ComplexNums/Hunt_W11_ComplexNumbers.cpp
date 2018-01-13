/*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   Hunt_W11_Complex_Num.cpp
*/
#include <iostream>
#include "Complex_Num.cpp"
 
using namespace std;
 
int main(){
 
    cout << "\n~~~~~~~~~~~~ Complex Numbers Homework - Advanced C++ Week 11 ~~~~~~~~~~~~~~" << endl;

    ComplexNumber a;
    cout << "\nPlease enter first complex number";
    cin >> a;
 
    cout << "\ta is " << a << endl;
 
    ComplexNumber b;
    cout << "\nPlease enter second complex number";
    cin >> b;
    cout << "\tb is " << b << endl;
 
    cout << "\na and b the same?  : " << (a == b ? "yes" : "no") << endl;
    cout << "a and b different? : " << (a != b ? "yes" : "no") << endl;
 
    ComplexNumber c = a + b;
    cout << "\nc = (a + b) is : " << c << endl;
    c += a;
    cout << "c += a is: " << c << endl;
    c -= b;
    cout << "c -= b is: " << c << endl;
    c = a - b;
    cout << "c = a - b is: " << c << endl;
    c = a * b;
    cout << "c = a * b is: " << c << endl;
 
    ComplexNumber x, y, z;
    cout  << "\nCreating complex numbers x, y, z...." << endl;
    cout << "(x = y = z = c) = " << (x = y = z = c) << endl;
 
    double d = 3.333;
    cout << "\nCasting... (Complex num) " << (ComplexNumber)d << endl;
    cout << "Casting... (double) " << (double)c << endl << endl;;
 
    return 0;
}