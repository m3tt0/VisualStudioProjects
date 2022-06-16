#include <stdio.h>
#include <stdlib.h>

void stampaChar(int n);

int main ()
{

	int n;
	printf ("Inserisci un interno: ");
	scanf ("%d",&n);

	stampaChar(n);


return 0;
}

void stampaChar (int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf (" # ");
	}
	printf ("\n");
}
