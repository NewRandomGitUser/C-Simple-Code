#ifndef Pilha_H
#define Pilha_H
#include <stdio.h>
#include <stdlib.h>
typedef struct TNoPilha NoPilha;
typedef NoPilha* NoPtrPilha;

struct TNoPilha
{
        int n;
	NoPtrPilha prox;
};


typedef struct
{
        NoPtrPilha Top;
        int tam;
}TPilha;

TPilha* IniciaPilha();
int EhVazia(TPilha *Pilha);
void Empilha(TPilha* Pilha, int n);
int Desempilha(TPilha* Pilha);
#endif
