#include <stdio.h>
#include <stdlib.h>

void verifica (float a, float b, float x);

int main ()
{
	float a,b;
	float x;

	printf ("Inserisci due valori: ");
	scanf ("%f%f", &a,&b);

	printf ("Inserisci un numero per sapere se è compreso tra %.2f e %.2f: ", a, b);
	scanf ("%f", &x);

	if (a < b)
	{
		verifica(a,b,x);
	}
	else
	{
		printf ("Il primo valore deve essere maggiore del secondo !\n");
	}

return 0;
}

void verifica (float a, float b, float x)
{
	if(x<=a)
	{
		printf ("Il numero x = %.2f inserito è MINORE di a = %.2f e di b = %.2f\n", x, a, b);
	}
	else if(x>=b)
	{
		printf ("Il numero x = %.2f inserito è MAGGIORE di a = %.2f e di b = %.2f\n", x, a, b);
	}
	else if(x >= a && x <= b)
	{
		printf ("%.2f <= %.2f <= %.2f\n", a, x, b);
	}
	else
	{
		printf ("ERRORE\n");
	}
}
