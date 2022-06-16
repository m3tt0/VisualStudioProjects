#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CODA        20
#define MIN_CODA        1
#define MAX_PERSONE     20
#define MIN_PERSONE     1

struct Coda 
{
    int deposit[MAX_CODA];
    int first_free;
    int first_busy;
    int n_busy;
};

void init_coda (struct Coda *c);
void visualizza_cassa (struct Coda *c);
//int is_cassa_vuota (struct Coda *c);
int consuma_prodotto (struct Coda *c);

int is_empty (struct Coda *c);
int is_full (struct Coda *c);
int insert_queue (struct Coda *c);
//int read_queue (struct Coda *c);
int remove_queue (struct Coda *c);



int main ()
{
    srand(time(NULL));
    struct Coda c1;
    struct Coda c2;

    int decisione;
    int cassa_scelta = -1;

    init_coda(&c1);
    init_coda(&c2);

    int err = insert_queue(&c1);
    int err1 = insert_queue(&c2);

    if (err == 0)
    {
        printf ("1 - Inserimento avvenuto !\n");
    }
    if (err1 == 0)
    {
        printf ("2 - Inserimento avvenuto !\n");
    }
    else 
        printf ("Inserimento non avvenuto !\n");

    printf ("CASSA 1: \n");
    visualizza_cassa(&c1);
    printf ("CASSA 2: \n");
    visualizza_cassa(&c2);

    while (cassa_scelta != 1 && cassa_scelta != 2)
    {
        printf ("In quale cassa vuoi andare ?\t");
        scanf ("%d",&cassa_scelta);
        if (cassa_scelta != 1 && cassa_scelta != 2)
        {
            printf ("Fai una scelta corretta, non esiste la cassa %d !\n", cassa_scelta);
        }
    }

    while (decisione != 0 && (is_empty(&c1) == 0 && is_empty(&c2) == 0))
    {
        printf ("TI TROVI ALLA CASSA N: %d\n", cassa_scelta);

        printf ("CASSA 1: \n");
        visualizza_cassa(&c1);
        printf ("CASSA 2: \n");
        visualizza_cassa(&c2);

        printf ("Scegli cosa vuoi fare:\n 1. Cambiare cassa.\n 2. Restare alla cassa attuale\n");
        scanf ("%d", &decisione);

        switch (decisione)
        {
            case 1:
                if (cassa_scelta == 1)
                {
                    cassa_scelta = 2;
                }        
                else
                { 
                    cassa_scelta = 1;
                }
                    int err2 = consuma_prodotto(&c1);
                    int err3 = consuma_prodotto(&c2);
                        if (err2 == 1)
                        {
                            printf ("1 - Lista vuota, nessun prodotto da consumare!\n");
                        }
                        if (err3 == 1)
                        {
                            printf ("2 - Lista vuota, nessun prodotto da consumare!\n");
                        }
        break;
            case 2:
                int err4 = consuma_prodotto(&c1);
                int err5 = consuma_prodotto(&c2);
                        if (err4 == 1)
                        {
                            printf ("1 - Lista vuota, nessun prodotto da consumare!\n");
                        }
                        if (err5 == 1)
                        {
                            printf ("2 - Lista vuota, nessun prodotto da consumare!\n");
                        }
        break;
            case 0:
        break;
            default:
                printf("Scelta errata, riprova!\n");
        break;
        }
    }

    if (is_empty(&c1) == 1)
    {
        printf("La cassa 1 e' vuota !\n");
    }
    if (is_empty(&c2) == 1)
    {
        printf("La cassa 2 e' vuota !\n");
    }
     if (is_empty(&c1) == 1 && cassa_scelta == 1)
    {
        printf("Hai vinto.\n");
    }
    if  (is_empty(&c2) == 1 && cassa_scelta == 2)
    {
        printf("Hai vinto.\n");
    }
    else
    {
        printf ("Hai perso.\n");
    }

    printf ("CASSA 1: \n");
    visualizza_cassa(&c1);
    printf ("CASSA 2: \n");
    visualizza_cassa(&c2);


    return 0;
}

void init_coda (struct Coda *c)
{
    c -> first_free = 0;
    c -> first_busy = 0;
    c -> n_busy = 0;
}

int insert_queue (struct Coda *c)
{
    if (is_full(c) == 1)
    {
        return 1;
    }
    int n_persone = rand() % (MAX_PERSONE + 1 - MIN_PERSONE) + MIN_PERSONE;

    for (int i = 0; i < n_persone; i++)
    {
        c -> deposit[i] = rand() % (MAX_CODA + 1 - MIN_CODA) + MIN_CODA;
        c -> first_free ++;
        c -> n_busy ++;
    }
    return 0;
}

void visualizza_cassa (struct Coda *c)
{
    for (int i = 0; i < (c -> n_busy); i++)
    {
        printf (" O ");
            if (i == 0)
            {
                printf ("|");
            }
    }
    printf ("\n");
}

int is_empty(struct Coda *c)
{
    if(c -> first_free == 0)
    {
        return 1;
    }
    return 0;
}

int is_full(struct Coda *c)
{
    if (c -> first_free >= MAX_CODA)
    {
        return 1;
    }
    return 0;
}

int consuma_prodotto (struct Coda *c)
{
    if (is_empty(c) == 1)
    {
        return 1;
    }
    int n_prodotti = c -> deposit[0];
    if (n_prodotti > 0)
    {
        c ->deposit[0] = c ->deposit[0] - 1;
    }
    else
    {
        int err = remove_queue(c) ;
        if (err != 0)
        {
            printf ("Non ci sono elementi da rimuovere! \n");
        }
    }
    return 0;
}

int remove_queue (struct Coda *c)
{
    if (is_empty(c) == 1)
    {
        return 1;
    }

    c -> first_busy = (c -> first_busy + 1) % MAX_CODA;
    c -> n_busy --;
    c -> first_free --;
    return 0;
}






























