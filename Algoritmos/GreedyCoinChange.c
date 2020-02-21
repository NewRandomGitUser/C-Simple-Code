#include <stdio.h>
#include <stdlib.h>

int* Carrega(int n)
{
   int *v = (int *)malloc(n*sizeof(int));
   for(int i = 0; i < n; i++)
      scanf("%d", &v[i]); //Insere os outros valores no conjunto
    return v;
}

int GreedyMinCoin(int ValAtual,
                  int *D,
                  int NMoedasDiferentes,
                  int Count,
                  int i)
{
  if(ValAtual == 0)
    return Count;
  while(ValAtual - D[i] >=0)
  { 
    ValAtual = ValAtual - D[i];
    Count++;
  }
  i++;
  return GreedyMinCoin(ValAtual,D,NMoedasDiferentes,Count,i);
}

int main(){
   int NMoedasDiferentes; //Numero de diferentes moedas disponíveis
   int Valor; //Quantidade total fornecida na compra
   int *D;
   scanf("%d", &NMoedasDiferentes);
   D = Carrega(NMoedasDiferentes); //Constroi conjunto D
   scanf("%d", &Valor);
   int min = GreedyMinCoin(Valor,D,NMoedasDiferentes,0,0);
   printf("%d", min);
   return 0;
}
