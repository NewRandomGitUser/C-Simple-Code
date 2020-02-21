#include <stdio.h>

int min(int *d, int n, int dB, int m)
{
	int pAtual = 0;
        int minParadas = 0;
        int j = 0;
        while(pAtual + m < dB)
	{        while(pAtual + m > d[j] &&
                      pAtual + m < dB &&
                      j < n) j++;//incrementa j até o posto mais longe possível

                if(pAtual<dB)
		{   
			minParadas++;
                        pAtual = d[j-1];
                }
        }
	return minParadas;
}

int main()
{	int dB, m, n;
	scanf("%d %d %d", &dB, &m, &n);

	int d[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &d[i]);
	int minParadas = min(d,n, dB, m);
	printf("%d", minParadas);
	return 0;
}
