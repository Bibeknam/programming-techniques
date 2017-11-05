#ifndef FFT_H_INCLUDED
#define FFT_H_INCLUDED

#include "complex.h"

class FFT {

    bool test_pwr2(unsigned int n);
    static int rev_bits(unsigned int index,int size);

    public:
    static Complex* fft1(Complex *, unsigned int , int, bool inverse = false);
    static Complex** fft2(Complex**, int width, int height, bool inverse = false);
};


#endif // FFT_H_INCLUDED
