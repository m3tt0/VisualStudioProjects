#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
	//Successione Fibonacci
	int n;
	long int a = 0;
	long int b = 1;
	long int x;
	
	float y;
	float q;
	
	
	printf ("Inserisci il valore a cui vuoi far riferimento: ");
	scanf ("%d" , &n);
	
	for (int i = 0; i < n; i++)
	{
		x = b + a;
		a = b;
		b = x;
		
		y = (float)(x / b);
		q= (y + sqrt(5)) / 2;
		
		printf ("Successione: %ld \n" , x);
		printf ("Quoziente: %f \n", q);
	}
	
	
	
	
	return 0;
	
}
