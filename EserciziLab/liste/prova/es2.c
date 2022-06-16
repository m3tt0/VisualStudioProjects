#include <stdio.h>
#include <stdlib.h>

struct element
{
	int dato;
	struct element* next;
};
typedef struct element nodo;

//nodo* remove_at(nodo* puntatore, int indice);
void insert(nodo** testa, int valore);
void eliminate(nodo** puntatore, int valore);
void stampa_lista(nodo* puntatore);

int main(){

	nodo* testa = NULL;
	//nodo* in_esame = NULL;
	int scelta = -1;
	int valore, elimina;

	while(scelta != 0)
	{
		printf("Cosa vuoi fare?\n");
		printf("1) Inserisci un valore\n");
		printf("2) Elimina un valore\n");
		printf("3) Stampa lista\n");
		printf("0) Esci\n");
		scanf("%d", &scelta);
		puts("");

		switch(scelta)
		{
			case 1:
				printf("Che valore vuoi inserire?\n");
				scanf("%d", &valore);
				insert(&testa, valore);
				break;
		
			case 2:
				printf("Che valore vuoi eliminare?\n");
				scanf("%d", &elimina);
				eliminate(&testa, elimina);
				break;

			case 3:
				stampa_lista(testa);
				break;

			case 0:
				printf("Chiusura del programma.\n");
				exit(0);

			default:
				printf("Inserito numero di scelta sbagliato.\n");
				exit(0);
		}

	}
	
	return 0;
}

void insert(nodo** testa, int valore)
{

	nodo* nuovo = NULL;
	nuovo = (nodo* )malloc(sizeof(nodo));

	if (nuovo == NULL)
	{
		printf("Qualcosa è andato storto.\n");
		exit(0);
	}

	   nuovo->dato = valore;
    nuovo->next = (*testa);
    (*testa) = nuovo;
	
	return;
}

void eliminate(nodo** puntatore, int valore)
{
	while((*puntatore)->dato != valore)
	{
		(*puntatore) = (*puntatore)->next;

		if ((*puntatore)->dato == valore)
		{
			nodo* precedente = NULL;
			precedente = (nodo *)malloc(sizeof(NULL));

			precedente = (*puntatore);
			precedente->next = (*puntatore);
			free(*puntatore);
			(*puntatore) = (*puntatore)->next; 		
		}
	}
}

void stampa_lista(nodo* puntatore)
{

	printf("Lista: ");
	while(puntatore != NULL)
	{
		printf("[%d] -> ", puntatore->dato);
		puntatore = puntatore->next;
	}

	printf("NULL\n");
	puts("");
}