#include <stdio.h>
#include <string.h>
int main()
{
    char n[1000];
	int len,i;
    while(~scanf("%s",n))
    {
		len=strlen(n);
		if(n[0]=='-')
		{
			for(i=1;i<len;i++)
			{
				printf("%c",n[i]);
			}
			printf("\n");
		}
		else
		{
			for(i=0;i<len;i++)
			{
				printf("%c",n[i]);
			}
			printf("\n");
		}
    }
    return 0;
}