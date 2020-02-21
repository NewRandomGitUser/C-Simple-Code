#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

int main()
{
        int n;
        scanf("%d",&n);
        TGrafo* Grafo = Inicia(n);
        int v1,v2;
        scanf("%d %d", &v1,&v2);
        while(!feof(stdin))
        {
                InsereAresta(Grafo,v1,v2);
                scanf("%d %d", &v1,&v2);
        }
        ImprimeGrafo(Grafo);
        return 0;
}

