/*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   Hunt_W11_Complex_Num.h
*/

#pragma once
 
#include <iostream>
 
using namespace std;
 
/* complex number class*/
class ComplexNumber{
private:
    //private variables
    double real;
    double imaginary;
 
public:
 
    /*empty constructor*/
    ComplexNumber();
     
    /* constructor using real and imaginary part as parameter */
    ComplexNumber(double r, double i);
 
    /* constructor using real part as parameter */
    ComplexNumber(double r);
 
    /* returns the double part of the complex num */
    operator double();
 
    /* typecast the complex num real part to int */
    operator int();
 
    /* += operator of two complex number */
    ComplexNumber &operator+= (const ComplexNumber &rhs);
 
    const ComplexNumber operator+ (const ComplexNumber &rhs);
 
    /* equality operator of two complex number. Returns true when both real and imaginary part are same */
    bool operator==(const ComplexNumber &rhs) const;
 
    /* non equality operator of two complex number. Returns true when any of the real or imaginary part are different */
    bool operator!=(const ComplexNumber &rhs) const;
 
    /* subtract rhis from this number and returns it */
    ComplexNumber &operator-= (const ComplexNumber &rhs);
 
    /* subtract rhis from this number and returns it */
    const ComplexNumber operator- (const ComplexNumber &rhs);
 
    /* multily complex num */
    const ComplexNumber operator* (const ComplexNumber &rhs);
 
    /* output stream of complex num */
    friend ostream &operator<<(ostream &out, const ComplexNumber &c){
        out << "(" << c.real << " " << (c.imaginary >= 0 ? "+" : "-") << " " << (c.imaginary >= 0 ? c.imaginary : -1 * c.imaginary) << "i)";
        return out;
    }
 
    /* input stream of complex num */
    friend istream &operator>>(istream &in, ComplexNumber &c){
        cout << "\nPlease enter real part: " ;
        in >> c.real;
 
        cout << "Please enter imaginary part: ";
        in >> c.imaginary; 
        return in;
    }
};