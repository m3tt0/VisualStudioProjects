#include <stdio.h>
#include <stdlib.h>

void stampaRettangolo (int b, int h);

int main ()
{
	int b, h;
	printf ("Inserisci base ed altezza del rettangolo: ");
	scanf ("%d%d", &b,&h);

	stampaRettangolo (b, h);




return 0;
}

void stampaRettangolo (int b, int h)
{
	int i, j;
	char count;
	for (i = 0; i < b; i++)
	{
		for (j = 0; j < h; j++)
		{
			printf (" * ");
		}
		printf ("\n");
	}
}

