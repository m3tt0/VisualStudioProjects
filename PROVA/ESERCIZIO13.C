//simulazione esami

#include <stdio.h>
#include <stdlib.h>

//codice errori
#define     FILE_READ_ERROR     10
#define     MEMORY_ALLOC_ERROR  20
#define     FILE_WRT_ERROR      30
#define     OUT_OF_RANGE        40


//gestione degli errori
void gestione_errori( int code);

//lettura del file 
int **read_file(const char *nomefile, int *righe, int *colonne);

//allocazione matrice 
int **allocMatrix(int x, int y);

//scrittura matrice
void wrtMatrix(int **ptr , int m, int n);


int main()
{   
    int **matrice;
    char nomefile[20];
    int righe;
    int colonne, i, j;

    printf("Inserisci il nome del file di input -->");
    scanf("%s", nomefile);

    matrice = read_file(nomefile, &righe, &colonne);

    
    for (i = 0; i < righe; i++) {
        for ( j = 0; j < colonne; j++){
            printf("%d ", matrice[i][j]);
        }
        printf("\n"); 
    }

    return 0;
}

//lettura del file
int **read_file(const char *nomefile, int *righe, int *colonne)
{
    FILE *fp;
    int **matrix;
    int i, j;
    int rows;
    int columns;


    fp=fopen(nomefile, "r");
    if (fp == NULL) {
        gestione_errori(FILE_READ_ERROR);
    }
    
    fscanf(fp, "%d %d", &rows, &columns);

    matrix =allocMatrix(rows, columns);

    if (matrix == NULL) {
        gestione_errori(MEMORY_ALLOC_ERROR);
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            fscanf(fp, "%d", matrix[i] + j);
        }
    }
    
    *righe=rows;
    *colonne= columns;

    fclose (fp);

    return matrix;
}

//gestione degli errori
void gestione_errori( int code)
{
    if (code == FILE_READ_ERROR) {
        perror("Errore lettura file\n");
    }
    
    if (code == MEMORY_ALLOC_ERROR){
        perror("Errore allocazione memoria\n");
    }
    
    if (code == FILE_WRT_ERROR){
        perror("Errore scrittura file\n");
    }
    if (code == OUT_OF_RANGE) {
        perror("Errore generico");
    }
    exit(-1);
}

//allocazione memoria matrice 
int **allocMatrix(int m, int n)
{
    int i;
    int **ptr;

   ptr = (int **) malloc(m*sizeof(int *));

   if ( ptr==NULL)  return ptr;
   
    ptr[0]= (int *) malloc(m*n*sizeof(int));

    if (ptr==NULL) {

        free((void *) ptr);
        return NULL;
    }

    for (i = 1; i < m; i++) {

       ptr[i]= ptr[i-1] + n;
    }
    
    return ptr;
}

//scrittura della matrice
void wrtMatrix(int **ptr , int m, int n)
{
    int i, j;

    for (i = 0; i < m; i++) {
        for ( j = 0; j < n; j++){
            printf("%d ", ptr[i][j]);
        }
        printf("\n"); 
    }
}