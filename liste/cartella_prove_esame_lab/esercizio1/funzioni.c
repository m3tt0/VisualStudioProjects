#include <stdio.h>
#include <stdlib.h>
#include "prototipi.h"


void write_file (FILE *fp)
{
    FILE *fpTmp;
    
    fpTmp = fopen ("Ingredienti.toc", "w");
    if (fpTmp == NULL)
    {
        printf("Errore nella scrittura su file!\n");
    }
    else
    {
        char car, flag;
        char array[20], arrayTmp[20];
        float quantita;

          while (feof(fp) == 0)
        {
            if (fscanf (fp, "%s %c %f*", array, &car, &quantita) == 3)
            {
                fprintf (fpTmp, "%s  %c  %.2f\n", array, car, quantita);
               /* fscanf(fp, "%c", &flag);*/
                if (flag == ' ')
                {
                    printf("\n");
                }
            }
        }
    }

fclose(fpTmp);

}