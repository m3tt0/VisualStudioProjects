#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
	int num;
	int valAss;

	printf ("Inserisci un numero per saperne il valore assoluto: ");
	scanf ("%d", &num);

	valAss = abs (num);

	printf ("Il valore assoluto di |%d| e' %d\n",num, valAss);
return 0;
}
