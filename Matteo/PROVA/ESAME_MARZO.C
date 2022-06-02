#include <stdio.h>
#include <stdlib.h>

#define FILE_READ_ERROR    1
#define FILE_WRITE_ERROR   2
#define MATRIX_ERROR       3

float **readFile (const char *nomeFile, int *righe, int *colonne);

void printMatrix (float **matrix, int righe, int colonne);
float **allocMatrix(int righe, int colonne);
float *mediana (float **matrix,int righe,int colonne);
void bubble(float **matrix, int righe, int colonne)
void gestisciErrori (int error);

int main ()
{
    float **matrix;
    char nomeFileIn[100];
    int righe, colonne;
    float *med;
    
    printf("Inserire il nome del file di input: ");
	scanf("%s", nomeFileIn);

    matrix = readFile (nomeFileIn,&righe,&colonne);
    printMatrix (matrix, righe, colonne);

    med = mediana (matrix,righe,colonne);





    return 0;
}

float **readFile (const char *nomeFile, int *righe, int *colonne)
{
    FILE *fp;
    float **matrixTemp;
    int i, j;

    fp = fopen (nomeFile,"r");
    if (fp == NULL)
    {
        gestisciErrori(FILE_READ_ERROR);
    }

    fscanf (fp, "%d%d",righe, colonne);
    
    matrixTemp = allocMatrix (*righe, *colonne);

    for(i=0;i<*righe;i++){
       for(j=0;j<*colonne;j++){
           fscanf(fp,"%f", matrixTemp[i][j]);
       }
   }
    fclose (fp);
   
    return matrixTemp;
}

float *mediana (float **matrix,int righe,int colonne)
{
    float *med;
    int i,j;

         for (i = 0; i < righe; i++) 
            {
            for (j = 0; j < colonne; j++) 
                {
                    med[i] = 2 + 2;
                }
            }



    return med;
}

float **allocMatrix(int righe, int colonne)
{
	float **matrix, i;
	
	matrix = (float**) malloc(righe * sizeof(float*));
	
	if (matrix == NULL)
	{
		gestisciErrori(MATRIX_ERROR);
	}
	matrix[0] = (float*) malloc(righe*colonne*sizeof(float));
	
	if (matrix[0] == NULL)
	{
		gestisciErrori(MATRIX_ERROR);
	}
	
	for (i = 1; i < righe; i++)
	{
		matrix [i] = matrix [i - 1] + colonne;
	}
	return matrix;
}

void printMatrix (float **matrix, int righe, int colonne)
{
      int i, j;

    for (i = 0; i < righe; i++) 
    {
        for (j = 0; j < colonne; j++) 
        {
            printf("%.2f ", matrix[i][j]);
        }
        puts ("");
    }

}

void bubble(float **matrix, int righe, int colonne)    
{
   int i, j;
   int count = 0;
   float **newMatrix;

     for(i = 0; i < righe; i++)
     {
        for(j = 0; j < colonne; j++)
        {
		  if (matrix [i][j] < mediana)
            newMatrix [i][count] = matrix [i][j];
            count++;
		}
	}
    for(i = 0; i < righe; i++)
     {
        for(j = 0; j < colonne; j++)
        {
		  if (matrix [i][j] > mediana)
            newMatrix [i][count] = matrix [i][j];
            count++;
		}
	}

    for (i = 0; i < righe; i++)
	{
		if (vettore[i] < s1)
		{
			newVect[n] = vettore[i];
			n++;
		}					
	}
	for (i = 0; i < dim; i++)
	{
		if (vettore[i] >= s1 && vettore[i] <= s2)
		{
			newVect[n] = vettore[i];
			n++;
		}					
	}
	for (i = 0; i < dim; i++)
	{
		if (vettore[i] > s2)
		{
			newVect[n] = vettore[i];
			n++;
		}					
	}














}

void gestisciErrori (int error)
{
	if (error == 1)
	{
		printf ("Errore nell'apertura del file !");
	}
	if (error == 2)
	{
		printf ("Errore nella scrittura del file !");
	}
	if (error == 3)
	{
		printf ("Errore nella matrice !");
	}
}