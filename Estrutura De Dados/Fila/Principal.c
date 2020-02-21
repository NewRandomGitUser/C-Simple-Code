#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main()
{
	TFila* Fila=IniciaFila();
	int tam, n;
	scanf("%d", &tam);

	for(int i=0;i<tam;i++)
	{
		scanf("%d", &n);
		Enfilera(Fila, n);
	}

	while(!EhVazia(Fila))
	{
		n=Desinfilera(Fila);
		printf("%d ", n);
	}
	printf("\n");

	return 0;
}


