#include <iostream>
#include <ctime>
#include "fft.h"


int powerOfTwo(int n) {
   int i = 0, m = 1;
   while (m < n) {
     m <<= 1;
     ++i;
   }
   return i;
}

int main()
{
    unsigned int r,c, temp1, temp2;
    double real, imag;
    clock_t t1;
    Complex **input_seq;
    Complex **output_seq;
    cout<<"Enter the size of DFT: ";
    cin>>r>>c;
    temp1 = r;
    temp2 = c;
    int log2w = powerOfTwo(r);
    int log2h = powerOfTwo(c);

    r = 1 << log2w;
    c = 1 << log2h;

    input_seq = new Complex*[r];
    for(unsigned int j = 0; j < r; j++){
        input_seq[j] = new Complex[c];
    }

    for(unsigned int i = 0; i < temp1; i++){
            for(unsigned int j = 0; j <temp2; ++j){
                cin>>real>>imag;
                input_seq[i][j] = Complex(real,imag);
            }
    }

    t1 = clock();
    output_seq = FFT::fft2(input_seq,r, c);

    cout<<endl<<"The DFT of the given sequence is "<<endl<<endl;
    for(unsigned int i = 0; i < r; i++)
    {
        for(unsigned int j = 0; j < c; j++){
                cout<<output_seq[i][j]<<"\t";
        }
        cout<<endl;

    }
    cout<<endl;
    cout.precision(6);
    cout<<"The total time taken by this algorithm is "<<(double)(clock()-t1)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;

}
