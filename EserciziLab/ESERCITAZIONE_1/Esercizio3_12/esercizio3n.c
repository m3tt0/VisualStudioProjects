#include <stdio.h>
#include <stdlib.h>

float media (int n);

int main ()
{
	int n;
	float m;
	printf ("Inserisci la quantita' preferita di numeri: ");
	scanf ("%d", &n);

	m = media (n);

	printf ("La media dei numeri pari inseriti è: %.1f\n", m);


return 0;
}

float media (int n)
{
        float med = 0;
        int i;
        float num, sum = 0;
	int count = 0;

        printf ("Inserisci %d numeri interi per sapere la media: ", n);

        for (i = 0; i < n; i++)
        {
                scanf ("%f", &num);
		if (((int)num % 2) == 0)
		{
	                sum += num;
			count++;
		}
        }

        med = (sum / count);

return med;
}
