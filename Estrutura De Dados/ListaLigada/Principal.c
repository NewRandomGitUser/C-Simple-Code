#include <stdio.h>
#include <stdlib.h>
#include "ListaLigada.h"

int main()
{
	TLista *Lista=IniciaLista();
	int n;
	scanf("%d", &n);
	while(!feof(stdin))
	{
		Insere(Lista,n);
		scanf("%d",&n);
	}
	Imprime(Lista);
	scanf("%d",&n);
	while(!feof(stdin))
	{
		Remove(Lista,n);
		Imprime(Lista);
		scanf("%d",&n);
	}
	return 0;
}	
