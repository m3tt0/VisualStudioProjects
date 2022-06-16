#include <stdio.h>
#include <stdlib.h>

#define FILE_SIZE   256

struct Matrice;

int **readFile(char *In_fileName, int *righe, int *colonne);

void stampa_matrice(int **matrix, int righe, int colonne);

int is_magic(int **matrix, int righe, int colonne);

void create_list(int **matrix, struct Matrice **head, int righe, int colonne);

void stampa_lista(struct Matrice *head);

int eliminate(struct Matrice **head);

int modify_matrix(int ***matrix, struct Matrice *head, int righe, int colonne);

//void writeFile(char *Out_fileName, int **matrix, int righe, int colonne);

//void free_list(struct Matrice *head);

int **allocMatrix (int righe, int colonne);