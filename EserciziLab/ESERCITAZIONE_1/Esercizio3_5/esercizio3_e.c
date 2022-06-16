#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int j;

	for (j = 1; j <= 50; j++)
	{
		printf ("%d ", j);
		if ((j % 10) == 0)
		{
			printf ("\n");
		}
	}


return 0;
}
