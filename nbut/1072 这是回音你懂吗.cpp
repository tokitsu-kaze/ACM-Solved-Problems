#include <stdio.h>
#include <string.h>
int main()
{
	int len,i,j;
	char a[10001];
	while(~scanf("%s",a))
	{
		len=strlen(a);
		for(i=0;i<len;i++)
		{
			if(a[i]<0)
			{
				for(j=i;j<len;j++)
				{
					printf("%c",a[j]);
				}
				printf("~\n");
				i++;
			}
			else
			{
				for(j=i;j<len;j++)
				{
					printf("%c",a[j]);
				}
				printf("~\n");
			}
		}
	}
	return 0;
}