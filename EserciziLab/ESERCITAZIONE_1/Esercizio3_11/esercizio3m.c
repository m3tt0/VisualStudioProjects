#include <stdio.h>
#include <stdlib.h>

float media (int n);

int main ()
{
	int n;
	float m;
	printf ("Inserisci la quantita' preferita di numeri: ");
	scanf ("%d", &n);

	m = media (n);

	printf ("La media dei numeri inseriti è: %.2f\n", m);

return 0;
}


float media (int n)
{
	float med = 0;
	int i;
	float num, sum = 0;

	printf ("Inserisci %d numeri interi per sapere la media: ", n);

	for (i = 0; i < n; i++)
	{
		scanf ("%f", &num);
		sum += num;
	}

	med = (sum / n);

return med;
}
