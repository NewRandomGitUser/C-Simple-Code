#include <stdio.h>
#include <string.h>
int main()
{
	char str[500];
	char *pch;
	gets(str);
	pch = strtok(str," ,.");
	while(pch!=NULL)
	{
		printf("%s\n",pch);
		pch = strtok(NULL," ,.");
	}
	return 0;
}
