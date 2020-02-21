#include <stdio.h>
#include <stdlib.h>

typedef struct TNoArvore NoArvore;
typedef NoArvore* NoArvorePtr;

struct TNoArvore{
	int n;
	NoArvorePtr Esq;
	NoArvorePtr Dir;
};


typedef struct{
	NoArvorePtr Raiz;
}TArvore;


TArvore* IniciaArvore()
{
	TArvore* Arvore = (TArvore*)malloc(sizeof(TArvore));
	Arvore->Raiz = NULL;
	return Arvore;
}


NoArvorePtr CriaNo(int n)
{
	NoArvorePtr NovoNo = (NoArvorePtr)malloc(sizeof(NoArvore));
	NovoNo->n = n;
	NovoNo->Esq = NULL;
	NovoNo->Dir = NULL;
	return NovoNo;
}


int InsereNoArvore(TArvore* Arvore, int n)
{
	if(Arvore==NULL)
		return 0;
	
	if(Arvore->Raiz==NULL)
	{
		Arvore->Raiz = CriaNo(n);
		return 1;
	}
	
	NoArvorePtr Temp = Arvore->Raiz;
	
	while(Temp->Dir!=NULL || Temp->Esq!=NULL)
	{
		if(n > Temp->n)
			Temp = Temp->Dir;
		else
			Temp = Temp->Esq;	
	}

	if(n > Temp->n)
		Temp->Dir = CriaNo(n);
	else
		Temp->Esq = CriaNo(n);
	
	return 1;
}

int RemoveNoArvore;
void PrintaArvore(NoArvorePtr No)
{
	if(No->Dir==NULL && No->Esq==NULL)
		return;
	
	PrintaArvore(No->Esq);
	printf("%d\n",No->n);
	PrintaArvore(No->Dir);
	printf("%d\n",No->n);
}

int main()
{
	TArvore* Arvore = IniciaArvore();
	int n;
	for(int i=0;i<5;i++)
	{
		scanf("%d", &n);
		InsereNoArvore(Arvore, n);
	}
	PrintaArvore(Arvore->Raiz);
	return 0;
}
