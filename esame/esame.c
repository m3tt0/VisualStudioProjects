#include <stdio.h>
#include <stdlib.h>

int **readFile (const char *nomeFile, int *r, int *c);
void verifyMatrix (int **matrix, int righe, int colonne);
int **newMatrix (int **matrix, int r, int c, int *newR);
void writeFile(const char *nomeFile, int **matrix, int newR, int c);
int **allocMatrix(int r, int c);
void gestisciErrore (int code);

int main ()
{
	int **matrix, **matrix1;
	char nomeFileIn [100];
	char nomeFileOut [100];
	int righe, colonne, newRighe, i, j;
	
	printf ("Inserisci nome del file di input: ");
	scanf ("%s", nomeFileIn);
	
	
	matrix = readFile (nomeFileIn, &righe, &colonne);
	printf ("Matrice letta: \n");
	for (i = 0; i < righe; i++)
	{
		for (j = 0; j < colonne; j++)
		{
			printf ("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	
	verifyMatrix (matrix, righe, colonne);
	matrix1 = newMatrix (matrix, righe, colonne, &newRighe);

	printf ("\nInserisci nome del file di output: ");
	scanf ("%s", nomeFileOut);

	writeFile(nomeFileOut, matrix1, newRighe, colonne);
	
	
	return 0;
}

#define FILE_READ_ERROR    	1
#define FILE_WRITE_ERROR   	2
#define ALLOC_MEMORY_ERROR 	3

int **readFile (const char *nomeFile, int *r, int *c)
{
	FILE *fp;
	int **matrice;
	int valore, i, j, righe, colonne;
	
	fp = fopen (nomeFile, "r");
	if (fp == NULL)
	{
		gestisciErrore(FILE_READ_ERROR);
	}
	fscanf (fp, "%d %d", &righe, &colonne);
	matrice = allocMatrix(righe, colonne);
	
	for (i = 0; i < righe; i++) 
	{
		for (j = 0; j < colonne; j++) 
		{
			fscanf(fp,"%d", matrice[i] + j);
		}
	}
	
	
	*r = righe;
	*c = colonne;
	
	fclose (fp);
	
	return matrice;
}

//allocazione dinamica di memoria contigua
int **allocMatrix (int r, int c)
{
	int **matrice, i;
	
	matrice = (int **) malloc (r * sizeof(int *));
	if (matrice == NULL)
	{
		gestisciErrore(ALLOC_MEMORY_ERROR);
	}
	matrice[0] = (int *) malloc (r * c * sizeof(int));
	if (matrice[0] == NULL)
	{
		gestisciErrore(ALLOC_MEMORY_ERROR);
	}
	for ( i = 1; i < r; i++)
	{
		matrice[i] = matrice [i - 1] + c;

		if (matrice[i] == NULL)
		{
			gestisciErrore(ALLOC_MEMORY_ERROR);
		}
	}	
		
	return matrice;
}

void verifyMatrix (int **matrix, int righe, int colonne)
{
	int *sommaColonne;
	int i,j, controlloColonne = 0;
	
	
	sommaColonne = (int *) calloc (colonne, sizeof(int));
	
	for (j = 0; j < colonne; j++)
	{
		for (i = 0; i < righe; i++)
		{
			sommaColonne[j] = sommaColonne[j] + matrix[i][j];
		}
	}
	
	for (j = 0; j < colonne - 1; j++)     													 
	{
		for (i = j + 1; i < colonne; i++)
		{
			if (sommaColonne[j] == sommaColonne[i])
			{
				controlloColonne = 1;
			}	
		}		
	}
	
	if (controlloColonne != 0)
	{
		printf ("Ci sono delle colonne con la stessa somma !");
		
	}
	else
	{
		printf ("Verifica avvenuta correttamente !\n");
		printf ("Somma colonne: ");
		for (i = 0; i < colonne; i++)
		{
			printf(" [%d] = %d ",i, sommaColonne[i]);
		}	
	}
	
	
	
}

int **newMatrix (int **matrix, int r, int c, int *newR)
{
	int **matrice;
	int i,j,count = 0;
	int indexRow = 0;

	for (i = 0; i < r; i++)
	{
		if (matrix[i][0] != 0)
		{
			count++;
		}
	}
		
	matrice = allocMatrix(count, c); 
	
		
	for (i = r - 1; i >= 0; i--) 
	{
		if (matrix[i][0] != 0) 
		{
			for (j = 0; j < c; j++) 
			{
				matrice[indexRow][j] = matrix[i][j];
			}
			indexRow++;
		}
	}


	*newR = count;
	
	return matrice;
}

void writeFile(const char *nomeFile, int **matrix, int newR, int c)
{
	FILE *fp;
	int i,j;
	
	fp = fopen (nomeFile, "w");
	if (fp == NULL)
	{
		gestisciErrore (FILE_WRITE_ERROR);
	}
	
	fprintf (fp, "%d %d \n", newR, c);
	for (i = 0; i < newR; i++)
	{
		for (j = 0; j < c; j++)
		{
			fprintf (fp, "%d\t", matrix[i][j]);
		}
		fprintf (fp, "\n");
	}	

}

void gestisciErrore (int code)
{
		if (code == 1)
	{
		printf ("Errore nell'apertura del file !");
	}
	if (code == 2)
	{
		printf ("Errore nella scrittura del file !");
	}
	if (code == 3)
	{
		printf ("Errore nella allocazione della matrice !");
	}
}
