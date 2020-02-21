#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
	TPilha *Pilha=IniciaPilha();

	int n;
	scanf("%d", &n);
	while(!feof(stdin))
	{
		Empilha(Pilha,n);
		scanf("%d", &n);
	}

	while(!EhVazia(Pilha))
	{
		n=Desempilha(Pilha);
		printf("%d ",n);	
	}
	printf("\n");
	return 0;	
}
