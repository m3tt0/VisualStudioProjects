#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE  3

int **prdCart (int *A, int *B);

int main ()
{
	int A[MAX_SIZE] = {1,2,3};
	int B[MAX_SIZE] = {4,5,6};

	int X[MAX_SIZE * MAX_SIZE][2];



	X = prdCart (A,B);



return 0;
}


int **prdCart (int *A, int *B)
{
	int matrix[MAX_SIZE * MAX_SIZE][2];
	int counter = 0;

	for (int i = 0; i < (MAX_SIZE*MAX_SIZE); i++)
	{
			matrix[i][0] = A[counter];
			matrix[i][1] = B[counter];
		counter++;

	}

}
