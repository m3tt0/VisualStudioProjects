//Scrivete un programma C che dichiari una matrice di interi NxM, 
//inizializzi la matrice in modo che il valore di ogni elemento sia il risultato dalla somma dei propri indici. 
//Visualizzare la matrice alla fine. 
//La memoria va allocata dinamicamente. 

#include <stdio.h>
#include <stdlib.h>


float **alloc_matrix(int m, int n)
{
  float **ptr;
  int i;

  ptr = (float **) malloc(m*sizeof(float *));

  if (ptr==NULL) return ptr;

  ptr[0] = (float *) malloc(m*n*sizeof(float));

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

  for (i=0; i<m; i++) {
    for (j=0; j<n; j++) {
      printf("%f ", ptr[i][j]); 
    }
    printf("\n");
  }
}

float  **initialize_matrix(float **A, int m, int n)
{
  int i, j;

  for (i=0; i<m; i++) {
    for (j=0; j<n; j++) {
      A[i][j] = i+j;
    }
  }

  return A;
}


int main()
{
  float **A;
  int m, n, i, j;

  scanf("%d %d", &m, &n);
  A = alloc_matrix(m,n);
  if (A==NULL) {
     exit(-1);
  }
  
  A = initialize_matrix(A,m,n);
  print_matrix(A,m,n);

  free_matrix(A);

  
}