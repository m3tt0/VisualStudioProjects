#include <stdio.h>
#include <stdlib.h>

int fattoriale (int a);

int main ()
{
	int a;
	printf ("Inserisci il numero di cui vuoi sapere il fattoriale: ");
	scanf ("%d", &a);

	int f = fattoriale (a);

	printf ("Il fattoriale di %d e' = %d\n", a, f);

return 0;
}

int fattoriale (int a)
{
	int fat = 1;
	if (a == 0)
	{
		return fat;
	}
	else
	{
		while (a > 0)
		{
			fat *= a;
			a--;
		}
	return fat;
	}
}
