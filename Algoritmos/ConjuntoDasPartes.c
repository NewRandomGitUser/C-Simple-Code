#include <stdio.h>
#include <stdlib.h>

void BackTrack(int *S, int *PS, int n, int i)
{
  if(i == n)
  {  for(int j = 0;j<n;j++)
     {    if(PS[j]==1)
             printf("%d ",S[j]);
     }
     printf("\n");
     return;
  }

  PS[i] = 1;
  BackTrack(S,PS,n,i+1);
  PS[i] = 0;
  BackTrack(S,PS,n,i+1);

}


int main(){
  int n;
  int *S;
  int *PS;
  scanf("%d",&n);

  S = (int*)malloc(n*sizeof(int));
  PS = (int*)malloc(n*sizeof(int));

  for(int i = 0; i < n; i++)
    PS[i] = -1;

  for(int i = 0; i < n; i++)
    scanf("%d",&S[i]);

  BackTrack(S,PS,n,0);

  return 0;
}
