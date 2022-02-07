#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMES		100

int readVoti(const char *nomeFile,int *voti, char **nomi, int N);
int findWinner(int *voti, char **nomi, int Nnomi, int **eletti);
void printWinner(int maxVoti, int *eletti, char **nomi);
void freeNomi(char **nomi, int Nnomi);

int main()
{
	int voti[MAX_NAMES] = {0}, *eletti;
	char *nomi[MAX_NAMES] = {NULL};
	int Nnomi, maxVoti;
	
	Nnomi = readVoti("voti.txt",voti, nomi, MAX_NAMES);
	maxVoti = findWinner(voti, nomi, Nnomi, &eletti);
	printWinner(maxVoti, eletti, nomi);
	
	freeNomi(nomi, Nnomi);
	free(eletti);
}
#undef MAX_NAMES


#define FILE_READ_ERROR		10
#define TOO_MANY_NAMES		20
#define MEMORY_ALLOC_ERROR	30

void gestisciErrore(int code)
{
	if (code == FILE_READ_ERROR) {
		printf("Errore lettura file\n");
	}
	if (code == TOO_MANY_NAMES) {
		printf("Troppi nomi\n");
	}
	if (code==MEMORY_ALLOC_ERROR) {
		printf("Errore allocazione memoria\n");
	}
	exit(-1);
}


int findNome(char **nomi, char *nome, int *Numnomi, int N)
{
	int i;
	int Nnomi = *Numnomi;
	int length;
	
	for (i=0; i<Nnomi; i++) {
		if (strcmp(nomi[i], nome) == 0) return i;
	}
	if (Nnomi == N) {
		gestisciErrore(TOO_MANY_NAMES);
	}
	length = strlen(nome);
	nomi[Nnomi] = (char *) malloc((length+1)*sizeof(char));
	strcpy(nomi[Nnomi], nome);

	*Numnomi = *Numnomi+1;
	
	return Nnomi;
}

int readVoti(const char *nomeFile,int *voti, char **nomi, int N)
{
	FILE *fp;
	char nome[256];
	int index;
	int Nnomi = 0;
	
	fp = fopen(nomeFile, "r");
	if (fp == NULL) {
		gestisciErrore(FILE_READ_ERROR);
	}
	
	while (fscanf(fp,"%s",nome) == 1) {
		index = findNome(nomi, nome, &Nnomi, N);
		voti[index] = voti[index] + 1;
	}
	
	fclose(fp);
	
	return Nnomi;
}

void freeNomi(char **nomi, int Nnomi)
{
	int i;
	
	for (i=0; i<Nnomi; i++)
	{
		free(nomi[i]);
	}
}

#define NOINDEX	-1
int findWinner(int *voti, char **nomi, int Nnomi, int **eletti)
{
	int maxVoti = 0;
	int i;
	int count = 0;
	int *Eletti;
	int index = 0;
	
	for (i=0; i<Nnomi; i++)
	{
		if (maxVoti < voti[i]) {
			maxVoti = voti[i];
			count = 1;
		} else if (maxVoti==voti[i]) count++;
	}
	
	Eletti = (int *)malloc((count+1)*sizeof(int));
	if (Eletti==NULL) {
		gestisciErrore(MEMORY_ALLOC_ERROR);
	}
	
	
	for (i=0; i<Nnomi; i++) {
		if (maxVoti==voti[i]) {
			Eletti[index] = i;
			index++;
		}
	}
	Eletti[index] = NOINDEX;
	
	*eletti = Eletti;
	return maxVoti;
}

void printWinner(int maxVoti, int *eletti, char **nomi)
{
	int index, i=0;

    printf("Eletti:\n");
	while (eletti[i] != NOINDEX) {
		index = eletti[i];
		printf("%s\n", nomi[index]);
		i = i + 1;
	}
	printf("Voti %d\n", maxVoti);
}

#undef NOINDEX



