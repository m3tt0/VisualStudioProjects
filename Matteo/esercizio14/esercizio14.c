//Sia dato un file che contiene una sequenza (di lunghezza ignota, massimo 1000 elementi) di valori reali. Si scriva un programma in C che:
//1)legga la sequenza e la memorizzi in una opportuna struttura dati V nello stesso ordine in cui sono nel file.
//2) elimini dalla struttura dati  tutti i valori minori di una data soglia K (eliminare un elemento i-esimo significa che deve gli elementi dal posto i+1 in poi vanno spostati a sinistra di una posizione).
//3) dati 2 valori interi k1 e k2 (con k1 < k2) produca una nuova struttura dati W dove gli elementi sono arrangiati in maniera che prima vi siano tutti gli elementi di v di V tali che v < k1, 
//poi tutti gli elementi k1 < v< k2 e infine tutti gli elementi v > k2. L’ordine degli elementi di ognuna delle 3 parti di W deve essere la stessa di V.
//4) scriva la struttura dati W su un file di output.


#include <stdio.h>
#include <stdlib.h>

#define SIZE_MAX  1000

#define FILE_READ_ERROR		10
#define	FILE_WRITE_ERROR	20
#define MEMORY_ALLOC_ERROR	30
#define TOO_MANY_VALUES		40

int readFile (const char *nomeFile, float *vect, int size);
int eliminaValore (float *vect, int size, float key);
void modificaVect (float *vect, float *newVect, int size, int key1, int key2);
void writeFile (float *vect, int dim);
void gestisciErrori(int code);

int main ()
{	
	float vect[SIZE_MAX], newVect[SIZE_MAX];
	char nomeFile[100];
	int dim, i;
	float k;
	int  k1, k2;
	
		printf ("Inserisci il nome del file da cui vuoi leggere !\n");
		scanf ("%s", nomeFile);
	
		dim = readFile(nomeFile, vect, SIZE_MAX);
	
		printf ("Vettore attuale: \n");
	for (i = 0; i < dim; i++)
	{
		printf ("%.2f ", vect[i]);
	}
	
		printf ("\nInserisci una soglia, (a partire da essa tutti i numeri inferiori verranno eliminati): ");
		scanf ("%f", &k);
	
		dim = eliminaValore (vect, dim, k);
	
		printf ("Vettore senza elementi < %.2f: \n", k);
	for (i = 0; i < dim; i++)
	{
		printf ("%.2f ", vect[i]);
	}
	
		printf ("\nInserisci i valori k1 e k2: ");
		scanf ("%d %d", &k1, &k2);
	if (k1 < k2)
	{
		modificaVect (vect, newVect, dim, k1, k2);
		
		writeFile(newVect, dim);

	}
	else 
	{
		printf ("Il nuovo vettore non è stato creato, devi inserire un valore k1 < k2: \n");
		exit(-1);
	}
	
	
	
	return 0;
}


int readFile (const char *nomeFile, float *vect, int size)
{
	FILE *fp;
	float v;
	int i = 0;
	
	fp = fopen (nomeFile, "r");
	if (fp == NULL)
	{
		gestisciErrori(FILE_READ_ERROR);
	}
	
	while (fscanf (fp, "%f", &v) != EOF)
	{
		if (i < size)
		{
		vect[i] = v;
		i++;
		}
		else 
		{
			gestisciErrori(TOO_MANY_VALUES);
		}
	}
	
	fclose (fp);
	
	return i;
}
int eliminaValore(float *vect, int size, float key)
{
	int *flags;
	int i, n;
	
	flags = (int *) calloc(size, sizeof(int));
	for (i = 0; i < size; i++) {
		if (vect[i] >= key) {
			flags[i] = 1;
		}
	}
	
	n = 0;
	for (i = 0; i < size; i++) {
		if (flags[i] == 1) {
			vect[n] = vect[i];
			n = n+1;
		}
	}
	
	free(flags);
	
	return n;
}
/*
int *eliminaValore (float *vect, int size, float key)
{
	int *vectTemp;
	int i, dim = 0;
	
	for (i = 0; i < size; i++)
	{
		if (vect[i] < key)
		{
			vectTemp[dim] = vect[i];
			dim++;
		}
	}
	return dim;
}
*/
void modificaVect (float *vect, float *newVect, int size, int key1, int key2)
{
	int i, n = 0;
	
		//newVect = (float *) calloc (size, sizeof (float));
		
	if (newVect == NULL)
	{
		gestisciErrori (MEMORY_ALLOC_ERROR);
	}
	
	for (i = 0; i < size; i++)
	{
		if (vect[i] < key1)
		{
			newVect[n] = vect[i];
			n++;
		}					
	}
	for (i = 0; i < size; i++)
	{
		if (vect[i] >= key1 && vect[i] <= key2)
		{
			newVect[n] = vect[i];
			n++;
		}					
	}
	for (i = 0; i < size; i++)
	{
		if (vect[i] > key2)
		{
			newVect[n] = vect[i];
			n++;
		}					
	}
		
}

void writeFile (float *vect, int dim)
{
	FILE *fp;
	int i;
	
	fp = fopen ("output.txt", "w");
	
	if (fp == NULL)
	{
		gestisciErrori (FILE_WRITE_ERROR);
	}
		
	for (i = 0; i < dim; i++)
	{
		fprintf (fp, "%.2f ", vect[i]);
	}
		
	fclose (fp);
	
}

void gestisciErrori(int code)
{
	if (code==FILE_READ_ERROR) {
		printf("Errore apertura file in lettura\n");
	}
	if (code==FILE_WRITE_ERROR) {
		printf("Errore apertura file in scrittura\n");
	}
	if (code==MEMORY_ALLOC_ERROR) {
		printf("Errore allocazione memoria\n");
	}
	if (code==TOO_MANY_VALUES) {
		printf("Troppi valori in input\n");
	}
	
	exit(-1);
}
