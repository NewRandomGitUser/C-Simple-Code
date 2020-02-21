#ifndef Grafo_H
#define Grafo_H
#include <stdio.h>
#include <stdlib.h>
#include "/home/fulano/Área de Trabalho/code/Estrutura de Dados/ListaLigada/ListaLigada.h"

typedef struct{
	int V,E;
	TLista** Lista;
}TGrafo;

TGrafo* Inicia(int V);
int ExisteAresta(TGrafo* Grafo, int v1, int v2);
int InsereAresta(TGrafo* Grafo, int v1, int v2);
int RemoveAresta(TGrafo* Grafo, int v1, int v2);
void ImprimeGrafo(TGrafo* Grafo);
#endif
