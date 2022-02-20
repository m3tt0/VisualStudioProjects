
//Scrivere una funzione ricorsiva che, avendo in input un array di interi e un intero K, 
//dia in output TRUE se tutti gli elementi del vettore sono maggiori di K e FALSE altrimenti.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initSeed(void);
int *allocVect(int n);
void randomVect(int *v, int n);
void wrtVect(int *v, int n);
int verificaRicorsivo(int *v, int n, int k);
int verificaRicorsivo2(int *v, int n, int k);

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
	
	printf("Risultato cerca: %d\n", verificaRicorsivo(v, n, k));
	free(v);
}


void initSeed(void)
{
	srand(time(NULL));
}

int *allocVect(int n)
{
	int *v;
	
	v = (int *) malloc(n*sizeof(int));
	
	return v;
}

void randomVect(int *v, int n)
{
	int i;
	
	for (i=0; i<n; i++) {
		v[i] = rand() % 100 + 1;
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


int verificaRicorsivo(int *v, int n, int k)
{	
	if (k >= v[0]) return 0;
	if (n==0) return 1;
	return verificaRicorsivo(v+1, n-1, k);
}


//Soluzione elegante
int verificaRicorsivo2(int *v, int n, int k)
{
	if (n==1) return (k < v[0]);
	return (v[0] > k  && verificaRicorsivo2(v+1, n-1, k));
}