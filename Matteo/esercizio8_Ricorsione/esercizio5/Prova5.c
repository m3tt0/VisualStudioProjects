#include <stdio.h>
#include <stdlib.h>

int sommaPariRicorsiva (int n);

int main()
{
	int n;
	int sum;
	
	printf("Inserisci N ");
	scanf("%d", &n);
    
    sum = sommaPariRicorsiva (n);

    printf ("Somma: %d", sum);
	
}


int sommaPariRicorsiva (int n)
{   
   if (n==0) return 0;
	return (2*(n-1)) + sommaPariRicorsiva(n-1);
    
}














