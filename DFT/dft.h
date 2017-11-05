#ifndef DFT_H_INCLUDED
#define DFT_H_INCLUDED

#include "complex.h"

class DFT {
  unsigned int size;
  double scale;

  void del_all();
  void initialize(unsigned int n, bool del=false);

  public:
      Complex *input_seq;
    Complex *output_seq;

    double pi2;
    DFT(int n);
    ~DFT();

    Complex* array_input();
    Complex* array_output();
    void dft1();
    void idft1();
};

#endif // DFT_H_INCLUDED
