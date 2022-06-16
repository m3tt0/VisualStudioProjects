#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define EOR '\0'

int lenght (char *string);

int main ()
{
	char *string;
	int dim;
	long int maxChar;

	maxChar = pow (2, 32);

	string = (char *) malloc (maxChar * sizeof(char));

	printf ("Inserisci una parola per saperne la lunghezza: ");
	scanf ("%s", string);

	dim = lenght (string);

	printf ("La stringa e' lunga %d caratteri\n", dim);

return 0;
}

int lenght (char *string)
{
	int dim = 0;
	int count = 0;

	while (string[count] != '\0')
	{
		dim ++;
		count ++;
	}

return dim;
}

