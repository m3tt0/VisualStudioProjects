
//ERRATO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 20
#define LISTDIM 50
#define MINIMUM 300

struct azienda
{
	char NomeAzienda[DIM];
	int dipendenti;
	int dipartimenti;
	int sedi;	
	struct azienda* next;
};
typedef struct azienda node;

//PUNTO 1 

struct azienda *insert(node* head, FILE* fp);
void print_list(node* head);

//PUNTO 2

void eliminate_record(node** head, int min_limit);

//PUNTO 3

void write_list(node** head);

//DEALLOCAZIONE CONCLUSIVA DELLA LISTA

void deallocate_list(node** head);

node *deallocate(node* start);

int main()
{
	char FileName[DIM];
	
	printf("Inserisci il nome del file da aprire: ");
	scanf("%s", FileName);

	FILE *filePointer = fopen(FileName, "r");

	if (filePointer == NULL)
	{
		printf("Errore nell'apertura del file, chiusura del programma.\n");
		exit(0);
	}
	else
	{

		node* head = NULL;

		head = insert(head, filePointer);

		printf ("PRIMA\n");
		print_list(head);

	
		eliminate_record(&head, MINIMUM);
		printf ("DOPO\n");
		print_list(head);

		write_list(&head);
		deallocate_list(&head);
	}

	fclose(filePointer);

	return 0;
}


struct azienda *insert(node* head, FILE* fp)
{
	
	char array_temp[DIM];

	while(feof(fp) == 0)
	{
		node* new = (node *)malloc(sizeof(node));
		if (new == NULL)
		{
			printf("Errore nella creazione del nodo, chiusura del programma.\n");
			exit(0);
		}
		fscanf(fp, "%s%d%d%d", array_temp, &(new -> dipendenti), &(new -> dipartimenti), &(new -> sedi));
		strcpy ((new -> NomeAzienda), array_temp);
		
		new -> next= NULL;

	
		node *corrente = head;
		node *precedente = NULL;

		while (corrente != NULL)
		{
			precedente = corrente;
			corrente = corrente -> next;
		}

		if (precedente == NULL)
		{
			head = new;
		}
		else 
		{
			precedente -> next = new;
		}
						
	}
	return head;

}

void print_list(node* head)
{

	while (head != NULL)
	{
		printf("%s  ", head->NomeAzienda);
		printf("%d  ", head->dipendenti);
		printf("%d  ", head->dipartimenti);
		printf("%d\n", head->sedi);

		head = head->next;
	}
	
}

void eliminate_record(node** head, int min_limit)
{
	struct azienda* cursore = (*head);
    struct azienda* prec    = NULL;

    while(cursore != NULL)
    {
        if(cursore->dipendenti < min_limit)
        {
            struct azienda* to_del = cursore;
            if (prec == NULL)
                (*head) = to_del->next;
            else
                prec->next = to_del->next;
            
            cursore = to_del->next;
            free(to_del);
        }
        else
        {
            prec   = cursore;
            cursore = cursore->next;
           
        }
    }
}

void write_list(node** head)
{
	FILE *outputFile = fopen("output.txt", "w");

	if (outputFile == NULL)
	{
		printf("Errore nella creazione del file, chiusura del programma.\n");
		exit(0);
	}
	else
	{
		int counter = 0;
		int i;

		node *tmp = (*head);

		while (tmp != NULL)
		{
			tmp = tmp -> next;
			counter++;
		}
		
		node *list_in_array[counter];

		for (int j = 0; j < counter; j++)
		{
			list_in_array[j] = NULL;
		}
		
		node *corrente = (*head);		

		for (i = 0; i < counter; i++)
		{
			list_in_array[i] = corrente;
			corrente = corrente -> next;
		}

		node* tmp1 = NULL;

		for (int i = 0; i < counter; i++)
		{
			for (int j = 0; j < counter; j++)
			{
				if ((list_in_array[j]->dipendenti) < (list_in_array[j + 1]->dipendenti))
				{
					tmp1 = list_in_array[j];
					list_in_array[j] = list_in_array[j + 1];
					list_in_array[j + 1] = tmp1;
				}
			}
		}
			for (int i = 0; i < counter; i++)
			{
				fprintf(outputFile, "%s", list_in_array[i] -> NomeAzienda);
				fprintf(outputFile, " %d  ", list_in_array[i] -> dipendenti);
				fprintf(outputFile, "%d  ", list_in_array[i] -> dipartimenti);
				fprintf(outputFile, "%d\n", list_in_array[i] -> sedi);
			}
	}

	fclose(outputFile);
}

void deallocate_list(node** head)
{
	while((*head) != NULL)
	{
		node* tmp = (*head) -> next;
		free((*head));
		(*head) = tmp;
	}

	if ((*head) == NULL)
	{
		puts("Lista deallocata correttamente.");
	}
}

node *deallocate(node* start)
{
	node *tmp;
	node *precedente = start;
	node *corrente = start;

	if (corrente -> next)
	{
		tmp = corrente -> next;
		if (precedente)
		{
			precedente -> next = corrente;
		}
		else
		{
			start = tmp;
		}
		free (start);
	}
	return tmp;
}
