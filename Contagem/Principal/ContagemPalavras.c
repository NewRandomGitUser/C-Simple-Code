#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"


int main(){
	
	TLista *Lista=IniciaLista();

	char texto[5000];
	char *palavra;
	gets(texto);
	while(!feof(stdin))
	{
		palavra = strtok(texto," ,.)(");
		while(palavra!=NULL)
		{
			Atualiza(Lista, palavra);
			palavra = strtok(NULL," ,.)(");/*strtok*/
		}
		gets(texto);
	}
	Imprime(Lista);

	return 0;
}
