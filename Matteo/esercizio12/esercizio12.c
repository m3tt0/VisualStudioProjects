//Si consideri un file contenente informazioni su un insieme di attività di una settimana (una per riga), con il formato che si evince dal file "agenda.txt".
//Il nome dell’attività è una stringa (massimo 20 caratteri) senza spazi, e tutte le informazioni nel file sono separate tra loro da uno o più spazi. 
//L’orario è sempre descritto solo da un intero rappresentante le ore (non ci sono i minuti).
//Inoltre, tutte le attività iniziano e terminano nella stessa settimana, quindi non è possibile ad esempio che un’attività inizi il Venerdı̀ e termini il Martedı̀, oppure che inizi Sabato alle 20 e termini Sabato alle 17.
//Si scriva un programma in C che prenda come parametro il nome di un file siffatto e restituisca gli eventi di lunghezza massima presenti nel file con la durata.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFile(const char *nomeFile, int * Neventi, int *** eventi, char *** impegni);
int *findLongest(int **eventi, int Neventi);
void printSelectedEvents(int **eventi, char **impegni, int Neventi, int *indexEventi);
void freeAgenda(int **eventi, char **impegni, int Neventi);


int main()
{
	int Neventi;
	char **impegni;
	int **eventi, *indexEventi;
	
	readFile("agenda.txt", &Neventi, &eventi, &impegni);
	indexEventi = findLongest(eventi, Neventi);
	printSelectedEvents(eventi, impegni, Neventi, indexEventi);
	
	freeAgenda(eventi, impegni, Neventi);
	free(indexEventi);
}

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


#define NCAMPI	5
#define LUNGHEZZASTR	25
void allocAgenda(int Neventi, int ***eventi, char ***impegni)
{
	int **ev, i;
	char **imp;
	
	ev = (int**) malloc(Neventi*sizeof(int *));
	if (ev == NULL) {
		gestisciErrore(MEMORY_ALLOC_ERROR);
	}
	
	ev[0] = (int *)malloc(Neventi*NCAMPI*sizeof(int));
	
	if (ev[0] == NULL) {
		gestisciErrore(MEMORY_ALLOC_ERROR);
	}
	for (i=1; i<Neventi; i++) {
		ev[i] = ev[i-1] + NCAMPI;
	}
	
	imp = (char **)malloc(Neventi*sizeof(char *));
	
	for (i=0; i<Neventi; i++) {
		imp[i] = (char *)malloc(LUNGHEZZASTR*sizeof(char));
	}
	
	*eventi = ev;
	*impegni = imp;
}

void freeAgenda(int **eventi, char **impegni, int Neventi)
{
	int i;
	
	free(eventi[0]);
	free(eventi);
	
	for (i=0; i<Neventi; i++) {
		free(impegni[i]);
	}
	
	free(impegni);
}


#define LUNEDI			1
#define	MARTEDI			2
#define	MERCOLEDI		3
#define	GIOVEDI			4
#define VENERDI			5
#define SABATO			6
#define	DOMENICA		7	

int dayStr2dayNum(char *giorno)
{
	if (strcmp(giorno,"Lunedi")==0) return LUNEDI;
	else if (strcmp(giorno,"Martedi")==0) return MARTEDI;
	else if (strcmp(giorno,"Mercoledi")==0) return MERCOLEDI;
	else if (strcmp(giorno,"Giovedi")==0) return GIOVEDI;
	else if (strcmp(giorno,"Venerdi")==0) return VENERDI;
	else if (strcmp(giorno,"Sabato")==0) return SABATO;
	else return DOMENICA;
}

void dayNum2dayStr(int dayNum, char *dayStr)
{
	switch (dayNum) {
		case LUNEDI: strcpy(dayStr, "Lunedi"); break;
		case MARTEDI: strcpy(dayStr, "Martedi"); break;
		case MERCOLEDI: strcpy(dayStr, "Mercoledi"); break;
		case GIOVEDI: strcpy(dayStr, "Giovedi"); break;
		case VENERDI: strcpy(dayStr, "Venerdi"); break;
		case SABATO: strcpy(dayStr, "Sabato"); break;
		default: strcpy(dayStr, "Domenica");
	}
}

int durataEvento(char *giornoInizio, int oraInizio, char *giornoFine, int oraFine)
{
	int day1, day2;
	
	day1 = dayStr2dayNum(giornoInizio);
	day2 = dayStr2dayNum(giornoFine);
	
	return 24*(day2-day1) + (oraFine-oraInizio);
}
#undef LUNEDI
#undef MARTEDI
#undef MERCOLEDI
#undef GIOVEDI
#undef VENERDI
#undef SABATO
#undef DOMENICA

#define GIORNO_INIZIO 		0
#define ORA_INIZIO			1
#define	GIORNO_FINE			2
#define	ORA_FINE			3
#define	DURATA				4

void insertInAgenda(int i, int **eventi, char **impegni, char *impegno, char *giornoInizio, int oraInizio, 
					char *giornoFine, int oraFine)
{
	strcpy(impegni[i], impegno);
	
	eventi[i][GIORNO_INIZIO] = dayStr2dayNum(giornoInizio);
	eventi[i][ORA_INIZIO] = oraInizio;
	eventi[i][GIORNO_FINE] = dayStr2dayNum(giornoFine);
	eventi[i][ORA_FINE] = oraFine;
	eventi[i][DURATA] = durataEvento(giornoInizio, oraInizio, giornoFine, oraFine);
}

void readFile(const char *nomeFile, int * N, int ***ev, char *** imp)
{
	FILE *fp;
	int **eventi, Neventi;
	char **impegni;
	int i;
	char impegno[LUNGHEZZASTR], giornoInizio[LUNGHEZZASTR], giornoFine[LUNGHEZZASTR];
	int oraInizio, oraFine;
	
	fp = fopen(nomeFile, "r");
	if (fp == NULL) {
		gestisciErrore(FILE_READ_ERROR);
	}
	
	fscanf(fp,"%d", &Neventi);
	allocAgenda(Neventi, &eventi, &impegni);
	
	for (i=0; i<Neventi; i++) {
		fscanf(fp,"%s%*s%s%*s%d%*s%s%*s%d",impegno, giornoInizio, &oraInizio, giornoFine, &oraFine);
		insertInAgenda(i, eventi, impegni, impegno, giornoInizio, oraInizio, giornoFine, oraFine);
	}
	
	fclose(fp);
	
	*N = Neventi;
	*ev = eventi;
	*imp = impegni;
}


int *findLongest(int **eventi, int Neventi)
{
	int *indiciEventi;
	int i, max = 0;
	
	indiciEventi = (int *)calloc(Neventi, sizeof(int));
	if (indiciEventi == NULL) {
		gestisciErrore(MEMORY_ALLOC_ERROR);
	}
	
	for (i=0; i<Neventi; i++) {
		if (max < eventi[i][DURATA]) {
			max = eventi[i][DURATA];
		}
	}
	
	for (i=0; i<Neventi; i++) {
		if (max == eventi[i][DURATA]) {
			indiciEventi[i] = 1;
		}
	}
	
	return indiciEventi;
}

void printSelectedEvents(int **eventi, char **impegni, int Neventi, int *indexEventi)
{
	int i;
	char giornoInizio[LUNGHEZZASTR], giornoFine[LUNGHEZZASTR];
	int oraInizio, oraFine, durata;
	
	
	for (i=0; i<Neventi; i++) {
		if (indexEventi[i] == 1) {
			dayNum2dayStr(eventi[i][GIORNO_INIZIO], giornoInizio);
			dayNum2dayStr(eventi[i][GIORNO_FINE], giornoFine);
			oraInizio = eventi[i][ORA_INIZIO];
			oraFine = eventi[i][ORA_FINE];
			durata = eventi[i][DURATA];
			
			printf("%s da %s ore %d a %s ore %d. Durata %d minuti\n", impegni[i], 
			giornoInizio, oraInizio, giornoFine, oraFine, durata);
		}
	}
}
