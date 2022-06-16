#include <stdio.h>
#include <stdlib.h>

#define  M1  1.80
#define  M2  1.65

void calcolo (int n);

int main ()
{
	int n;
	printf ("Inserisci il numero di individui: ");
	scanf ("%d", &n);

	calcolo (n);


return 0;
}

void calcolo (int n)
{

	float metri;
	int i;
	float media;
	float sum = 0;
	int count1 = 0;
	int count2 = 0;

	printf ("Inserisci le corrispettive %d altezze: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%f",&metri);
		sum += metri;

		if (metri > M1)
		{
			count1++;
		}
		else if (metri < M2)
		{
			count2++;
		}

	}

	media = (sum / n);

	printf ("La media delle %d altezze e': %.2f\n", n, media);
	printf ("Le persone più alte di %.2f metri sono: %d\n", M1, count1);
	printf ("Le persone più basse di %.2f metri sono: %d\n", M2, count2);


}
