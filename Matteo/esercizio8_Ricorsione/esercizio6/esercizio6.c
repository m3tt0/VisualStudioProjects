
//Il massimo comun divisore di due interi non negativi è l'intero più grande che è divisore dientrambi i numeri. 
//Il MCD di x e y può essere calcolato in base al seguente algoritmo:
//1. se x è divisibile per y, allora y è il MCD
//2. Altrimenti, il MCD tra x e y è sempre uguale al MCD di y e del resto della divisione tra x e y 
//Scrivere una funzione ricorsiva MCD(x,y) che restituisca il massimo comun divisore fra x e y.

#include <stdio.h>

int mcd(int x, int y)
{
	if (y == 0) return x;
	return mcd(y, x%y);
}

int main()
{
	int x, y;
	
	scanf("%d%d",&x,&y);
	
	printf("%d\n", mcd(x,y));
}