#include <stdio.h>
#include <stdlib.h>

#define OK          0
#define ERRORE      1
#define MAX_CODA    10

struct Queue 
{
    int *deposit;
    int first_free;
    int n_occupati;

};

int insert_queue(struct Queue *c, int val);
int get_queue(struct Queue c, int *val);
int remove_queue (struct Queue *c, int *val);
void print_queue(struct Queue c);

void init_queue(struct Queue *c);
int is_full (struct Queue *c);
int is_empty (struct Queue *c);
int min (int *vect, int size);
void free_v(struct Queue *c);




int main ()
{
    int decisione;
    struct Queue c;
    int val, err = 0;
    int val1;
    int val2;
           
    init_queue(&c);
    do
    {
         printf ("Prendi una decisione, cosa vuoi fare ?\n");
            printf(" Inserisci nella coda = 1 \n");
            printf (" Leggi dalla coda = 2 \n");
            printf (" Leggi e poi rimuovi dalla coda = 3 \n");
            printf (" Se vuoi uscire = 0 \n");
            scanf ("%d",&decisione);
    

        switch (decisione)
        {
        case 1:
            printf ("Inserisci un valore da inserire nella coda: ");
            scanf ("%d",&val);

                err = insert_queue(&c, val);
                    if (err == 0)
                    {
                        printf ("Inserito correttamente. \n");
                    }            
                    else
                        printf ("Errore nell'inserimento. \n");
            break;
        case 2:
            printf ("Lettura dalla coda...\n");
            err = get_queue(c, &val1);
                    if (err == 0)
                        printf ("Il valore letto e': %d. \n", val1); 
                    else 
                        printf ("Errore nella lettura. \n");  
            break;
        case 3:
            printf ("Coda prima della rimozione: ");
                print_queue(c);
            printf ("Rimozione dalla coda...\n");
                err = remove_queue (&c, &val2);
                    if (err == 0)
                    {
                        printf("Nuova coda:\n");
                        print_queue(c);
                        printf("Il valore eliminato e': %d. \n", val2);
                    }
                    else
                        printf ("Errore durante l'eliminazione. \n");                  
            break;
        default:
            break;
        }
    }
    while (decisione != 0);

    //printf ("\nPRIMA %p \n", c.deposit);
    
    free_v (&c);
    
    //printf ("\nDOPO %p \n", c.deposit);
    return 0;
}

void init_queue(struct Queue *c)
{
    c -> first_free = 0;
    c -> n_occupati = 0;
    c -> deposit = (int *) malloc (MAX_CODA * sizeof (int));
}

int is_empty(struct Queue *c)
{
    if(c -> first_free == 0)
    {
        return ERRORE;
    }
    return OK;
}

int is_full(struct Queue *c)
{
    if (c -> first_free >= MAX_CODA)
    {
        return ERRORE;
    }
    return OK;
}

int min (int *vect, int size)
{
    int m;
	
	if (size == 1) 
    {
        return vect[0];
    }
	m = min(vect, size - 1);
	if (vect[size - 1] < m)
    { 
		return vect[size - 1];
    }
	else
		return m;
}

int insert_queue(struct Queue *c, int val)
{
    if (is_full(c) == 1)
    {
       return ERRORE;
    }

    c -> deposit[c -> first_free] = val;
    c->first_free = (c->first_free+1) % MAX_CODA;
    c -> n_occupati ++;
    
    return OK;
}

int get_queue(struct Queue c, int *val)
{
    if (c.first_free == 0)
    {
        return ERRORE;
    }

    *val = c.deposit[0];

    return OK;
}

int remove_queue (struct Queue *c, int *val)
{

     if (is_empty(c)== 1)
    {
        return ERRORE;
    }

    *val = min (c -> deposit, c -> n_occupati);

    for (int i = 0;  i < (c -> first_free) - 1; i++)
    {
        if (c -> deposit[i] == *val)
        {
            for (int j = i; j < (c -> first_free) - 1; j++)
            {
                c -> deposit [j] = c -> deposit [j + 1];
            }
        }
    }

    c -> first_free --;
    c -> n_occupati --;

    return OK;
}

void print_queue(struct Queue c)
{
    if (is_empty(&c) == 1)
    {
        printf ("La pila e' vuota\n");
    }
    printf ("{");
    for (int i = 0; i < (c.first_free); i++)
    {
        printf (" %d ",c.deposit[i]);
    }
    printf ("}\n");
}

void free_v(struct Queue *c)
{
    free(c -> deposit);
}
















