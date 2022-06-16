#include <stdio.h>
#include <stdlib.h>

#define NUM 10

int main ()
{
	int i;

	for (i = 0; i <= NUM; i++)
	{
		printf ("%d - ",i);
	}

	printf("\nDecrescente\n");
	for (i = NUM; i >= 0; i--)
	{
		printf ("%d - ", i);
	}

return 0;
}
