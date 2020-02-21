#include "Grafo.h"
#include <stdio.h>
#include <stdlib.h>
TGrafo* Inicia(int V)
{
        TGrafo* Grafo =(TGrafo*)malloc(sizeof(TGrafo));

        Grafo->V=V; Grafo->E=0;

        Grafo->Lista = (TLista**)malloc(V*sizeof(TLista*));
        for(int i=0;i<V;i++)
                Grafo->Lista[i]=IniciaLista();

        return Grafo;
}

int ExisteAresta(TGrafo* Grafo, int v1, int v2)
{
        if(v1 > Grafo->V || v2 > Grafo->V)
                return -1;//um dos vértices não pertence ao grafo
        if(Vazia(Grafo->Lista[v1]))
                return 0;//v1 não está conectado com nenhum vértice

        NoPtr Temp = Busca(Grafo->Lista[v1],v2);
        if(Temp==NULL)
                return 0;//v1 não está conectado com v2
        return 1;//v1 está conectado com v2
}

int InsereAresta(TGrafo* Grafo, int v1, int v2)
{
        int Existe = ExisteAresta(Grafo, v1, v2);
        if(Existe==-1)
                return -1;//Os vértices não pertencem ao grafo
        if(Existe==1)
                return 0;//Já existe uma aresta entre v1 e v2   
        Insere(Grafo->Lista[v1],v2);
        Insere(Grafo->Lista[v2],v1);
        Grafo->E++;
        return 1;
}
int RemoveAresta(TGrafo* Grafo, int v1, int v2)
{
        int Existe = ExisteAresta(Grafo, v1, v2);
        if(Existe==-1)
                return -1;
        if(Existe==0)
                return 0;
        Remove(Grafo->Lista[v1],v2);
        Remove(Grafo->Lista[v2],v1);
        Grafo->E--;
        return 1;
}

void ImprimeGrafo(TGrafo* Grafo)
{
        for(int i=0;i < Grafo->V;i++)
        {       printf("[%d] - ",i);
                if(Vazia(Grafo->Lista[i]))
                        printf("\n");
                else
                        Imprime(Grafo->Lista[i]);
        }
}
