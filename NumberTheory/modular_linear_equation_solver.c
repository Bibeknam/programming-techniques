#include <stdio.h>
#include <math.h>

typedef struct {
	int d;
	int x;
	int y;
} EE;

EE extended_euclid(int a, int b) {
	EE ee1, ee2, ee3;
	if (b == 0) {
		ee1.d = a;
		ee1.x = 1;
		ee1.y = 0;
		return ee1;
	} else {
		ee2 = extended_euclid(b, a % b);
		ee3.d = ee2.d;
		ee3.x = ee2.y;
		ee3.y = ee2.x - floor(a / b) * ee2.y;
		return ee3;
	}
}

// Copied from 
// https://stackoverflow.com/questions/11720656/modulo-operation-with-negative-numbers
int modulo(int x, int N){
    return (x % N + N) % N;
}

void modular_linear_equation_solver(int a, int b, int n){
	EE ee;
	int x0, i;
	ee = extended_euclid(a, n);
	if (b % ee.d == 0) {
		x0 = modulo(ee.x * (b/ee.d), n);
		for (i = 0; i < ee.d; i++) {
			printf("Solution %d: %d\n", i + 1, modulo(x0 + i * (n / ee.d), n));
		}
	} else {
		printf("No Solutions\n");
	}
}

int main(int argc, char* argv[]) {
	int a = 17, b = 1, n = 60;
	modular_linear_equation_solver(a, b, n);
	return 0;
}