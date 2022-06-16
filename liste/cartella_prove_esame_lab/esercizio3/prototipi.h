#include <stdio.h>
#include <stdlib.h>

#define FILE_SIZE   256
#define MAX_CHAR    5

struct Classe;

void readFile(char *In_fileName, struct Classe **head);

void stampa_lista(struct Classe *head);

void eliminate(struct Classe **head);

void writeFile(char *Out_fileName, struct Classe *head);

void free_list(struct  Classe **head);