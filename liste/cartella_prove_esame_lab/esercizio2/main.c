#include <stdio.h>
#include <stdlib.h>
#include "strutture_dati.h"
#include "prototipi.h"

int main ()
{
    char in_fileName[FILE_SIZE];
    char out_fileName[FILE_SIZE];

    struct Persona *start = NULL;
    int err, err1;
    int num_el;
    float **matrix;

//Inserimento del file di input
    printf("Inserisci il nome del file di input: ");
    scanf("%s", in_fileName);
//Lettura dal file in questione e inserimento nella lista concatenata
   err = read_File(in_fileName, &start, &num_el);
   if (err == 0)
   {
       printf ("Lettura del file avvenuta correttamente!\n\n");
   }
   else
   {
       printf ("Errore nella lettura del file!\n");
   }
   //Stampa della lista a schermo
    printf("-------------Lista attuale!----------------- \n\n");
    print_list(start);

//Elimazione delle occorrenze minori di 12 chili
   err1 = eliminate(&start, &num_el);
   if (err1 == 0)
   {
       printf ("\nEliminazione avvenuta!\n\n");
   }
   else
   {
       printf ("Eliminazione NON avvenuta!\n");
   }    
    printf("-------------Lista dopo l'eliminazione!---------------- \n\n");
    print_list(start);
    
    printf("\n\n-------------Matrice delle medie---------------- \n\n");
    matrix = create_matrix(start, num_el);
    stampa_matrix(matrix, num_el);

    printf ("Inserisci il nome del file di output: ");
    scanf("%s", out_fileName);
    write_File(out_fileName, start, num_el, matrix);

    free_list(start);
    freeMatrix(matrix);

    return 0;
}