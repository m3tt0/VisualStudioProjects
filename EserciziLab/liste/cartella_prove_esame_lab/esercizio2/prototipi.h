#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR    20
#define FILE_SIZE   256
#define ERR_FILE_READ   1
#define ERR_FILE_WRITE  2


struct Persona;
int read_File(const char *fileName, struct Persona **head, int *num);
void print_list(struct Persona *head);
int eliminate(struct Persona **head, int *num);
float **create_matrix(struct Persona *head, int num);
float **allocMatrix (int dim);
void stampa_matrix(float **matrix, int dim);
void write_File(const char *out_fileName, struct Persona *head, int num, float **matrix);
void free_list(struct  Persona *head);
void freeMatrix(float **matrix);
int max(int *v, int n);