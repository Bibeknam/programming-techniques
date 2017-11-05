#include "fft.h"

// reverse bits in provided index
 int FFT::rev_bits(unsigned int index,int size)
{
    int rev = 0;
    for(;size > 1; size>>=1)
    {
        rev = (rev << 1) | (index & 1);
        index >>= 1;
    }
    return rev;
}


Complex* FFT::fft1(Complex *data, unsigned int size, int log2n,  bool inverse)
{
        double angle, wtmp, wpr, wpi, wr, wi;
        int n = 1, n2;
        double pi2 = M_PI * 2.0;
        double scale = 1.0/size;
        Complex tc;

        for (int k = 0; k < log2n; ++k)
        {
            n2 = n;
            n <<= 1;
            angle = (inverse)?pi2/n:-pi2/n;
            wtmp=sin(0.5*angle);
            wpr = -2.0*wtmp*wtmp;
            wpi = sin(angle);
            wr = 1.0;
            wi = 0.0;

            for (int m=0; m < n2; ++m) {
                for (unsigned int i=m; i < size; i+=n) {
                    int j = i+n2;
                    tc.real = wr * data[j].real - wi * data[j].imag;
                    tc.imag = wr * data[j].imag + wi * data[j].real;
                    data[j] = data[i] - tc;
                    data[i] += tc;
                }
                wr=(wtmp=wr)*wpr-wi*wpi+wr;
                wi=wi*wpr+wtmp*wpi+wi;
            }
        }
        if(inverse) {
            for(int i = 0;i < n;i++) {
                data[i] *= scale;
            }
        }
        return data;
}

Complex** FFT::fft2(Complex **data, int r, int c, bool inverse)
{
    Complex *row = new Complex[r];
    Complex *column = new Complex[c];
    int log2w = r >> 1;
    int log2h = c >> 1;

    // Perform FFT on each row
    for (int y = 0; y < c; ++y) {
      for (int x = 0; x < r; ++x) {
        int rb = rev_bits(x, r);
        row[rb] = data[x][y];
      }
      row = fft1(row, r, log2w, inverse);
      for (int x = 0; x < r; ++x) {
        data[x][y] = row[x];
      }
    }

    // Perform FFT on each column
    for (int x = 0;x < r; ++x) {
      for (int y = 0; y < c; ++y) {
            int rb = rev_bits(y, c);
            column[rb] = data[x][y];
      }
      column = fft1(column, c, log2h, inverse);
      for (int y = 0; y < c; ++y) {
        data[x][y] = column[y];
      }
    }
    return data;
}

