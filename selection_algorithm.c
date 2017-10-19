#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int median_1(int a[]) {
	return a[0];
}

int median_2(int a[]) {
	return a[1];
}

int median_3(int a[]) {
	int temp;
	if (a[0] < a[1]) {
		swap(&a[0], &a[1]);
	}
	if (a[0] > a[2]) {
		a[0] = a[1];
		a[1] = a[2];
	} else {
		return a[0];
	}
	if (a[0] > a[1]) {
		return a[0];
	} else {
		return a[1];
	}
}

int median_4(int a[]) {
	int temp1, temp2;
	if (a[0] < a[1]) {
		swap(&a[0], &a[1]);
	}
	if (a[2] > a[3]) {
		swap(&a[1], &a[2]);
	} else {
		temp1 = a[1];
		temp2 = a[2];
		a[1] = a[3];
		a[2] = temp1;
		a[3] = temp2;
	}
	if (a[0] > a[1]) {
		a[0] = a[1];
		a[1] = a[2];
	} else {
		a[1] = a[3];
	}
	if (a[0] > a[1]) {
		return a[0];
	} else {
		return a[1];
	}
}

// six comparisions
int median_5(int a[]) {
	int temp1, temp2;
	if (a[0] < a[1]) {
		swap(&a[0], &a[1]);
	} 
	if (a[2] > a[3]) {
		swap(&a[1], &a[2]);
	} else {
		temp1 = a[1];
		temp2 = a[2];
		a[1] = a[3];
		a[2] = temp1;
		a[3] = temp2;
	}
	if (a[0] > a[1]) {
		a[0] = a[1];
		a[1] = a[3];
		a[3] = a[4];
	} else {
		a[1] = a[2];
		a[2] = a[3];
		a[3] = a[4];
	}
	if (a[2] > a[3]) {
		swap(&a[1], &a[2]);
	} else {
		temp1 = a[1];
		temp2 = a[2];
		a[1] = a[3];
		a[2] = temp1;
		a[3] = temp2;
	}
	if (a[0] > a[1]) {
		a[0] = a[1];
		a[1] = a[2];
	} else {
		a[1] = a[3]; 
	}
	if(a[0] > a[1]) {
		return a[0];
	} else {
		return a[1];
	}
}

int median(int a[], int n){
	switch(n) {
		case 1: 
		return median_1(a);
		break;
		case 2:
		return median_2(a);
		break;
		case 3:
		return median_3(a);
		break;
		case 4:
		return median_4(a);
		break;
		case 5:
		return median_5(a);
		break;
		default:
		break;
	}
	return -1;
}

// select method returns the kth smallest element
// median is the n/2 th smallest element
// This function runs in linear time
int select(int k, int a[], int n) {
	int **subarrays, *medians, *left, *right;
	int i, j, l, m,columns, pivot, len_l = 0, len_r = 0;

	if (n == 1) {
		return a[0];
	}

	columns = ceil(n / 5.0);

	subarrays = (int**)malloc(sizeof(int*)*columns);
	for (i=0;i<columns;i++){
		subarrays[i] = (int*)malloc(sizeof(int)*5);
	}

	medians = (int*) malloc(sizeof(int*) * columns);

	for (i = 0, j = 0; i < n; i = i + 5, j++) {
		if (j == columns) {
			for (l = 0; l < n % 5; l++) {
				subarrays[j][l] = a[i + l];
			}
		} else {
			for (l = 0; l < 5; l++) {	
				subarrays[j][l] = a[i + l];
			}
		}
	}

	// calculate local medians
	for (i = 0; i < columns; i++) {
		if (n % 5 != 0 && i == columns - 1) {
			medians[i] = median(subarrays[i], n % 5);
		} else {
			medians[i] = median(subarrays[i], 5);
		}
	}

	if (columns <= 5) {
		pivot = median(medians, columns);
	} else {
		pivot = select(columns/2, medians, columns);
	}

	// create right and left array
	for (i = 0; i < n; i++) {
		if (a[i] > pivot) {
			len_r++;
		} 
		if (a[i] < pivot) {
			len_l++;
		}
	}

	left = (int*) malloc(sizeof(int*) * len_l);
	right = (int*) malloc(sizeof(int*) * len_r);

	l = 0, m = 0;
	for (i = 0; i < n; i++) {
		if (a[i] > pivot){
			right[l] = a[i];
			l++;
		} 
		if (a[i] < pivot) {
			left[m] = a[i];
			m++;
		}

	}
	if (len_l == k - 1) {
		return a[0];
	}
	if (len_l > k - 1) {
		return select(k, left, len_l);
	} 
	if (len_l < k - 1) {
		return select(k - len_l - 1, right, len_r);
	}
	return -1;
}

int main() {
	int array[] = {8,7,12,13,3,4,5,6,19,20,9,10,11,14,15,16,17,18,1,2};
	printf("Median is %d\n", select(10, array, 20));
}