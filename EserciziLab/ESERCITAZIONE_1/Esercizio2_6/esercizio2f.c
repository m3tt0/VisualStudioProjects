#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int voto;
	printf ("Inserisci il voto ricevuto: ");
	scanf ("%d",&voto);

	if (voto >= 18)
	{
		printf ("PROMOSSO\n");
	}
	else
	{
		printf ("BOCCIATO\n");
	}

return 0;
}
