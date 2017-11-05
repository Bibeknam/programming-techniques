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
		printf("%d %d %d %d %d\n", a, b, ee1.d, ee1.x, ee1.y);
		return ee1;
	} else {
		ee2 = extended_euclid(b, a % b);
		ee3.d = ee2.d;
		ee3.x = ee2.y;
		ee3.y = ee2.x - floor(a / b) * ee2.y;
		printf("%d %d %d %d %d\n", a, b, ee3.d, ee3.x, ee3.y);
		return ee3;
	}
}

int main(int argc, char* argv[]) {
	int a = 287, b = 288;
	EE ee = extended_euclid(a, b);
	printf("GCD = %d\n", ee.d);
	printf("x = %d\n", ee.x);
	printf("y = %d\n", ee.y);
	return 0;
}