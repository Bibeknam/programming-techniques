#include "complex.h"

Complex::Complex()
{
    real = 0;
    imag = 0;
}

Complex::Complex(const Complex &v)
{
    real = v.real;
    imag = v.imag;
}

Complex::Complex(const double &real, const double &imag)
{
    this->real = real;
    this->imag = imag;
}

void Complex::operator=(Complex v)
{
    real = v.real;
    imag = v.imag;
}


void Complex::operator=(double v)
{
    real = v;
    imag = v;
}

Complex Complex::operator*(double v)
{
    return Complex(real*v, imag*v);
}

Complex Complex::operator+(Complex v)
{
    return Complex(real+v.real, imag+v.imag);
}

Complex Complex::operator-(Complex v)
{
    return Complex(real-v.real, imag-v.imag);
}

Complex Complex::operator*(Complex v)
{
    return Complex(real*v.real - imag*v.imag, real*v.imag + imag*v.real);
}

Complex* Complex::operator+=(Complex v)
{
    real += v.real;
    imag += v.imag;
    return this;
}

Complex* Complex::operator-=(Complex v)
{
    real -= v.real;
    imag -= v.imag;
    return this;
}

void Complex::operator*=(Complex v)
{
    real *= v.real;
    imag *= v.imag;
}

void Complex::operator*=(double v)
{
    real *= v;
    imag *= v;
}


double Complex::mag()
{
    return sqrt(real*real + imag*imag);
}

double Complex::squaredSum()
{
    return real*real + imag*imag;
}

double Complex::angle()
{
    double a = atan2(real, imag);
    if(a < 0) {
        a = (M_PI * 2) + a;
    }
    return a;
}

ostream& operator<<(ostream& output, const Complex& v) {
    output.setf(ios::fixed, ios::floatfield);
    output.precision(2);
    if(abs(v.imag) > 0.001){
        if(v.imag < 0)
            output  << v.real << " - " << abs(v.imag)<<"i";
        else
            output  << v.real << " + " << abs(v.imag)<<"i";
    }else{
        if (abs(v.real) < 0.001)
            output << abs(v.real);
            else
                output << v.real;
    }
	return output;
}
