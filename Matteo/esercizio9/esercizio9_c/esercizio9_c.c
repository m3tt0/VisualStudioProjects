//Scrivere un programma in linguaggio C che:
//1. Definisca una matrice mxn di valori float i cui valori sono generati casualmente fra 0 e 1 e lavisualizzi.
//2. Definisca una seconda matrice (di valori float) opportunamente dimensionata i cui valori sonogenerati casualmente fra 0 e 1 e la visualizzi.
//3. Calcoli   il   prodotto   matrice   per   matrice,   memorizzando   i   valori   in   una   terza   matriceopportunamente dimensionata e la visualizzi.
//La memoria va allocatadinamicamente.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float **alloc_matrix(int m, int n)
{
  float **ptr;
  int i;

  ptr = (float **) malloc(m*sizeof(float *));

  if (ptr==NULL) return ptr;

  *ptr = (float *) malloc(m*n*sizeof(float));

  if (*ptr==NULL) {
    free((void *) ptr);
    return NULL;
  }

  for (i=1; i<m; i++) {
    ptr[i] = ptr[i-1] + n;
  }
  
  return ptr;
}


void free_matrix(float **ptr)
{
  free((void *) *ptr);
  free((void *) ptr);
}

void print_matrix(float **ptr, int m, int n)
{
  int i, j;

  printf("\n");
  for (i=0; i<m; i++) {
    for (j=0; j<n; j++) {
      printf("%f ", ptr[i][j]); 
    }
    printf("\n");
  }
  printf("\n");
}

float  **initialize_matrix(float **A, int m, int n)
{
  int i, j;

  for (i=0; i<m; i++) {
    for (j=0; j<n; j++) {
      A[i][j] = ((float) rand()) / (float) RAND_MAX;
    }
  }

  return A;
}


float **product(float **A, float **B, int m, int n, int p, int q)
{
  float **C;
  int i, j, h;
  
  if (n!=p) {
    printf("Matrices size mismatch\n");
    return NULL;
  }

  C = alloc_matrix(m,q);
  if (C==NULL) {
    return C;
  }

  for (i=0; i<m; i++) {
    for (j=0; j<q; j++)  {
      for (h=0; h<n; h++) {
	C[i][j] = A[i][h]*B[h][j];
      }
    }
  }

  return C;
}

int main()
{
  float **A, **B, **C;
  int m, n, p, q, i, j;

  srand((unsigned int)time(NULL));

  printf("Size of matrix A: ");
  scanf("%d %d", &m, &n);
  printf("Size of matrix B: ");
  scanf("%d %d", &p, &q);
    
  A = alloc_matrix(m,n);
  B = alloc_matrix(p,q);

  if (A==NULL || B==NULL) {
    exit(-1);
  }

  A = initialize_matrix(A,m,n);
  B = initialize_matrix(B,p,q);

  print_matrix(A,m,n);
  print_matrix(B,p,q);

  C = product(A,B,m,n,p,q);

  if (C==NULL) {
    exit(-1);
  }

  print_matrix(C,m,q);
  
  free_matrix(A);
  free_matrix(B);
  free_matrix(C);

  
}