#include <stdio.h>
#include <stdlib.h>

#define FILE_READ_ERROR     1
#define FILE_WRITE_ERROR    2
#define MEMORY_ALLOC_ERROR  3
#define TOO_MANY_VALUES     4
#define WRONG_VALUE         5

float *readFile (const char *nomeFileIn, int *dim);
float *modifyVect (float *vettore, int dim);
void writeFile (const char *nomeFileOut, float *newVect, int dim);
void writeVect(float *vettore, int dim);
void gestisciErrori (int error);
float *allocVect(int n);

int main ()
{
    float *vettore, *newVect;
    char nomeFileIn[50], nomeFileOut[50];
    int dim;

    printf ("Inserisci nome file di input: ");
    scanf ("%s", nomeFileIn);

    vettore = readFile (nomeFileIn, &dim);
    printf ("Il tuo vettore e' il seguente: \n");
    writeVect (vettore, dim);

    newVect = modifyVect (vettore, dim);

    printf ("\nInserisci nome file di output: ");
    scanf ("%s", nomeFileOut);

    writeFile (nomeFileOut, newVect, dim);


    return 0;
}

float *readFile (const char *nomeFileIn, int *dim)
{
    FILE *fp;
    float *vect;
    float val;
    int i = 0, size;

    fp = fopen (nomeFileIn, "r");
    if (fp == NULL)
    {
        gestisciErrori(FILE_READ_ERROR);
    }

    fscanf (fp, "%d", &size);

    vect = allocVect (size);
    if (vect == NULL)
    {
        gestisciErrori (MEMORY_ALLOC_ERROR);
    }

    while (fscanf(fp, "%f", &val) != EOF)
    {
            vect[i] = val;
            i++;        
    }
   


    *dim = size;

    return vect;

}

float *modifyVect (float *vettore, int dim)
{
    int s1, s2;
    float *newVect;
    int i;
    int n = 0;

    printf ("\nInserisci due valori da cui partire per l'ordinamento. ");
    scanf ("%d%d", &s1, &s2);
    if (s1 >= s2)
    { 
        gestisciErrori (WRONG_VALUE);
    }

    newVect = allocVect (dim);

    for (i = 0; i < dim; i++)
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


    return newVect;

}

void writeFile (const char *nomeFileOut, float *newVect, int dim)
{
    FILE *fp;
    int i;
    fp = fopen (nomeFileOut, "w");
    if (fp == NULL)
    {
        gestisciErrori (FILE_WRITE_ERROR);
    }

    fprintf (fp, "%d\n", dim);

    for (i = 0; i < dim; i++)
    {
        fprintf (fp, "%.2f\t", newVect[i]);
    }


}

float *allocVect(int n)
{

    float *v;

    v = (float *)calloc(n, sizeof(float));

    return v;
}

void gestisciErrori (int error)
{
    if (error==FILE_READ_ERROR) {
		printf("Errore apertura file in lettura! \n");
	}
	if (error==FILE_WRITE_ERROR) {
		printf("Errore apertura file in scrittura! \n");
	}
	if (error==MEMORY_ALLOC_ERROR) {
		printf("Errore allocazione memoria! \n");
	}
	if (error==TOO_MANY_VALUES) {
		printf("Troppi valori in input! \n");
	}
    if (error==WRONG_VALUE) {
		printf("Il primo valore deve essere piu' piccolo del secondo! \n");
	}

	
	exit(-1);
}

void writeVect(float *vettore,int dim)
{
    int i;

    for (i = 0; i < dim; i++) {
        
        printf("%.2f ", vettore[i]);

    }
}

