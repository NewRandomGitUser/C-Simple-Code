#include <stdio.h>
#include <stdlib.h>
int max(int x, int y)
{
  return ( x >= y ? x : y);
}
int LCS(int*X, int n, int *Y, int m)
{
  if(n == 0 || m == 0)
     return 0;
  if(X[n] == Y[m])
     return LCS(X,n-1 ,Y,m-1) + 1;
  else
    return max(LCS(X,n,Y,m-1),LCS(X,n-1,Y,m));
}
int main()
{ int n,m;
  scanf("%d", &n);
  scanf("%d", &m);
  int *X = (int*)malloc(n*sizeof(int));
  int *Y = (int*)malloc(m*sizeof(int));
  for(int i = 0; i < n; i++)
     scanf("%d",&X[i]);
  for(int i = 0; i < m; i++)
     scanf("%d",&Y[i]);

  printf("%d", LCS(X,n,Y,m));

  return 0;
}
