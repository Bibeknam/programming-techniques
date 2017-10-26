#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int rows, columns, i, j;
	int **matrix1, **matrix2;

	if (argc != 3) {
		printf("Usage: outputfile rows columns\n");
		exit(1);
	}

	rows = atoi(argv[1]);
	columns = atoi(argv[2]);

	// allocate memory for matrices
	matrix1 = (int**) malloc (sizeof(int*) * columns);
	for (i = 0; i < columns; i++) {
		matrix1[i] = (int*) malloc(sizeof(int*) * rows);
	}

	matrix2 = (int**) malloc (sizeof(int*) * columns);
	for (i = 0; i < columns; i++) {
		matrix2[i] = (int*) malloc(sizeof(int*) * rows);
	}

	// get matrices from user
	printf("Enter the first matrix: \n");
	for(i = 0 ; i < rows; i++)
        for(j = 0; j < columns; j++)
            scanf("%d", &matrix1[i][j]);
    
    printf("Enter the second matrix: \n");
	for(i = 0 ; i < rows; i++)
        for(j = 0; j < columns; j++)
            scanf("%d", &matrix2[i][j]);

    // add two matrices
    for(i = 0 ; i < rows; i++){
        for(j = 0; j < columns; j++)
            matrix2[i][j] = matrix1[i][j] + matrix2[i][j];
    }

    // display the result
    printf("The sum of the matrix is :\n");
    for(i = 0 ; i < rows; i++){
        for(j = 0; j < columns; j++){
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    return 0;

}