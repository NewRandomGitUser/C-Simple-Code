#include <stdio.h>
#include <stdlib.h>
#include "/home/fulano/Área de Trabalho/code/Estrutura de Dados/Grafo/Grafo.h"
#include "/home/fulano/Área de Trabalho/code/Estrutura de Dados/Pilha/pilha.h"
#define NaoVisitado -1

void ImprimeVetor(int *v, int n)
{
        for(int i=0;i<n;i++)
        {
                if(i!=n-1)
                        printf("%d ", v[i]);
                else
                        printf("%d", v[i]);
        }
}

int* BuscaEmProfundidade(TGrafo* Grafo, int s)
{
        int V = Grafo->V;//numero de vértices do grafo

        TPilha* Pilha = IniciaPilha();
        int *distancia = (int *)malloc(V*sizeof(int));
        int VerticeAnterior[V];

        for(int i=0;i<V;i++)
                distancia[i] = NaoVisitado;

        Empilha(Pilha, s);
        distancia[s]=0;

        while(!EhVazia(Pilha))
        {
                int u = Desempilha(Pilha);
                NoPtr Temp = Grafo->Lista[u]->Head;
                while(Temp!=NULL)
                {
                        int n = Temp->n;
                        if(distancia[n] == NaoVisitado)
                        {
                                Empilha(Pilha, n);
                                VerticeAnterior[n] = u;
                                distancia[n] = distancia[VerticeAnterior[n]] + 1;
                        }
                        Temp = Temp->prox;
                }
        }
        return distancia;
}


int main()
{
        int n;
        scanf("%d",&n);
        TGrafo* Grafo = Inicia(n);
        int v1,v2;
        scanf("%d %d", &v1,&v2);
        for(int i=0;i<19;i++)
        {
                InsereAresta(Grafo,v1,v2);
                scanf("%d %d", &v1,&v2);
        }
        ImprimeGrafo(Grafo);

        int s;
        scanf("%d",&s);
        int *d = BuscaEmProfundidade(Grafo, s);
        ImprimeVetor(d, n);
	printf("\n");
        return 0;
}

