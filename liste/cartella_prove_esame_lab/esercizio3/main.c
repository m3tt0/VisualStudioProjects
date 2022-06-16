#include <stdio.h>
#include <stdlib.h>
#include "strutture_dati.h"
#include "prototipi.h"


int main ()
{
    struct Classe *c = NULL;
    char *In_fileName = (char *) malloc (FILE_SIZE * sizeof(char));
    char *Out_fileName = (char *) malloc (FILE_SIZE * sizeof(char));


    printf ("Inserisci il nome del file da cui leggere: ");
    scanf ("%s", In_fileName);

//Lettura dal file di input ed inserimento nella lista, successiva stampa a video della lista letta.
    readFile(In_fileName, &c);
    printf("\n<-----Lista appena letta----->\n");
    stampa_lista(c);

//Eliminazione delle occorrenze (#Studenti ≠ #Promossi + #Bocciati + #Rimandati), successiva stampa a video della lista.
    eliminate(&c);
    printf("\n<-----Lista dopo eliminazione----->\n");
    stampa_lista(c);

    printf ("Inserisci il nome del file su cui scrivere: ");
    scanf ("%s", Out_fileName);

//Scrittura della nuova lista creata su un file di output, in ordine decrescente in base al numero di promossi.
    writeFile(Out_fileName, c);

    free (In_fileName);
    free (Out_fileName);

    free_list(&c);

    return 0;
}