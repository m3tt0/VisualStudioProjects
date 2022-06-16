#include <stdio.h>
#include <stdlib.h>
#include "prototipi.h"


int main ()
{
    char fileName [256];
    FILE *fp;

    printf ("Inserisci il nome del file da leggere:\n");
    scanf ("%s", fileName);

    fp = fopen (fileName, "r");
    if (fp == NULL)
    {
        printf("Errore nell'apertura del file!\n");
    }
    else
    {
/*
        char car;
        int num_rows = 0;

        while (feof(fp) == 0)
        {
            fscanf(fp, "%c", &car);
            if (car == "#")
            {
                puts("");
            }
            if (car == "\n")
            {
                num_rows++;
            }
        }

        struct Ingredienti *array = (struct Ingredienti *) malloc (num_rows * sizeof(struct Ingredienti));
*/
        write_file(fp);

    }

    fclose (fp);
    
    return 0;
}