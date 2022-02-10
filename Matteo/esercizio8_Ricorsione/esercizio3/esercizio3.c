
//Scrivere una funzione ricorsiva che, avendo in input un array di interi ed un intero K, ritornaTRUE se K è un elemento dell’array e FALSE altrimenti.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initSeed(void);
int *allocVect(int n);
void randomVect(int *v, int n);
void wrtVect(int *v, int n);
int cercaRicorsivo(int *v, int n, int k);

int main()
{
	int n, k;
	int *v;
	int sum;
	
	printf("Inserisci dimensione vettore  ");
	scanf("%d", &n);
	
	initSeed();
	v = allocVect(n);
	if (v==NULL) {
		printf("Errore allocazione memoria\n");
		exit(-1);
	}
	randomVect(v, n);
	
	printf("Vettore input:\n");
	wrtVect(v, n);
	
	printf("Inserisci elemento da cercare ");
	scanf("%d",&k);
	
	printf("Risultato cerca: %d\n", cercaRicorsivo(v, n, k));
	free(v);
}


void initSeed(void)
{
	srand(time(NULL));
}

int *allocVect(int n)
{
	int *v;
	
	v = malloc(n*sizeof(int));
	
	return v;
}

void randomVect(int *v, int n)
{
	int i;
	
	for (i=0; i<n; i++) {
		v[i] = rand() % 101;
	}
}


void wrtVect(int *v, int n)
{
	int i;
	
	for (i=0; i<n; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}


int cercaRicorsivo(int *v, int n, int k)
{	
	if (n==0) return 0;
	if (v[n-1] == k) return 1;	
	return cercaRicorsivo(v, n-1, k);
}


















