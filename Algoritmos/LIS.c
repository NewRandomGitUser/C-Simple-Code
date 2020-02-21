#include <stdio.h>
#include <stdlib.h>

int MenorNumero(int *D, int p, int x)
{  for(int i=0;i<p;i++)
     if(x >= D[i]) return 0;
  return 1;
}


int LIS(int*D, int n, int *T)
{
  T[0] = 1;
  for(int i=1;i<n;i++)
  {
    if(MenorNumero(D,i,D[i]))
      T[i] = 1;
    else
    {
      int max = 0;
      int aux;
      for(int j = 0; j < i; j++)
      {
       aux = T[j];
       if(aux >= max && D[i] > D[j])
        max = aux;
      }
      T[i] = max + 1;
    }
  }
  return T[n-1];
}


int main(){
  int n;
  int *D;
  int*T;

  scanf("%d", &n);
  D = (int*)malloc(n*sizeof(int));
  T = (int*)malloc(n*sizeof(int));
  for(int i=0;i<n;i++)
  {  scanf("%d",&D[i]);
     T[i] = 0;
  }
  int lis = LIS(D, n,T);
  printf("%d",lis);
  return 0;
}
