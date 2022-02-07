
//La radice digitale di un numero intero n è definita come il risultato della somma delle cifre checompongono il numero, 
//ripetuta consecutivamente finché essa non ha un valore ad una solacifra. 
//Per esempio, la radice digitale di 1729 può essere calcolata con i seguenti passi:
//1. 1 + 7 + 2 + 9 = 19
//2. 1 + 9 = 10
//3. 1 + 0 = 1 (una sola cifra <-> radice digitale di 1729)
//Scrivere una funzione DigitalRoot(n) che restituisce la radice digitale di n.

int sumDigit(int n)
{
	if (n % 10 == n) return n;
	return n%10 +  sumDigit(n/10);
}


int digitalRoot(int n)
{
	int x = sumDigit(n);
	
	if (x<10) return x;
	return digitalRoot(x);
}