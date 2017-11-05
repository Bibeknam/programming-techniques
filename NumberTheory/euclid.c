#include <stdio.h>

int euclid(int a, int b) {
	if (b == 0) {
		return a;
	} else {
		return euclid(b, a % b);
	}
}

int main(int argc, char* argv[]) {
	int a = 30, b = 21;
	printf("GCD is %d\n", euclid(a, b));
	return 0;
}