#include <stdio.h>
#include <stdlib.h>

#define FILE_READ_ERROR    1
#define FILE_WRITE_ERROR   2
#define MATRIX_ERROR       3

int **readFile (const char *fileName, int *righe, int *colonne);
void magica(int **matrix, int righe, int colonne);
int **modifyMatrix (int **matrix, int righe, int colonne);
void writeFile(int **matrix, int righe, int colonne);
void gestisciErrori (int error);
void freeMatrix(int **matrix);
int **allocMatrix(int righe, int colonne);


int main ()
{
	int **matrix, **newMatrix;
	int righe, colonne;
	char fileName[100];
	int i,j;
	
	printf("Inserire il nome del file di input: ");
	scanf("%s", fileName);
	
	matrix = readFile (fileName, &righe, &colonne);
	
	magica(matrix, righe, colonne);
	
	newMatrix = modifyMatrix (matrix, righe, colonne);
	

	writeFile (newMatrix, righe, colonne);
	
	
return 0;	
}

int **readFile (const char *fileName, int *righe, int *colonne)
{
	FILE *fp;
	int **matrix;
	int i, j;
	int valore, indice1, indice2;
	fp = fopen (fileName, "r");
	if (fp == NULL)
	{
		gestisciErrori(FILE_READ_ERROR);
	}
	
	fscanf (fp, "%d %d ", righe, colonne);
	
	matrix = allocMatrix (*righe, *colonne);
	
	
	while (fscanf(fp, "%d%d%d", &valore, &indice1, &indice2) != EOF)
	{
		matrix[indice1 - 1][indice2 - 1] = valore;
	}
	
	fclose (fp);
	
	return matrix;
}

int **allocMatrix(int righe, int colonne)
{
	int **matrix, i;
	
	matrix = (int**) calloc(righe, sizeof(int*));
	
	if (matrix == NULL)
	{
		gestisciErrori(MATRIX_ERROR);
	}
	matrix[0] = (int *) malloc(righe*colonne*sizeof(int));
	
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

void magica(int **matrix, int righe, int colonne)
{
	int i, j, k;
	int *Sum_Rows;
	int *Sum_Col;
	int *Sum_Diag;
	int n_diag=2;
	int ControlloRighe=1;
    int ControlloColonne=1;
    int ControlloDiag=1;
	int verificati = 0;
	int f = righe - 1;
	
	if (righe == colonne)
	{
		for (i = 0; i < righe; i++)
		{
			for (j = 0; j < colonne; j++)
			{
				for (k = j+1; k< (righe * colonne); k++)
				{					
					if (matrix[i][j] == matrix[i][k])
					{
						printf ("Non può essere magica !");
						exit (-1);
					}
				}
			}
		}
		
		 Sum_Rows = (int *) calloc(righe, sizeof(int));

    //somma delle righe
    for (i = 0; i < righe; i++) {
       for (j = 0; j < colonne; j++) {
           
           Sum_Rows[i]= Sum_Rows[i] + matrix[i][j]; 
       }
    }
    
    //Controllo se tutti gli elementi del vettore che mi contiene le somme delle righe contiene elementi diversi
    for (i = 0; i < righe-1 && ControlloRighe == 1 ; i++) {
        for (j = i+1; j < colonne && ControlloRighe == 1; j++) {

            if (Sum_Rows[i] != Sum_Rows[j]) {
                ControlloRighe=0;
            }
        }
    }
    

    Sum_Col = (int *) calloc(righe, sizeof(int));

    //somma delle colonne
    for (i = 0; i < righe; i++) {
       for (j = 0; j < colonne; j++) {
           
           Sum_Col[i]= Sum_Col[i] + matrix[j][i]; 
       }
    }
    
    //Controllo se tutti gli elementi del vettore che mi contiene le somme delle Colonne contiene elementi diversi
    for (i = 0; i < righe-1  && ControlloColonne == 1 ; i++) {
        for (j = i+1; j < colonne && ControlloColonne == 1 ; j++) {

            if (Sum_Col[i] != Sum_Col[j]) {
                ControlloColonne=0;
            }
        }
    }

    //somma della diagonale principale
    Sum_Diag = (int *) calloc(n_diag, sizeof(int));

    for ( i = 0; i < righe; i++) {
        Sum_Diag[0]=Sum_Diag[0] + matrix[i][i];

    }
    

    // domma della diagonale secondaria
    for (i= 0; i < righe; i++){
        Sum_Diag[1]=Sum_Diag[1] + matrix[i][f];
        f--;
    }	
	
	 if (ControlloDiag==1 && ControlloColonne == 1 && ControlloRighe == 1 ){
        if ((Sum_Diag[1] == Sum_Rows[1]) && (Sum_Rows[1] == Sum_Col[1]) ) {
            
            verificati=1;
        }
	}
	
	}
		if (verificati == 1)
		{
			printf ("La matrice è magica !\n");
		}
	
	free (Sum_Col);
	free (Sum_Diag);
	free (Sum_Rows);

}

int **modifyMatrix (int **matrix, int righe, int colonne)
{
	int i, j;
	
	
	for (i = 0; i < righe; i++)
	{
		for (j = 0; j < colonne; j++) 
		{
			if ((matrix[i][j] % (i + 1)) == 0 && (matrix[i][j] % (j + 1)) == 0)
			{
				matrix [i][j] = 0;
			}
		}
	}
	
	
	return matrix;
}

void writeFile(int **matrix, int righe, int colonne)
{
	FILE *fp;
	int i, j;
	fp = fopen ("output.txt", "w");
	if (fp == NULL)
	{
		gestisciErrori (FILE_WRITE_ERROR);
	}
	
	fprintf (fp, "%d %d\n", righe, colonne);
	
	for (i = 0; i < righe; i++)
	{
		for (j = 0; j < colonne; j++)
		{
			if (matrix[i][j] != 0)
			{
				fprintf(fp, "%d %d %d\n", matrix[i][j], (i + 1), (j + 1));
			}
			//fprintf (fp, "%d", matrix[i][j]);
		}
	}
	fclose (fp);
}

void freeMatrix(int **matrix)
{
	free(matrix[0]);
	free(matrix);
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
 
 

