#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

NoPtrFila criaNo(int n){
        NoPtrFila NovoNo=(NoPtrFila)malloc(sizeof(NoFila));
        NovoNo->n=n;
        NovoNo->prox=NULL;
        return NovoNo;
}

TFila* IniciaFila()
{
	TFila* Fila=(TFila*)malloc(sizeof(Fila));
	Fila->First=NULL;
	Fila->Last=NULL;
	Fila->tam=0;
	return Fila;
}

void Enfilera(TFila* Fila, int n)
{
	NoPtrFila NovoNo=criaNo(n);
	if(Fila->tam==0)
	{
		Fila->First=NovoNo;
		Fila->Last=NovoNo;
	}
	else{
		Fila->Last->prox=NovoNo;
		Fila->Last=NovoNo;
	}
	Fila->tam++;
}

int EhVazia(TFila *Fila)
{
	return (Fila->tam==0);
}

int Desinfilera(TFila* Fila)
{
	if(EhVazia(Fila))
		return 0;
	int n;
	NoPtrFila temp=Fila->First;
	Fila->First=temp->prox;
	n=temp->n;
	free(temp);
	Fila->tam--;
	return n;
}

