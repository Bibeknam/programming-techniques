#include "dft.h"

void DFT::del_all()
{
    delete input_seq;
    delete output_seq;
}

DFT::DFT(int n)
{
    size = 0;
    input_seq= NULL;
    output_seq = NULL;
    initialize(n);
}

DFT::~DFT()
{
    del_all();
}

void DFT::initialize(unsigned int n, bool del)
{
    if(size != n) {
        size = n;
    pi2 = M_PI * 2.0;
    scale = 1.0/size;
    if(del) {
      del_all();
    }
    input_seq  = new Complex[n];
    output_seq = new Complex[n];
  }
}



Complex* DFT::array_input()
{
    return input_seq;
}

Complex* DFT::array_output()
{
    return output_seq;
}

void DFT::dft1()
{
    double pi2 = -2.0 * M_PI;
    double angleTerm,cosineA,sineA;
    double invs = 1.0 / size;
    for(unsigned int y = 0;y < size;y++) {
        output_seq[y] = 0;
        for(unsigned int x = 0;x < size;x++) {
            angleTerm = pi2 * y * x * invs;
            cosineA = cos(angleTerm);
            sineA = sin(angleTerm);
            output_seq[y].real += input_seq[x].real * cosineA - input_seq[x].imag * sineA;
            output_seq[y].imag += input_seq[x].real * sineA + input_seq[x].imag * cosineA;
        }

    }
}

void DFT::idft1()
{
    double pi2 = 2.0 * M_PI;
    double angleTerm,cosineA,sineA;
    double invs = 1.0 / size;
    for(unsigned int y = 0;y < size;y++) {
        output_seq[y] = 0;
        for(unsigned int x = 0;x < size;x++) {
            angleTerm = pi2 * y * x * invs;
            cosineA = cos(angleTerm);
            sineA = sin(angleTerm);
            output_seq[y].real += input_seq[x].real * cosineA - input_seq[x].imag * sineA;
            output_seq[y].imag += input_seq[x].real * sineA + input_seq[x].imag * cosineA;
        }
        output_seq[y] *= invs;
    }
}
