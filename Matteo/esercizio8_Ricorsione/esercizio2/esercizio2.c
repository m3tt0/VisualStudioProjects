
//Scrivere una funzione ricorsiva che calcoli la somma degli elementi di un array di interi.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initSeed(void);
int *allocVect(int n);
void randomVect(int *v, int n);
void wrtVect(int *v, int n);
int sumRicorsivo(int *v, int n);

int main()
{
	int n;
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
	
	sum = sumRicorsivo(v, n);
	
	printf("Vettore input:\n");
	wrtVect(v, n);
	printf("Somma: %d\n", sum);
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


int sumRicorsivo(int *v, int n)
{
	if (n==1) return v[0];
	return v[0] + sumRicorsivo(v+1, n-1);
	
}






















