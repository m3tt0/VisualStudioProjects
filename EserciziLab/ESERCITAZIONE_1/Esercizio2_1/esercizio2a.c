#include <stdio.h>
#include <stdlib.h>

int PariDispari (int n);

int main ()
{
	int num;
	int a;
	printf ("Inserisci il numero per sapere se è pari o dispari: ");
	scanf ("%d", &num);

	a = PariDispari (num);
	if (a == 1)
	{
		printf ("Il numero è PARI\n");
	}
	else
	{
		printf ("Il numero è DISPARI\n");
	}
return 0;
}

int PariDispari (int n)
{
	if ((n % 2) == 0)
	{
		return 1;
	}
	else return 0;
}
