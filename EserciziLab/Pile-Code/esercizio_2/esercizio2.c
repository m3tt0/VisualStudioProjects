#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM         100
#define OK            0
#define ERRORE        1
#define FULL          2


struct Coda 
{
    char lettere[DIM];
    int free_pos;
    int busy_pos;
    int n_busy;
};

void init_coda (struct Coda *c);
int is_empty (struct Coda *c);
int is_full (struct Coda *c);
int insert (struct Coda *c, char valore);
int is_palindrom (struct Coda c);
void stampa_coda (struct Coda c);




int main ()
{
    struct Coda c; 
    init_coda (&c);
    int scelta;
	char val;
	int err;
	int var;


    do {
            printf ("Scegli: \n");
            printf (" Inserisci nella coda = 1 \n");
            printf (" Verifica se e' palindroma = 2 \n");
            printf (" Stampa la coda = 3 \n");
            printf (" Se vuoi uscire = 0 \n");
            scanf ("%d",&scelta);

        switch (scelta)
        {
            case 1:
                scanf (" %1c", &val);
                    err = insert (&c, val);
                     if(err == OK)                  
                    printf("valore inserito\n");
                else
                    printf("coda piena!\n");
                break;

            case 2:
                   var = is_palindrom(c);
                    if (var == 0)
                    {
                        printf ("La parola da te inserita e' palindroma !\n");
                    }
                    else 
                        printf ("La parola da te inserita NON e' palindroma !\n");
                            break;
	case 3:
		stampa_coda(c);
		break;
            default: 
                break;
        }

        }
        while (scelta != 0);

return 0;
}

void init_coda (struct Coda *c)
{
    c -> free_pos = 0;
    c -> busy_pos = 0;
    c -> n_busy = 0;
}

int is_empty (struct Coda *c)
{
    if (c -> n_busy == 0)
    {
        return OK;
    }
    return ERRORE;
}
int is_full (struct Coda *c)
{
    if (c -> n_busy >= DIM)
    {
        return OK;
    }
    return ERRORE;
}

int insert (struct Coda *c, char valore)
{
    if (is_full(c) == OK)
    {
        return FULL;
    }

    c -> lettere [c -> free_pos] = valore;
    c -> free_pos = (c -> free_pos + 1) % DIM;
    c -> n_busy++;

    return OK;
}

int is_palindrom (struct Coda c)
{
    int i;
    int j = (c.free_pos)-1;
    struct Coda temp;
    init_coda (&temp);

    temp = c;

    for (i = 0; i < (c.free_pos)-1; i++)
    {
        if (c.lettere[i] != temp.lettere[j])
       {
           return ERRORE;
       }
       j--;
    }    
    
    return OK;
}

void stampa_coda(struct Coda c)
{
	int i;
    printf ("Parola inserita: ");
		for (i = 0; i < (c.free_pos); i++)
		{
			printf ("%c",  c.lettere[i]);
		}
        printf ("\n");
}

