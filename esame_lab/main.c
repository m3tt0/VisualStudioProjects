/*
MATTEO ROCCO 
N86004039
*/


#include <stdio.h>
#include <stdlib.h>
#include "prototipi.h"
#include "strutture_dati.h"


int main()
{
    char *In_fileName = (char *) malloc (FILE_SIZE * sizeof(char));
    char *Out_fileName = (char *) malloc (FILE_SIZE * sizeof(char));

    printf ("Inserisci il nome del file da cui leggere: ");
    scanf ("%s", In_fileName);

    struct Tris *head = NULL;

    int err = load_matches_from_file(In_fileName, &head);
    if (err != 0)
    {
        printf("Errore durante il caricamente nella lista.\n");
    }
    else
    {
        printf ("Inserimento in lista avvenuto correttamente.\n");
    }

    
    print_list (head);

   /* printf ("\n----Lista dopo l'eliminazione---- \n");

    remove_tied(&head);

    print_list(head);




    free(In_fileName);
    free(Out_fileName);
    free_list(&head);
*/
    return 0;
}