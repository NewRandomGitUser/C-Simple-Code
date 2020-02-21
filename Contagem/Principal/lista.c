#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

TLista* IniciaLista()
{
	TLista* Lista=(TLista*)malloc(sizeof(TLista));
	Lista->Head=NULL;
	return Lista;
}


int Vazia(TLista *Lista){
	return Lista->Head==NULL;
}


void Insere(TLista *Lista, char palavra[30]){
	NoPtr NovoNo=(NoPtr)malloc(sizeof(No));
	strcpy(NovoNo->palavra, palavra);
	NovoNo->cont=1;
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


void Imprime(TLista *Lista){
	NoPtr No = Lista->Head;
	while(No!=NULL){
		printf("%s %d\n", No->palavra, No->cont);
		No=No->prox;
	}
}


int Atualiza(TLista *Lista, char palavra[30]){
	NoPtr Temp = Lista->Head;
	while(Temp!=NULL){
		if(strcmp(palavra,Temp->palavra)==0){
			Temp->cont++;
			return 0;
		}
		Temp=Temp->prox;
	}
	Insere(Lista, palavra);
	return 1;
}
