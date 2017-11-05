#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#include <iostream>
#include <cmath>

using namespace std;

class Complex
{
public:
    double real;
    double imag;
public:
    Complex();
    Complex(const Complex &v);
    Complex(const double &real, const double &imag);
    void operator = (Complex v);
    void operator = (double v);
    Complex operator - (Complex v);
    Complex operator + (Complex v);
    Complex operator * (Complex v);
    Complex operator * (double v);
    void operator *= (Complex v);
    void operator *= (double v);
    Complex* operator += (Complex v);
    Complex* operator -= (Complex v);
    void operator /= (Complex v);
    double mag();
    double squaredSum();
    double angle();

};

ostream& operator<<(ostream& output, const Complex& v);

#endif // COMPLEX_H_INCLUDED
