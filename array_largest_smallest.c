#include <stdio.h>
#include <stdlib.h>

int get_largest(int a[], int n) {
	int i, largest = 0;
	for (i = 0; i < n; i++) {
		if (a[i] > largest) {
			largest = a[i];
		}
	}
	return largest;
}

int get_smallest(int a[], int n) {
	int i, smallest = 2147483647;
	for (i = 0; i < n; i++) {
		if (a[i] < smallest) {
			smallest = a[i];
		}
	}
	return smallest;
}

int main() {
	int n, i, largest, smallest;
	int *a;

	printf("Enter the size of the array: ");
	scanf("%d", &n);

	a = malloc(sizeof(int*) * n);
	printf("Enter the array: \n");

	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	largest = get_largest(a, n);
	printf("The largest number is %d\n", largest);

	smallest = get_smallest(a, n);
	printf("The smallest number is %d\n", smallest);

	return 0;
}