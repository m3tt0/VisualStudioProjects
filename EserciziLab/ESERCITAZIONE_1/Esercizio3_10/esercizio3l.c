#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int num, i;
	int count = 0;

	printf ("Inserisci dieci numeri interi: ");
	for (i = 0; i < 10; i++)
	{
		scanf ("%d", &num);
		if ((num % 2) == 0)
		{
			count ++;
		}
	}

	printf ("Ci sono %d numeri pari\n", count);


return 0;
}
