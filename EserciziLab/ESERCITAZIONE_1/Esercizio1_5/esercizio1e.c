#include <stdio.h>
#include <stdlib.h>

float calcoloMedia (float a, float b, float c, float d, float p1, float  p2, float p3, float p4);

int main ()
{
	float a,b,c,d;
	float p1,p2,p3,p4;
	float media ;	

	printf ("Inserisci quattro numeri: ");
	scanf ("%f%f%f%f",&a,&b,&c,&d);
	puts ("");
	printf ("Inserisci i pesi dei numeri, per sapere la media ponderata: ");
	scanf ("%f%f%f%f", &p1,&p2,&p3,&p4);

	media = calcoloMedia (a,b,c,d,p1,p2,p3,p4);
	printf ("La media ponderata dei numeri e': %.2f\n", media);


return 0;
}

float calcoloMedia (float a, float b, float c, float d, float p1, float p2, float p3, float p4)
{
	float media;
	media = ((a*p1)+(b*p2)+(c*p3)+(d*p4))/(p1+p2+p3+p4);
return media;
}
