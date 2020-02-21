#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct TNo No;
typedef No* NoPtr;

struct TNo{
	char palavra[30];
	int cont;
	NoPtr prox;
};

typedef struct{
	NoPtr Head;
}TLista;

TLista* IniciaLista();
int Vazia(TLista *Lista);
void Insere(TLista *Lista, char palavra[30]);
void Imprime(TLista *Lista);
int Atualiza(TLista *Lista, char palavra[30]);
#endif
