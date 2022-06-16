#include <stdio.h>
#include <stdlib.h>
#include "prototipi.h"
#include "strutture_dati.h"


int **readFile(char *In_fileName, int *righe, int *colonne)
{
    FILE *fp;
    fp = fopen (In_fileName, "r");
    
    int r, c;

    int **matrice;

    if (fp == NULL)
    {
        printf ("Errore nell'apertura del file in lettura.\n");
        exit(-1);
    }
    else
    {
       fscanf(fp,"%d %d", &r, &c);

        matrice = allocMatrix(r, c);

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                fscanf(fp,"%d", matrice[i] + j);
            }
        }
    }

    *righe = r;
    *colonne = c;

    return matrice;
}

void stampa_matrice(int **matrix, int righe, int colonne)
{
        for (int i = 0; i < righe; i++)
        {
            for (int j = 0; j < colonne; j++)
            {
                printf("%d\t", matrix[i][j]);
            }
            printf("\n");
        }
}

int is_magic(int **matrix, int righe, int colonne)
{
    if (righe != colonne)
    {
        return 1;
    }
    else
    {
        for (int i = 0; i < righe; i++)
        {
            for (int j = 0; j < colonne; j++)
            {
                for (int k = j + 1; k <(righe * colonne); k++)
                {
                    if(matrix[i][j] == matrix[i][k])
                    {
                        return 1;
                    }
                }

            }
        }

        int *sumRows = (int *) calloc(righe, sizeof(int));

        for (int i = 0; i < righe; i++)
        {
            for (int j = 0; j < colonne; j++)
            {
                sumRows[i] = sumRows[i] + matrix[i][j];
            }
        }

        for (int i = 0; i < righe-1; i++) 
        {
            for (int j = i+1; j < colonne; j++) 
            {
                if (sumRows[i] != sumRows[j]) 
                {
                    return 1;
                }
            }
        } 



        int *sumCol = (int *) calloc(colonne, sizeof(int));

        for (int i = 0; i < righe; i++)
        {
            for (int j = 0; j < colonne; j++)
            {
                sumCol[i] = sumCol[i] + matrix[j][i];
            }
        }

        for (int i = 0; i < righe-1; i++) 
        {
            for (int j = i+1; j < colonne; j++) 
            {
                if (sumCol[i] != sumCol[j]) 
                {
                    return 1;
                }
            }
        } 

        int *sumDiag = (int *) calloc (2, sizeof(int));

        for (int i = 0; i < righe; i++)
        {
            sumDiag[0] = sumDiag[0] + matrix[i][i];
        }

        int conta = righe - 1;
        for (int i = 0; i < righe; i++)
        {
            sumDiag[1] = sumDiag[1] + matrix[i][conta];
            conta--;
        }

        if ((sumDiag[1] == sumRows[1]) && (sumRows[1] == sumCol[1]) ) {
            
            return 0;
        }


    free (sumCol);
	free (sumDiag);
	free (sumRows);

    }

}

void create_list(int **matrix, struct Matrice **head, int righe, int colonne)
{
    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            struct Matrice *new = (struct Matrice *) malloc (sizeof(struct Matrice));

            new -> i = i;
            new -> j = j;
            new -> Aij = matrix[i][j];

            new -> next = NULL;

            struct Matrice *corrente = *head;
            struct Matrice *precedente = NULL;

            while (corrente != NULL)
            {
                precedente = corrente;
                corrente = corrente -> next;
            }

            if (precedente == NULL)
            {
                (*head) = new;
            }
            else 
            {
                precedente -> next = new;
            }
        }
    }
}

void stampa_lista(struct Matrice *head)
{
    while (head != NULL)
    {
        printf ("%d %d %d\n", (head -> i), (head -> j), (head -> Aij));
        head = head -> next;
    }
}

int eliminate(struct Matrice **head)
{
    struct Matrice *corrente = *head;
    struct Matrice *precedente = NULL;

    while (corrente != NULL)
    {
        if (((corrente -> Aij) % 2) != 0)
        {
            struct Matrice *del = corrente;

            if (precedente == NULL)
            {
                *head = del -> next;
            }
            else
            {
                precedente -> next = del -> next;
            }
            corrente = del -> next;
            free(del);
        }
        else
        {
            precedente = corrente;
            corrente = corrente -> next;
        }
    }

}




int **allocMatrix (int righe, int colonne)
{
    int **matrice;
    matrice = (int **) malloc (righe * sizeof(int *));

    matrice[0] = (int *) malloc (righe * colonne * sizeof(int));

	for (int i = 1; i < righe; i++)
	{
		matrice[i] = matrice [i - 1] + colonne;
    }

    return matrice;
}
