#ifndef ListaLigada_H
#define ListaLigada_H
#include <stdio.h>
#include <stdlib.h>

typedef struct TNo No;
typedef No* NoPtr;

struct TNo{
	int n;
	NoPtr prox;
};

typedef struct{
	NoPtr Head;
}TLista;

TLista* IniciaLista();
int Vazia(TLista *Lista);
NoPtr Busca(TLista* Lista, int n);
void Insere(TLista *Lista, int n);
int Remove(TLista *Lista, int n);
void Imprime(TLista *Lista);
#endif
