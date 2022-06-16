#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b);

int main ()
{
	int a, b;
	printf ("Inserisci i due valori su cui effettuare lo swap: ");
	scanf ("%d%d", &a,&b);

	printf ("Questi sono i valori prima dello swap: %d %d\n", a,b);
	swap (&a,&b);
	printf ("Questi sono i valori dopo lo swap: %d %d\n", a,b);

return 0;
}

void swap  (int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
