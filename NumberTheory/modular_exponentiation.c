#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void decimal_to_binary(int op1, int aOp[]){
    int result, i = 0;
    do{
        result = op1 % 2;
        op1 /= 2;
        aOp[i] = result;
        i++;
    }while(op1 > 0);
}

int modular_exponentiation(int a, int b, int n){
	int *bb;
	int count = 0, c = 0, d = 1, i;

	// find out the size of binary b
	count = (int) (log(b)/log(2)) + 1;

	bb = (int *) malloc(sizeof(int*) * count);
	decimal_to_binary(b, bb);

	for (i = count - 1; i >= 0; i--) {
		c = 2 * c;
		d = (d*d) % n;
		if (bb[i] == 1) {
			c = c + 1;
			d = (d*a) % n;
		}
	}
	return d;
}

int main(int argc, char* argv[]) {
	int a = 65, b = 17, n = 3233, d;
	d = modular_exponentiation(a, b, n);
	printf("Result = %d\n", d);
	return 0;
}