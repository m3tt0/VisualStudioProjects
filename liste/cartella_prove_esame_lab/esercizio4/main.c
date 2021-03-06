#include <stdio.h>
#include <stdlib.h>
#include "prototipi.h"
#include "strutture_dati.h"


int main ()
{
    char *In_fileName = (char *) malloc (FILE_SIZE * sizeof(char));
    char *Out_fileName = (char *) malloc (FILE_SIZE * sizeof(char));

    int **matrix;
    int righe, colonne;

    struct Matrice *m = NULL;

    printf("Inserisci il nome del file da cui leggere: ");
    scanf ("%s", In_fileName);

    matrix = readFile(In_fileName, &righe, &colonne);
    printf("Matrice letta dal file: \n");
    stampa_matrice(matrix, righe, colonne);

    int err = is_magic(matrix, righe, colonne);
    if (err == 0)
    {
        printf ("La matrice è magica.\n");
    }
    else
    {
        printf ("La matrice NON è magica.\n");
    }

    create_list(matrix, &m, righe, colonne);
    printf("-----Nuova lista creata-----\n");
    stampa_lista(m);

    int err1 = eliminate(&m);
    if (err1 == 0)
    {
        printf ("Eliminazione avvenuta correttamente.\n");
        printf("-----Lista dopo l'eliminazione-----\n");

        stampa_lista(m);
    }
    else
    {
        printf("Errore durante l'eliminazione.\n");
    }
/*   
    int err2 = modify_matrix(&matrix, m, righe, colonne);
    if (err2 == 0)
    {
        printf("Modifica avvenuta correttamente.\n");
        stampa_matrice(matrix, righe, colonne);
     }
 
        printf("\nInserisci il nome del file di output.\n");
        scanf("%s", Out_fileName);

        writeFile(Out_fileName, matrix, righe, colonne);
    }
    else
    {
        printf("Errore durante la modifica della matrice.\n");
    }




    free(In_fileName);
    free(Out_fileName);
    free_list(m);
*/
    return 0;
}
