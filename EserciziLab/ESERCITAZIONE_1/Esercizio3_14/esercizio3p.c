#include <stdio.h>
#include <stdlib.h>


int main ()
{
	float num;
	float media = 0;
	float sum = 0;
	int count = 0;

	printf ("Inserisci una serie di valori per saperne la media, quando inserirai zero si fermerà: ");

	do
	{
		scanf ("%f",&num);
		sum = sum + num;
		count++;
	}while (num != 0);

	media = (sum / (count - 1));
	printf ("La media dei %d numeri inseriti e': %.2f\n",(count - 1), media);

return 0;
}
