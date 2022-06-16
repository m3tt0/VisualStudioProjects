#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strutture_dati.h"
#include "prototipi.h"

//Funzione per la lettura da file ed inserimento nella lista
void readFile(char *In_fileName, struct Classe **head)
{
    FILE *fp; //creazione del puntatore a FILE.
    fp = fopen (In_fileName, "r"); //apertura dei file in lettura.
    if (fp == NULL)
    {
        printf ("Errore nella lettura del file.\n");
        return;
    }
    else
    {
        while (feof(fp) == 0) // finché il file non è finito bisogna continuare a leggere ed inserire nella lista
        {
            struct Classe *new = (struct Classe*) malloc (sizeof(struct Classe)); //creazione di un nuovo puntatore alla struct Classe, questo servirò per memorizzare le cose lette da file.
            char *Classe = (char *) malloc (MAX_CHAR * sizeof (char)); //vettore di appoggio per il campo Classe[] della struct.

            fscanf (fp, "%s %d %d %d %d", Classe, &(new -> Studenti), &(new -> Promossi), &(new -> Bocciati), &(new -> Rimandati));//lettura di tutti gli elementi dal file
            strcpy ((new -> Classe), Classe);//copia del vettore di appoggio nella listam, nel campo Classe
            new -> next = NULL; //il campo next è sempre inizializzato a NULL

            struct Classe *corrente = *head; //tengo traccia del corrente per non modificare il puntatore alla testa della lista
            struct Classe *precedente = NULL;//tengo traccia anche del precedente

//se la lista non è vuota, scorro tutta la lista e imposto i precedenti per ogni nodo
            while (corrente != NULL)
            {
                precedente = corrente;
                corrente = corrente -> next;
            }
//se invece la lista è vuota e quindi sono al primo nodo, devo inizializzare la testa della lista
            if (precedente == NULL)
            {
                *head = new;
            }
//altrimenti devo assegnare al campo next di ogni precedente il valore del nuovo nodo creato
            else
            {
                precedente -> next = new;
            }
        }
    }

    fclose (fp);
}

//funzione di stampa della lista a schermo
void stampa_lista(struct Classe *head)
 {
    while (head != NULL)
    {
        printf ("%s\t\t%d\t%d\t%d\t%d\n", (head -> Classe), (head -> Studenti), (head -> Promossi), (head -> Bocciati), (head -> Rimandati));
        head = head -> next;
    }
 }

//funzione di eliminazione delle occorrenze specificate 
void eliminate(struct Classe **head)
{
    struct Classe *corrente = *head; //creo una lista di appoggio
    struct Classe *precedente = NULL;//tengo traccia del precedente

//scorro tutta la lista fino alla fine
    while (corrente != NULL)
    {
        //verifico se i campi Studenti di ogni nodo sono diversi dalla somma dei Promossi, Bocciati e Rimandati
        if ((corrente -> Studenti) != ((corrente -> Promossi) + (corrente -> Bocciati) + (corrente -> Rimandati)))
        {
            //in tal caso bisogna eliminare quel nodo dalla lista, allora lo memorizza in un'altra lista d'appoggio
            struct Classe *del = corrente;
            //verifico se siamo nel primo nodo, in tal caso modifico proprio la testa della lista
            if (precedente == NULL)
            {
                (*head) = del -> next;
            }
            //altrimenti modifico il campo next di precedente, inserendogli il successivo al quale deve puntare il nodo precedente a quello da eliminare
            else
            {
                precedente -> next = del -> next;
            }
            //passo al successivo nodo da esaminare ed elimino il nodo che soddisfa la condizione
            corrente = del -> next;
            free(del);
        }
        //se invece la condizione iniziale non è soddisfatta vado semplicemente avanti con la lista, tenendo traccia del precedente
        else
        {
            precedente = corrente;
            corrente = corrente -> next;
        }
        
    }

}

//funzione di scrittura su file
void writeFile(char *Out_fileName, struct Classe *head)
{
//PROBLEMA RISCONTRATO QUI
//lo scopo di questa funzione era quello di stampare su un file di output la lista, dopo l'eliminazione, in ordine decrescente
//per fare ciò avevo pensato di usare un vettore di puntatori alla 'struct Classe' questo però mi ha portato a commettere lo stesso errore della volta precedente
//ovvero quello di usare un VLA, fortemente sconsigliato, volevo provare ad allocare dinamicamente questo vettore di puntatori, ma non sono stato in grado di capire 
//come fare, questo è il problema che volevo porre all'attenzione del professore.

	FILE *filePointer = fopen(Out_fileName, "w");

	if (filePointer == NULL)
	{
		puts("Errore nella creazione del file, chiusura del programma");
		exit(-1);
	}
	else
	{
        //mi scorro tutta la lista per contare quanti nodi ci sono
		int nodes = 0;
        struct Classe *tmp1 = head;
        while (tmp1 != NULL)
        {
            nodes++;
            tmp1 = tmp1 -> next;
        }
//uso questi nodi per creare un array di puntatori, statico. //ERRATO
		struct Classe **list_in_array = malloc(nodes * sizeof(struct Classe *));

//inserisco all'interno di ogni cella dell'array i puntatori ad ogni nodo
		for (int i = 0; i < nodes; i++)
		{
			list_in_array[i] = head;
			head = head->next;
		}
//con un bubblesort modificato vado ad ordinare ogni cella, ovvero ogni nodo della lista, in ordine decrescente
		for (int i = 0; i < nodes - 1; i++)
		{
			for (int j = 0; j < nodes - 1; j++)
			{
				if (list_in_array[j]->Promossi <= list_in_array[j+1]->Promossi)
				{
					struct Classe *tmp = list_in_array[j];
					list_in_array[j] = list_in_array[j+1];
					list_in_array[j+1] = tmp;
				}
			}
		}
//stampa della lista su file
		for (int i = 0; i < nodes; i++)
		{
			fprintf(filePointer, "%s  \t%d  %d  %d  %d\n", list_in_array[i]->Classe, list_in_array[i]->Studenti, list_in_array[i]->Promossi, list_in_array[i]->Bocciati, list_in_array[i]->Rimandati);
		}

        free(list_in_array);
        free_list(tmp1);
        free_list(tmp);
	}
}


/*
void writeFile(char *Out_fileName, struct Classe *head)
{
    FILE *fp;
    fp = fopen (Out_fileName, "w");

        if (fp == NULL)
        {
            printf ("Errore durante la scrittura su file.");
            return;
        }
        else
        {
            struct Classe *max = NULL;
            int max_found = 1;

                while (max_found == 1)
                {
                    struct Classe *corrente = head;
                    struct Classe *p_max = NULL;

                    max_found = 0;
                    
                        while (corrente != NULL)
                        {
                            if (max == NULL || corrente -> Promossi < max -> Promossi)
                            {
                                if (p_max == NULL || corrente -> Promossi > p_max -> Promossi)
                                {
                                    p_max = corrente;
                                    max_found = 1;
                                }
                            }
                            corrente = corrente -> next;
                        }

                        if (p_max != NULL)
                        {
                            fprintf (fp, "%s\t\t%d\t%d\t%d\t%d\n", p_max -> Classe, p_max -> Studenti, p_max -> Promossi, p_max -> Bocciati, p_max -> Rimandati);
                            corrente = p_max -> next;

                            while (corrente != NULL)
                            {
                                if (corrente -> Promossi == p_max -> Promossi)
                                {
                                    fprintf (fp,"%s\t\t%d\t%d\t%d\t%d\n", corrente -> Classe, corrente -> Studenti, corrente -> Promossi, corrente -> Bocciati, corrente -> Rimandati);
                                }
                                    corrente = corrente -> next;
                            }
                        }

                    max = p_max;
                }
        }
    fclose (fp);
}*/

//funzione di deallocazione della lista
void free_list(struct  Classe **head)
{
    struct  Classe *tmp;
    while((*head) != NULL)
    {
        tmp = (*head)->next;
        free(*head);
        (*head) = tmp;
    
    }
}