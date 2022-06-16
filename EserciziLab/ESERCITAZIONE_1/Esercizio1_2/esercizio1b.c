#include  <stdio.h>
#include <stdlib.h>

float calcoloArea (float b, float a);


int main ()
{
	float base, altezza;
	float area;
	
	printf ("Inserisci base e altezza del triangolo: ");
	scanf ("%f%f", &base,&altezza);
	
	area = calcoloArea (base, altezza);
	
	printf ("L'area del triangolo con base = %.2f e altezza = %.2f e': %.2f\n", base, altezza, area);

	return 0;
}

float calcoloArea (float b, float a)
{
	float area;
	area = (b * a)/2;

	return area;
}
