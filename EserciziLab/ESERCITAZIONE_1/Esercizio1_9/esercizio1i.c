#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calcoloDelta (int a, int b, int c);
void calcoloX (int a, int b, int c, int d, int *x1, int *x2);

int main ()
{
	 int a, b, c;
	 int delta;
	int x1, x2;

	printf ("Inserisci i valori di a b c: ");
	scanf ("%d%d%d", &a,&b,&c);

	delta = calcoloDelta (a,b,c);
	if (delta >= 0)
	{
		calcoloX(a,b,c,delta,&x1,&x2);
		printf ("X1 = %d\n X2 =%d\n", x1,x2);
	}
	else
	{
		printf ("Il delta è pari a: %d, non ci sono soluzioni !", delta);
	}


return 0;
}

int calcoloDelta (int a, int b, int c)
{
	int delta;
	delta = (pow(b,2)-(4*a*c));

return delta;
}

void calcoloX (int a, int b, int c, int d, int *x1, int *x2)
{
	int xUno, xDue;

	 xUno = (-b - (sqrt(d)))/(2*a);
	 xDue = (-b + (sqrt(d)))/(2*a);

 *x1 = xUno;
 *x2 = xDue;
}
