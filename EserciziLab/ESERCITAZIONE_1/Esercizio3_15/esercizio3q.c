#include <stdio.h>
#include <stdlib.h>


int main ()
{
	int i;

	for (i = 1; i < 51; i++)
	{
		printf (" * ");
		if ((i % 10) == 0)
		{
			puts (" ");
		}
	}

	printf ("\n");

return 0;
}
