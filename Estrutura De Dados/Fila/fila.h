#ifndef Fila_H
#define Fila_H
#include <stdio.h>
#include <stdlib.h>

typedef struct TNoFila NoFila;
typedef struct TNoFila* NoPtrFila;

struct TNoFila{
        int n;
        NoPtrFila prox;
};

typedef struct{
        NoPtrFila First;
        NoPtrFila Last;
        int tam;
}TFila;

TFila* IniciaFila();
void Enfilera(TFila* Fila, int n);
int EhVazia(TFila *Fila);
int Desinfilera(TFila* Fila);
#endif
