#include <stdio.h>
#include <stdlib.h>
#include "ListaLigada.h"

TLista* IniciaLista()
{
	TLista* Lista=(TLista*)malloc(sizeof(TLista));
	Lista->Head=NULL;
	return Lista;
}


int Vazia(TLista *Lista){
	return Lista->Head==NULL;
}


NoPtr Search(NoPtr Temp, int n){	
	if(Temp->n==n)
		return Temp;
	if(Temp->prox!=NULL)
		return Search(Temp->prox,n);
	return NULL;
}


NoPtr Busca(TLista *Lista, int n)
{
	if(Vazia(Lista))
		return NULL;
	else
		return Search(Lista->Head, n);
}


void Insere(TLista *Lista, int n){
	NoPtr NovoNo=(NoPtr)malloc(sizeof(No));
	NovoNo->n=n;
	NovoNo->prox=NULL;
	if(Vazia(Lista))
		Lista->Head=NovoNo;
	else{
	
		NoPtr Ultimo = Lista->Head;
		while(Ultimo->prox!=NULL)
			Ultimo=Ultimo->prox;
		Ultimo->prox=NovoNo;
	}
}

int Remove(TLista *Lista, int n)
{
	if(Vazia(Lista))
		return -1;
	NoPtr Alvo = Busca(Lista,n);
	if(Alvo==NULL)
		return 0;
	if(Alvo == Lista->Head)
	{
		Lista->Head = Alvo->prox;
		free(Alvo);
		return 1;
	}
	NoPtr TempAntes = Lista->Head;
	while(TempAntes->prox->n!=n)
		TempAntes=TempAntes->prox;
	TempAntes->prox=Alvo->prox;
	free(Alvo);
	return 1;
}

void Imprime(TLista *Lista){
	if(!Vazia(Lista))
	{
		NoPtr No = Lista->Head;
		while(No!=NULL)
		{
			if(No->prox != NULL)
				printf("%d ", No->n);
			else
				printf("%d", No->n);
			No=No->prox;

		}
		printf("\n");
	}
}
