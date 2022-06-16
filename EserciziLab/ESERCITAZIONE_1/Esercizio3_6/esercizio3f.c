#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int i;

	for (i = 1; i <= 50; i++)
	{
		if ((i % 2) == 0)
		{
			printf ("%d  ",i);
				if ((i % 5) == 0)
				{
					printf ("\n");
		}		}
	}


return 0;
}
