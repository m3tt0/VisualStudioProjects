
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **allocMatrix(int r, int c);
void initMatrix(int **matrice, int r, int c);
void printMatrix(int **matrice, int r, int c);
int checkMatrix(int **matrice, int r, int c);

int main(){
    int **matrice;
    int r, c;

    printf ("Inserire numero righe: ");
    scanf ("%d", &r);
    
    printf ("Inserire numero colonne: ");
    scanf ("%d", &c);

    matrice = allocMatrix(r, c);
    initMatrix(matrice, r, c);
    printMatrix(matrice, r, c);

    if (checkMatrix(matrice, r, c))
    {
        printf ("Tutti gli elementi sopra la diagonale principale sono maggiori di quelli al di sotto\n");
    } else {
        printf ("Alcuni elementi sopra la diagonale principale sono minore di quelli al di sotto\n");
    }
}

int **allocMatrix (int r, int c)
{
    int i;
    int **a;

    a = (int** )malloc(r * sizeof(int *));
    a[0] = (int*) malloc(r * c * sizeof(int));

    for (i=1; i<r; i++)
    {
        a[i] = a[i-1] + c;
    }

    return a;
}

void initMatrix(int **matrice, int r, int c)
{
    int i, j;
    int x;

    for (i=0; i<r; i++)
    {
        for (j=0; j<c; j++)
        {
            printf ("Inserire valore di a[%d][%d]: ", i, j);
            scanf ("%d", &x);
            matrice[i][j] = x;
        }
    }
}

void printMatrix(int **matrice, int r, int c)
{
    int i, j;

    for (i=0; i<r; i++)
    {
        for (j=0; j<c; j++)
        {
            printf ("%d ", matrice[i][j]);
        }
        printf ("\n");
    }
}

int checkMatrix(int **matrice, int r, int c)
{
    int i, j;
    int p, q;
    int diagIndex;

    for (i=0; i<r; i++)
    {
        diagIndex = i;
        for (j=0; j<c; j++)
        {
            if (i>=diagIndex && j>=diagIndex)
            {
                for (p=0; p<r; p++)
                {
                    for (q=0; q<c; q++)
                    {
                        if (q<=diagIndex && q<=diagIndex)
                        {
                            if (matrice[i][j]<matrice[p][q])
                            {
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    return 1;
}