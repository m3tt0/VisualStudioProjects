#include <stdio.h>
#include <stdlib.h>

void operazioni (int a, int b, int op);

int main ()
{
	int a, b;
	int op;

	printf ("Inserisci due valori: ");
	scanf ("%d%d", &a, &b);
	printf ("1 = somma - 2 = differenza - 3 = prodotto - 4 = quoziente\n");
	scanf ("%d", &op);
	operazioni (a, b, op);

return 0;
}

void operazioni (int a, int b, int op)
{
	int somma, differenza, prodotto, quoziente;
	switch (op)
	{
		case 1:
			somma = a + b;
			printf ("Somma: %d\n", somma);
		break;
		case 2:
			differenza = a - b;
			printf ("Differenza: %d\n", differenza);
		break;
		case 3:
			prodotto = a * b;
			printf ("Prodotto: %d\n", prodotto);
		break;
		case 4:
			quoziente = a / b;
			printf ("Quoziente: %d\n", quoziente);
		break;
		default:
			printf ("NESSUNA OPERAZIONE\n");
		break;
	}
}
