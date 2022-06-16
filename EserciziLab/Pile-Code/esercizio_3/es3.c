#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>


#define MAX_STACK       32
#define OK              0
#define ERRORE          1


struct Stack 
{
    int deposito[32];
    int n_occupati;
};

int insert_stack(struct Stack *s, int val);
void dec_to_bin(struct Stack *s, int *val1);

void init_stack(struct Stack *c);
int is_full (struct Stack *c);
int is_empty (struct Stack *c);
void free_v(struct Stack *c);
void print_queue(struct Stack c);


int main ()
{
    int decisione;
    struct Stack s;
    init_stack(&s);

    int val, err = 0;
    int val1;

    do
    {
            
            printf(" Inserisci nella pila = 1 \n");
           //printf (" Leggi e poi rimuovi dalla coda = 2 \n");
            printf ("Mostra il risultato della conversione binaria = 2 \n");
            printf (" Se vuoi uscire = 0 \n");
            scanf ("%d",&decisione);
    

        switch (decisione)
        {
        case 1:
            printf ("Inserisci un valore da inserire nella pila: ");
                scanf ("%d",&val);
                   err = insert_stack(&s, val);
                        if (err == 0)
                        {
                            printf ("Inserimento effettuato !\n");
                            //print_queue(s);
                        }
                        else 
                            printf ("La pila è piena !\n");
            break;
        case 2:
            printf ("Conversione in binario, attendere...\n");
            sleep(5);
                dec_to_bin(&s, &val1);
                    printf ("Numero binario: %d\n\n", val1);    
                        free_v(&s);
                        //print_queue(s);
            break;
        default:
            break;
        }
    }
    while (decisione != 0);

    return 0;
}


void init_stack(struct Stack *c)
{
    c -> n_occupati = 0; 
}

int is_empty(struct Stack *c)
{
    if(c -> n_occupati == 0)
    {
        return ERRORE;
    }
    return OK;
}

int is_full(struct Stack *c)
{
    if (c -> n_occupati >= MAX_STACK)
    {
        return ERRORE;
    }
    return OK;
}

int insert_stack(struct Stack *s, int val)
{
    if (is_full(s) == ERRORE)
    {
        return ERRORE;
    }

    while (val != 0)
    {
       int resto = val % 2;
        val = val / 2;
        s -> deposito[s -> n_occupati] = resto;
        s -> n_occupati ++;
    }
        return OK;
}

void dec_to_bin(struct Stack *s, int *val1)
{
    int bin;
    int j = 0;
    for (int i = (s -> n_occupati) - 1; i >= 0; i--)
    {
        bin = (s -> deposito[i]) * (pow(10, j));
        j++;
        *val1 = *val1 + bin;
    }
}

void free_v(struct Stack *c)
{
    for (int i = 0; i< (c -> n_occupati); i++)
    {
        c -> deposito[i] = 0;
    }
}

void print_queue(struct Stack c)
{
    if (is_empty(&c) == 1)
    {
        printf ("La pila e' vuota\n");
    }
    printf ("{");
    for (int i = 0; i < (c.n_occupati); i++)
    {
        printf (" %d ",c.deposito[i]);
    }
    printf ("}\n");
}