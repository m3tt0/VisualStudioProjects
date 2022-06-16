#include <stdio.h>
#include <stdlib.h>

float equazione (int m, int q, int y);

int main ()
{
	int m, q, y;
	float x;
	printf ("Inserisci i valori di m, q ed y: ");
	scanf ("%d%d%d",&m,&q,&y);

	x = equazione (m,q,y);

	printf("La X nell'equazione (y = mx + q) equivale a: %.2f\n", x);

return 0;
}

float equazione (int m, int q, int y)
{
	float x;
	x = (y - q)/m;
return x;
}
