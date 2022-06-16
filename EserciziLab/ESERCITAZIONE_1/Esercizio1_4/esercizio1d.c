#include <stdio.h>
#include <stdlib.h>

float calcoloMedia (float a, float b, float c, float d);

int main ()
{
	float a,b,c,d;
	float media;
	printf ("Inserisci quattro numeri di cui vuoi sapere la media: ");
	scanf ("%f%f%f%f", &a,&b,&c,&d);

	media = calcoloMedia (a,b,c,d);
	printf ("La media dei quattro numeri e': %.2f\n", media);

return 0;
}


float calcoloMedia (float a, float b, float c, float d)
{
	float media;
	media = (a + b + c + d) / 4;
return media;
}
