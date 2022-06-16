#include <stdlib.h>
#include <stdio.h>

#define N_PILA 256

#define FULL -1
#define EMPTY -2
#define OK 0
struct Pila
{
    char deposito[N_PILA];
    int n_occupati;

};

void init_stack (struct Pila* p)
{
    p->n_occupati = 0;
}

int is_empty(struct Pila* p)
{
    if(p->n_occupati <= 0)
        return 1;
    return 0;
}


int is_full(struct Pila* pila)
{
    if(pila->n_occupati >= N_PILA)
        return 1;
    return 0;
}

int pop(struct Pila* p, char* val)
{
    if(is_empty(p)== 1)
        return EMPTY;
    *val = p->deposito[p->n_occupati-1];
    p->n_occupati--;
    return OK;
}


int push(struct Pila* p, char val)
{
    if(is_full(p) == 1)
        return FULL;
    p->deposito[p->n_occupati] = val;
    p->n_occupati++;
    return OK;
}


int main()
{
    struct Pila p;
    init_stack(&p);
    
    char s[N_PILA];
    
    printf("stringa: ");
    scanf("%s", s);
    
    int i = 0;
    while(s[i] !='\0')
    {
        push(&p,s[i]);
        i++;
    }
    
    i       = 0;
    int pal = 1;
    while(s[i] !='\0' && pal == 1)
    {
        char c;
        pop(&p, &c);
        if(s[i] != c)
            pal = 0;
        i++;
    }
    
    if(pal == 1)
    {
        printf("la stringa %s è palindroma\n", s);
    
    }
    else
    {
        printf("la stringa %s non è palindroma\n", s);
    
    }
    
    return 0;
}