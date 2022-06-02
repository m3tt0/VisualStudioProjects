#include <stdio.h>
#include <stdlib.h>

float**readfile(const char*nomefileIn,int * righe,int* colonne);
float** alloc_matrix(int m, int n);
void print_matrix(float **ptr, int m, int n);
float* ordinamento(float**matrix, int r,int c);   
float* alloc_array(int n);
void wrtVect(float *v, int n);
float**ord_matrice(float**m,int r,int c,float*med);
void freeMatrix(float **matrix);



int main(){
float**matrix;
int righe,colonne;
char nomefileIn[100];
char nomefileOut[100];
float**newmatrix;
float*mediane;
int i,j;
FILE*fp;

printf("inserire il nome del file di input:\n");
scanf("%s",&nomefileIn);

matrix=readfile(nomefileIn,&righe,&colonne);
print_matrix(matrix,righe,colonne);
mediane=ordinamento(matrix,righe,colonne);
wrtVect(mediane,righe);
newmatrix=ord_matrice(matrix,righe,colonne,mediane);



printf("inserire nome file di output:\n");
scanf("%s",&nomefileOut);
fp=fopen(nomefileOut,"w");

for (i=0; i<righe; i++) {
    for (j=0; j<colonne; j++) {
      fprintf(fp,"%f ",newmatrix[i][j]); 
    }
    fprintf(fp,"\n");
}
fclose(fp);

freeMatrix(matrix);
freeMatrix(newmatrix);

return 0;
}

float**readfile(const char*nomefileIn,int * righe,int* colonne){
    int r,c; //righe e colonne
    FILE*fp;
    float** matrix; //matrice della funzione
    int i,j;
   
   fp=fopen(nomefileIn,"r");
   fscanf(fp,"%d%d",&r,&c);

 
   matrix=alloc_matrix(r,c);

   for(i=0;i<r;i++){
       for(j=0;j<c;j++){
           fscanf(fp,"%f",&matrix[i][j]);
       }
   }

    fclose(fp);
   *righe=r;
   *colonne=c;
  
    return matrix;
}

float** alloc_matrix(int m, int n)
{
  float** ptr;
  int i;

  ptr = (float **) malloc(m*sizeof(float *));

  if (ptr==NULL) 
  {
    printf("errore");
      exit(-1);
  }

  ptr[0] = (float *) malloc(m*n*sizeof(float));

  if (ptr[0]==NULL) {
    free((void *) ptr);
    printf("errore");
      exit(-1);
  }

  for (i=1; i<m; i++) {
    ptr[i] = ptr[i-1] + n;
  }
  
  return ptr;
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
  printf("\n");
}

float* ordinamento(float**matrix, int r,int c)     
{
   int    i, j,k;
   int l=0;
   float*array;
   float meadiana;
   float media;
   float tmp;



for(i=0;i<r;i++){
   for (k = 0; k < c-1; k++){
      for (j = k+1; j < c ; j++){
         if (matrix[i][j] < matrix[i][k]){
           tmp=matrix[i][j];
           matrix[i][j]=matrix[i][k];
            matrix[i][k]=tmp;
                }
            }
        }
    }
    array=alloc_array(r);

    for(i=0;i<r;i++){
        if((c%2)!=0){
            array[l]=matrix[i][c/2];
            l++;
        }
        if((c%2)==0){
            media=(matrix[i][(c-1)/2]+matrix[i][(c+1)/2])/2;
            array[l]=media;
            l++;
        }
    }
  return array;
}

float* alloc_array(int n)
{
	float *v;
	v = (float *) calloc(n,sizeof(float));
	if (v==NULL)
     {
		printf("Menoria non sufficiente\n");
		exit(-1);
	}
	return v;
}

void wrtVect(float *v, int n) 
{
	int i;
	
	for (i=0; i<n; i++)  {
		printf("%f ", v[i]);
	}
	printf("\n");
}

float**ord_matrice(float**m,int r,int c,float*med){
    int i,l;
    int j=0;
    int k;
    float*tmp;

    tmp=alloc_array(c);
    
    for (i=0;i<r-1;i++){
        for(l=(i+1);l<r;l++){
            if (med[i]>med[l]){
                for(k=0;k<c;k++){
                    tmp[k]=m[i][k];
                    m[i][k]=m[l][k];
                    m[l][k]=tmp[k];
                }      
            }
        }
       
    }

    return m;
}

void freeMatrix(float **matrix)
{
    free(matrix[0]);
    free(matrix);
}