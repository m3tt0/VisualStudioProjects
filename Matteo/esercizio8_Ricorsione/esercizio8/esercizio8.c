
//Stampare una stringa con una funzione ricorsiva

void printStr(char *s)
{
	if (*s != '\0') {
		putchar(*s);
		printStr(s+1);
	} 
}
