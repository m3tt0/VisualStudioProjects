
//Scrivere una funzione ricorsiva che calcola il minimo di un array di interi.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initSeed(void);
int *allocVect(int n);
void randomVect(int *v, int n);
void wrtVect(int *v, int n);
int minRicorsivo(int *v, int n);

int main()
{
	int n;
	int *v;
	int m;
	
	printf("Inserisci dimensione vettore  ");
	scanf("%d", &n);
	
	initSeed();
	v = allocVect(n);
	if (v==NULL) {
		printf("Errore allocazione memoria\n");
		exit(-1);
	}
	randomVect(v, n);
	
	m = minRicorsivo(v, n);
	
	printf("Vettore input:\n");
	wrtVect(v, n);
	printf("Minimo: %d\n", m);
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


int minRicorsivo(int *v, int n)
{
	int min;
	
	if (n==1) return v[0];
	min = minRicorsivo(v, n-1);
	if (v[n-1] < min) 
		return v[n-1];
	else
		return min;
}























