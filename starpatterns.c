#include <stdio.h>
#include <stdlib.h>

void pattern_1(int n) {
	int i, j;

	for(i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
}

void pattern_2(int n) {
	int i, j;

	for(i = 0; i < n; i++) {
		for(j = 0; j < n - i - 1; j++) {
			printf(" ");
		}
		for (j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
}

void pattern_3(int n) {
	int i, j;

	for(i = 0; i < n; i++) {
		for(j = 0; j < n - i - 1; j++) {
			printf(" ");
		}
		for (j = 0; j <= 2 * i; j++) {
			printf("*");
		}
		printf("\n");
	}
}

void pattern_4(int n) {
	int i, j;
	for(i = n - 1; i >= 0; i--) {
		for (j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
}

void pattern_5(int n) {
	int i, j;
	for(i = n - 1; i >= 0; i--) {
		for(j = 0; j < n - i - 1; j++) {
			printf(" ");
		}
		for (j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
}

void pattern_6(int n) {
	int i, j;

	for(i = n - 1; i >= 0; i--) {
		for(j = 0; j < n - i - 1; j++) {
			printf(" ");
		}
		for (j = 0; j <= 2 * i; j++) {
			printf("*");
		}
		printf("\n");
	}
}

void pattern_7(int n) {
	int i, j;

	for(i = 0; i < n; i++) {
		for(j = 0; j < n - i; j++) {
			printf(" ");
		}
		for (j = 0; j <= 2 * i; j++) {
			printf("*");
		}
		printf("\n");
	}
	for(i = (n - 1) ; i >= 0; i--) {
		for(j = 0; j < n - i; j++) {
			printf(" ");
		}
		for (j = 0; j <= 2 * i; j++) {
			printf("*");
		}
		printf("\n");
	}
}

void pattern_8(int n) {
	int i, j, k;
	for (i = 0; i < n; i++) {
		printf("\n");
		for(k = 0; k < n - i; k++) {
			printf("*");
		}

		for(k = 2*i; k > 0; k--) {
			printf(" ");
		}

		for(k = 0; k < n - i; k++) {
			printf("*");
		}
		

	}
	for (i = 0; i <= n; i++) {
		for(k = 0; k < i; k++) {
			printf("*");
		}

		for(k = 0; k < 2* (n - i); k++) {
			printf(" ");
		}

		for(k = 0; k < i; k++) {
			printf("*");
		}
		printf("\n");
	}
}

int main(int argc, char *argv[]) {
	int n;
	if (argc != 2) {
		printf("Usage: outputfile n\n");
		exit(1);
	}

	n = atoi(argv[1]);

	pattern_1(n);
	printf("\n");
	pattern_2(n);
	printf("\n");
	pattern_3(n);
	printf("\n");
	pattern_4(n);
	printf("\n");
	pattern_5(n);
	printf("\n");
	pattern_6(n);
	printf("\n");
	pattern_7(n);
	printf("\n");
	pattern_8(n);
}