#include <stdio.h>
#include <stdlib.h>

float calcolaPerimetro (float b, float a);
float calcoloArea (float b, float a);

int main ()
{
	float base, altezza;
	float perimetro, area;
	printf ("Inserisci base ed altezza: ");
	scanf ("%f%f",&base,&altezza);
	if (base <= 0 || altezza <= 0)
	{
		printf ("Devi inserire dei valori positivi e maggiori di zero, riprova !");
		exit (-1);
	}
	perimetro = calcolaPerimetro (base, altezza);
	area = calcoloArea (base, altezza);

	printf ("Il perimetro del rettangolo con base = %.2f e con altezza = %.2f e': %.2f\n",base, altezza, perimetro);
	printf ("L'area del rettangolo con base = %.2f e con altezza = %.2f e': %.2f\n", base, altezza, area);

	return 0;
}

float calcolaPerimetro (float b, float a)
{
	float perimetro = 0;
	perimetro = 2*(b + a);

 return perimetro;
}

float calcoloArea (float b, float a)
{
	float area = 0;
	area = b * a;

 return area;
}













