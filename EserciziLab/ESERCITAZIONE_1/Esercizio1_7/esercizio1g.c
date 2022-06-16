#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float euclide (float x1, float x2, float y1, float y2);

int main ()
{
	float x1, y1;
	float x2, y2;
	float d;

	printf ("Inserisci le cordinate del punto P1:");
	scanf ("%f%f",&x1, &y1);

	printf ("Inserisci le cordinate del punto P2:");
	scanf ("%f%f",&x2,&y2);

	d = euclide (x1,x2,y1,y2);
	printf ("La distanza euclidea tra i due punti e': %.3f\n", d);

return 0;
}

float euclide (float x1, float x2, float y1, float y2)
{
	float dis;

	dis = sqrt ((pow((x1 - x2),2)) + (pow((y1 - y2),2)));
return dis;
}
