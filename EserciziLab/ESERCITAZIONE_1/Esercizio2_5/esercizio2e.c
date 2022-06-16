#include <stdio.h>
#include <stdlib.h>

float verificaMaggiore (float a, float b, float c);

int main ()
{
	float a, b, c;
	float max;

	printf ("Inserisci tre numeri per sapere quale è il maggiore: ");
	scanf ("%f%f%f", &a, &b, &c);

	max = verificaMaggiore (a, b, c);
	printf ("Il numero più grande è %.2f\n", max);

return 0;
}


float verificaMaggiore (float a, float b, float c)
{
	float max;

	if (a >= b)
	{
		if (a >= c)
		{
			max = a;
		}
		else
			max = c;
	}
	else
	{
		if (b >= c)
		{
			max = b;
		}
		else
			max = c;
	}
return max;
}
