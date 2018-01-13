/*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   Hunt_W11_Complex_Num.cpp
*/

#include <iostream>
#include "Complex_Num.h"
 
ComplexNumber::ComplexNumber(){
    real = 0.0;
    imaginary = 0.0;
}
ComplexNumber::ComplexNumber(double r, double i){
    real = r;
    imaginary = i;
}
ComplexNumber::ComplexNumber(double r){
    real = r;
    imaginary = 0.0;
}
 
ComplexNumber::operator double(){
    return real;
}
 
ComplexNumber::operator int(){
    return (int)real;
}
 
ComplexNumber & ComplexNumber::operator+= (const ComplexNumber &rhs){
    real += rhs.real;
    imaginary += rhs.imaginary;
    return *this;
}
 
const ComplexNumber ComplexNumber::operator+ (const ComplexNumber &rhs){
    ComplexNumber result = *this;
    result += rhs;
    return result;
}
 
bool ComplexNumber::operator==(const ComplexNumber &rhs) const {
    return (real == rhs.real && imaginary == rhs.imaginary);
}
 
bool ComplexNumber::operator!=(const ComplexNumber &rhs) const {
    return !(*this == rhs);
}
 
ComplexNumber &ComplexNumber::operator-= (const ComplexNumber &rhs){
    real -= rhs.real;
    imaginary -= rhs.imaginary;
    return *this;
}
 
const ComplexNumber ComplexNumber::operator- (const ComplexNumber &rhs){
    ComplexNumber result = *this;
    result -= rhs;
    return result;
}
 
const ComplexNumber ComplexNumber::operator* (const ComplexNumber &rhs){
 
    double r = 0.0;
    double i = 0.0;
    r = (real * rhs.real) - (imaginary*rhs.imaginary);
    i = (real * rhs.imaginary) + (imaginary * rhs.real);
    real = r;
    imaginary = i;
    return *this;
}