#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

TPilha* IniciaPilha()
{
	TPilha* Pilha=(TPilha*)malloc(sizeof(TPilha));
	Pilha->Top=NULL;
	Pilha->tam=0;
	return Pilha;
}

int EhVazia(TPilha *Pilha)
{
	return (Pilha->tam==0);
}

void Empilha(TPilha* Pilha, int n)
{
	NoPtrPilha NovoNo=(NoPtrPilha)malloc(sizeof(NoPilha));
	NovoNo->n=n;
	NovoNo->prox=Pilha->Top;
	Pilha->Top=NovoNo;
	Pilha->tam++;
}


int Desempilha(TPilha* Pilha)
{
	int n;
	NoPtrPilha Temp=Pilha->Top;
	Pilha->Top=Temp->prox;
	Pilha->tam--;
	n=Temp->n;
	free(Temp);
	return n;
}
