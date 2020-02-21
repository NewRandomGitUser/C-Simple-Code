/*
      Problema:
      Dado um valor Val e um conjunto D
      com diferentes valores de moedas para troco,
      incluindo sempre a moeda de 1 centavo,
      minimizar o número de moedas necessárias
      para fornecer o troco para Val.
      Solução:
      A abordagem aqui usada emprega Programação Dinâmica
      em uma estratégio top-down
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_INT 20

///////////////////////////////////// Lista ///////////////////////////////////
typedef struct TNo No;
typedef No* NoPtr;

struct TNo{
	int n;
	NoPtr prox;
};

typedef struct{
	NoPtr Head;
}TLista;

TLista* IniciaLista()
{
	TLista* Lista=(TLista*)malloc(sizeof(TLista));
	Lista->Head=NULL;
	return Lista;
}


int Vazia(TLista *Lista){
	return Lista->Head==NULL;
}


NoPtr Search(NoPtr Temp, int n){
	if(Temp->n==n)
		return Temp;
	if(Temp->prox!=NULL)
		return Search(Temp->prox,n);
	return NULL;
}


NoPtr Busca(TLista *Lista, int n)
{
	if(Vazia(Lista))
		return NULL;
	else
		return Search(Lista->Head, n);
}


void Insere(TLista *Lista, int n){
	NoPtr NovoNo=(NoPtr)malloc(sizeof(No));
	NovoNo->n=n;
	NovoNo->prox=NULL;
	if(Vazia(Lista))
		Lista->Head=NovoNo;
	else{

		NoPtr Ultimo = Lista->Head;
		while(Ultimo->prox!=NULL)
			Ultimo=Ultimo->prox;
		Ultimo->prox=NovoNo;
	}
}

int Remove(TLista *Lista, int n)
{
	if(Vazia(Lista))
		return -1;
	NoPtr Alvo = Busca(Lista,n);
	if(Alvo==NULL)
		return 0;
	if(Alvo == Lista->Head)
	{
		Lista->Head = Alvo->prox;
		free(Alvo);
		return 1;
	}
	NoPtr TempAntes = Lista->Head;
	while(TempAntes->prox->n!=n)
		TempAntes=TempAntes->prox;
	TempAntes->prox=Alvo->prox;
	free(Alvo);
	return 1;
}

void Imprime(TLista *Lista){
	if(!Vazia(Lista))
	{
		NoPtr No = Lista->Head;
		while(No!=NULL)
		{
			if(No->prox != NULL)
				printf("%d ", No->n);
			else
				printf("%d", No->n);
			No=No->prox;

		}
		printf("\n");
	}
}
/////////////////////////////////Fim da Lista /////////////////////////////////


int* Carrega(int n)
{
   int *v = (int *)malloc(n*sizeof(int));
   v[0] = 1; //A moeda de 1 centavo sempre faz parte do conjunto
   for(int i = 1; i < n; i++)
      scanf("%d", &v[i]); //Insere os outros valores no conjunto
    return v;
}

void BackTrackMin(int ValAtual, int *D, int NMoedasDiferentes, TLista *Lista)
{
  if(ValAtual == 0)
    {
      Imprime(Lista);
      return;
    }
  int res = MAX_INT;
  for(int i = 0; i < NMoedasDiferentes; i++)
  {
    if(D[i]<=ValAtual)
    { Insere(Lista,D[i]);
      BackTrackMin(ValAtual - D[i], D, NMoedasDiferentes,Lista);
      Remove(Lista,D[i]);
    }
  }
}

int main(){
   int NMoedasDiferentes; //Numero de diferentes moedas disponíveis
   int Valor; //Quantidade total fornecida na compra
   int *D; //Conjunto com os diferentes valores de moeda

   scanf("%d", &NMoedasDiferentes);
   D = Carrega(NMoedasDiferentes); //Constroi conjunto D
   scanf("%d", &Valor);
   TLista *Lista=IniciaLista();


   BackTrackMin(Valor,D,NMoedasDiferentes,Lista);
   return 0;
}
