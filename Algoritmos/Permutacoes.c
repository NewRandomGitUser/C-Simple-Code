#include <stdio.h>
#include <stdlib.h>

int Pertence(int *V, int n, int x)
{
  for(int i = 0; i < n; i++)
    if(x == V[i]) return 1;
  return 0;
}

void BackTrack(int *S, int *P, int n, int p)
{
  if(p==n)
  {  for(int i = 0;i<n;i++)
        printf("%d",P[i]);
     printf("\n");
     return;
  }
  for(int i = 0; i<n;i++)
  {
    if(Pertence(P,n,S[i]) == 0)
    {
      P[p] = S[i];
      BackTrack(S,P,n,p+1);
      P[p] = -1;
    }
  }
}


int main(){
  int n;
  int *S;
  int *P;

  scanf("%d", &n);
  S = (int*)malloc(n*sizeof(int));
  P = (int*)malloc(n*sizeof(int));

  for(int i = 0; i < n; i++)
  {
    scanf("%d", &S[i]);
    P[i] = -1;
  }
  BackTrack(S,P,n,0);
  return 0;
}
