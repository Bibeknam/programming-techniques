#include <stdio.h>
#include <stdlib.h>

void mat_product(unsigned long long a[], unsigned long long b[], unsigned long long result[]) {
	// assuming matrix is always 2 x 2
	result[0] = a[0] * b[0] + a[1] * b[2];
	result[1] = a[0] * b[1] + a[1] * b[3];
	result[2] = a[2] * b[0] + a[3] * b[2];
	result[3] = a[2] * b[1] + a[3] * b[3];
}

int main(int argc, char* argv[]) {
	int n, i, temp, len;
	unsigned long long bin[1000], **fib;
	unsigned long long result[4];
	if (argc != 2) {
		printf("Usage: outputfile n\n");
		exit(1);
	}

	n = atoi(argv[1]);
	temp = n;
	len = 1;
	while(n / 2 > 0) {
		bin[len - 1] = n % 2;
		n = n/2;
		len++;
	}
	if (n == 1) {
		bin[len - 1] = 1;
	}

	fib = (unsigned long long**) malloc(sizeof(unsigned long long*) * len);
	for (i = 0; i < len; i++) {
		fib[i] = (unsigned long long*) malloc(sizeof(unsigned long long*)*4);
	}

	fib[0][0] = 0;
	fib[0][1] = 1;
	fib[0][2] = 1;
	fib[0][3] = 1;

	for (i = 1; i < len; i++) {
		mat_product(fib[i - 1], fib[i - 1], fib[i]);
	}

	result[0] = fib[len - 1][0];
	result[1] = fib[len - 1][1];
	result[2] = fib[len - 1][2];
	result[3] = fib[len - 1][3];
	
	for(i = 0; i < len - 1; i++) {
		if (bin[i] == 1) {
			mat_product(fib[i], result, result);
		}
	}

	printf("F(%d) => %llu\n", temp, result[1]);

	return 0;
}