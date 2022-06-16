#include <stdio.h>
#include <stdlib.h>

#define piGreco  3.14

float calcoloArea (float r);

int main ()
{
	float raggio;
	float area;
	printf ("Inserisci la dimensione del raggio: ");
	scanf ("%f", &raggio);
	
	area = calcoloArea (raggio);
	printf ("L'area del cerchio è: %.2f\n",area);

return 0;
}

float calcoloArea (float r)
{
	float area;
	area = (r*r)*piGreco;
return area;
}

