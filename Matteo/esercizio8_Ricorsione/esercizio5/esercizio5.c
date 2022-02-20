
//Scrivere una funzione C che, dato un numero calcola la somma dei primi N numeri pari positiviin maniera ricorsiva.

#include <stdio.h>

int sommaPariRicorsiva(int n)
{
	if (n==0) return 0;
	return (2*n) + sommaPariRicorsiva(n-1);
}


int main()
{
	int N;
	int sum;
	
	scanf("%d", &N);
	sum = sommaPariRicorsiva(N);
	
}
