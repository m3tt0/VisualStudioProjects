#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strutture_dati.h"
#include "prototipi.h"

int read_File(const char *fileName, struct Persona **head, int *num)
{
    FILE *fp;
    int n_el;

    fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        printf("Errore nell'apertura del file in lettura\n");
        return 1;
    }

    while (feof(fp) == 0)
    {
        struct Persona *new = (struct Persona*) malloc(sizeof(struct Persona));
        char *Nome = (char*) malloc (MAX_CHAR * sizeof (char));
        char *Cognome = (char*) malloc (MAX_CHAR * sizeof (char));

        fscanf (fp,"%s %s %f %f", Nome, Cognome, &(new -> Peso), &(new -> Altezza));
        strcpy ((new -> Nome), Nome);
        strcpy ((new -> Cognome), Cognome);

        new -> next = NULL;

        struct Persona *corrente = (*head);
        struct Persona *precedente = NULL;

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
            
            n_el++;

        free(Nome);
        free(Cognome);
    }
    
        fclose(fp);

        
    *num = n_el;
    return 0;
}

void print_list (struct Persona *head)
{
    while (head != NULL)
    {
        printf ("%s\t", head -> Nome);
        printf ("%s\t", head -> Cognome);
        printf ("%.1f\t", head -> Peso);
        printf ("%.1f\n", head -> Altezza);

        head = head -> next;
    }
}

int eliminate(struct Persona **head, int *num_el)
{
    struct Persona *corrente = (*head);
    struct Persona *precedente = NULL;
    int count = 0;

    while (corrente != NULL)
    {
        if ((corrente -> Peso) < 12)
        {
            struct Persona *del = corrente;
                if (precedente == NULL)
                {
                    (*head) = del -> next;
                }
                else 
                {
                    precedente -> next = del -> next;
                }
                corrente = del -> next;
                free (del);
        }
        else
        {
            precedente = corrente;
            corrente = corrente -> next;
            count++;
        }
        
    }
    *num_el = count;

    return 0;

}

float **create_matrix(struct Persona *head, int num)
{
    float **matrice;
    matrice = allocMatrix (num);
    float *arrayTmp = (float *) calloc (num, sizeof(float));
    int indx = 0;
    struct Persona *prova = head;

    while (prova != NULL)
    {    
        arrayTmp[indx] = prova -> Peso;
        prova = prova -> next;
        indx++;
    }

    for (int i = 0; i < num; i++)
    {
        for(int j = 0; j < num; j++)
        {
            float a = arrayTmp[i];
            float b = arrayTmp[j];
            matrice[i][j] = (a + b)/2;
        }
    }

    return matrice;
}

float **allocMatrix (int num)
{
	float **matrice;
	
	matrice = (float **) malloc (num * sizeof(float *));
	if (matrice == NULL)
	{
		printf ("Errore nell'allocazione della matrice! \n");
	}
	matrice[0] = (float *) malloc (num * num * sizeof(float));
	if (matrice[0] == NULL)
	{
		printf ("Errore nell'allocazione della matrice! \n");
	}
	for (int i = 1; i < num; i++)
	{
		matrice[i] = matrice [i - 1] + num;

		if (matrice[i] == NULL)
		{
			printf ("Errore nell'allocazione della matrice! \n");
		}
	}	
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            matrice[i][j] = 0;
        }
    }
		
	return matrice;
}

void stampa_matrix(float **matrix, int dim)
{
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            printf (" %.1f   ", matrix[i][j]);
        }
        printf ("\n");
    }
}

void write_File(const char *out_fileName, struct Persona *head, int num, float **matrix)
{
    FILE *fp;
    fp = fopen (out_fileName, "w");
    if (fp == NULL)
    {
        printf ("Errore nella scrittura del file!\n");
    }
    else
    { 
        int i, j;
        float max;
        int new_j;

        for (i = 0; i < num; i++)
        {
            max = matrix[i][0];
            for (j = 0; j < num; j++)
            {
                
                if (matrix[i][j] > max)
                {
                    max = matrix[i][j];
                    new_j = j;
                }
            }
                int count = 0;
                int count1 = 0;

                struct Persona *list = head;
                struct Persona *list1 = head;    
                    char *array_nome = (char *) malloc (num * sizeof(char));
                    char *array_cognome = (char *) malloc (num * sizeof(char));

                    while (list != NULL)
                    {
                        if (count == i)
                        {
                            strcpy (array_nome,(list -> Nome));
                            strcpy (array_cognome,(list -> Cognome));
                        }
                        list = list -> next;
                        count++;
                    }
                    
                    char *array_nome1 = (char *) malloc (num * sizeof(char));
                    char *array_cognome1 = (char *) malloc (num * sizeof(char));
                    while (list1 != NULL)
                    { 
                        if (count1 == new_j)
                        {
                            strcpy (array_nome1,(list1 -> Nome));
                            strcpy (array_cognome1,(list1 -> Cognome));
                        }
                        list1 = list1 -> next;
                        count1++;
                    }         
                    fprintf (fp,"%s %s massimizza il peso con %s %s = %.1f\n", array_nome, array_cognome, array_nome1, array_cognome1, max);
        }    
    }

    fclose(fp);

}

void free_list(struct  Persona *head)
{
    struct  Persona *tmp;
    while(head != NULL)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    
    }
}

void freeMatrix(float **matrix)
{
	free(matrix[0]);
	free(matrix);
}
/*
int max(int *v, int n)
{
	int max;
	
	if (n==1) return v[0];
	min = max(v, n-1);
	if (v[n-1] > min) 
		return v[n-1];
	else
		return min;
}
*/

/*
void err_handle (int code)
{
    if (code == 1)
    {
        printf("Errore lettura file\n");
    }
    if (code == 2)
    {
        printf("Errore scrittura file\n");
    }
}
*/