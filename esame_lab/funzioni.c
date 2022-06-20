/*
MATTEO ROCCO 
N86004039
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipi.h"
#include "strutture_dati.h"

int load_matches_from_file(char *In_fileName, struct Tris **head)
{
    FILE *fp;
    fp = fopen (In_fileName, "r");
        if (fp == NULL)
        {
            return -1;
        }
        else
        {
            while (feof(fp) == 0)
            {
                struct Tris *new = (struct Tris *) malloc (sizeof(struct Tris));

                new -> campo = alloc_matrix(DIM,DIM);
                
                char *val;
                for(int i = 0; i < DIM; i++)
                {
                    for (int j = 0; j < DIM; j++)
                    {
                        fscanf(fp, "%c", val);
                        if (val == "@")
                        {
                            val = " ";
                        }
                        new -> campo[i][j] = *val;
                    }
                }

                new -> vincitore = the_winner_is(new -> campo);

                new -> punteggio = match_score (new -> campo);

                new -> next = NULL;

                struct Tris *corrente = *head;
                struct Tris *precedente = NULL;

                while (corrente != NULL)
                {
                    precedente = corrente;
                    corrente = corrente -> next;
                }

                if (precedente == NULL)
                {
                    *head = new;
                }
                else
                {
                    precedente -> next = new;
                }
                
            }
        }

    fclose (fp);
}

char the_winner_is (char **campo)
{
    char *Rows = (char *) malloc (DIM * sizeof(char));
    char *Columns = (char *) malloc (DIM * sizeof(char));
    char *Diag = (char *) malloc (2 * sizeof(char));
    
    int r = 0;
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 1; j < DIM; j++)
        {
            if (campo[r][i] == campo[i][j])
            {
                if(campo[i][j] == campo[i][j + 1])
                {
                    return campo[i][j];
                }
            }
            r++;
        }
    }

    int c = 0;
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 1; j < DIM; j++)
        {
            if (campo[c][i] == campo[j][i])
            {
                if (campo[j][i] == campo[j + 1][i])
                {
                    return campo[j][i];
                }
            }
            c++;
        }
    }

    int d = 0;
    int d2 = DIM - 1;
    for (int i = 1; i < DIM; i++)
    {
        if (campo[d][d] == campo[d + 1][i])
        {
            if (campo[d + 1][i] == campo[d + 2][i + 1])
            {
                return campo[d][d];
            }
        }
        else
        {
            if (campo[d][d2] == campo[d + 1][d2 -1])
            {
                if (campo[d + 1][d2 - 1] == campo[d + 2][d2 - 2])
                {
                    return campo[d][d2];
                }
            }
            else
            {
                char win = 'P';
                return win;
            }
        }
    }


}

int match_score (char **campo)
{
    int punt = 0;

    punt = free_positions(campo);

    return punt;
}

int free_positions (char **campo)
{
    int count = 0;
    char *tmp = " ";

    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            if (campo[i][j] == *tmp)
            {
                count ++;
            }
        }
    }

    if (count != 0)
    {
        count = count + 3;
    }

    return count;
}

void print_list (struct Tris *head)
{
    print_match (head);
    print_list(head -> next);
}

void print_match (struct Tris *head)
{
    while (head != NULL)
    {
        printf ("Il vincitore e': %c\n", head -> vincitore);
        printf ("Il punteggio e': %d\n", head -> punteggio);
        printf ("Campo da gioco:\n");
        for (int i = 0; i < DIM; i++)
        {
            for (int j = 0; j < DIM; j++)
            {
                printf ("%c", head -> campo[i][j]);
            }
            printf ("\n");
        }
        
        head = head -> next;
    }
}

void free_list(struct  Tris **head)
{
    struct  Tris *tmp;
    while((*head) != NULL)
    {
        tmp = (*head)->next;
        free(*head);
        (*head) = tmp;
    
    }
}

char **alloc_matrix(int righe, int colonne)
{
	char **matrix;
    int i;
	
	matrix = (char**) calloc(righe, sizeof(char*));
	

	matrix[0] = (char *) malloc(righe*colonne*sizeof(char));
	
	if (matrix[0] == NULL)
	{
		printf("Errore allocazione matrice.\n");
	}
	
	for (i = 1; i < righe; i++)
	{
		matrix [i] = matrix [i - 1] + colonne;
	}
	return matrix;
}