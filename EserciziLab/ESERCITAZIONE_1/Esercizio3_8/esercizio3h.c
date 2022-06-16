#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
	int a, b;
	int pot = 0;

	printf ("Inserisci il numero e poi la sua potenza: ");
	scanf ("%d%d", &a, &b);

	pot = pow (a, b);

	printf ("Il risultato e': %d\n", pot);


return 0;
}
