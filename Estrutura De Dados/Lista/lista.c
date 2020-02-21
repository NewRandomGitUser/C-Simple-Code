#include <stdio.h>
#include <stdlib.h>

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

int InsereGeral(TLista* Lista, int n, int Posicao){
	if(Posicao!=1 && Vazia(Lista))
		return 0;//Tentativa de Inserir fora da primeira posição de uma lista vazia
	if(Posicao==1)
	{
		NoPtr NovoNo=(NoPtr)malloc(sizeof(No));
		NovoNo->n=n;
		NovoNo->prox=Lista->Head;
		Lista->Head=NovoNo;
	}
	else{
		NoPtr Ant = Lista->Head; int i;
		for(i=1; i<Posicao-1 && Ant!=NULL; i++,Ant=Ant->prox); //Ant recebe o endereço do nó anterior a posição em que se deseja inserir
		if(i!=Posicao-1)
			return 0;
		NoPtr NovoNo=(NoPtr)malloc(sizeof(No));
		NovoNo->n=n;
		NovoNo->prox=Ant->prox;
		Ant->prox=NovoNo;
	}
	return 1;
	
}



void Imprime(TLista *Lista){
	NoPtr No = Lista->Head;
	while(No!=NULL){
		printf("%d ", No->n);
		No=No->prox;
	}
	printf("\n");
}



int main(){
	
	TLista *Lista=IniciaLista();
	int tam,n;
	scanf("%d", &tam);
	for(int i=0;i<tam;i++)
	{
		scanf("%d", &n);
		Insere(Lista,n);
	}
	InsereGeral(Lista,1,3);
	InsereGeral(Lista,42,6);
	InsereGeral(Lista,4,20);
	InsereGeral(Lista,89,1);
	Imprime(Lista);
	return 0;
}
