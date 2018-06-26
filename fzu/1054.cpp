#include <stdio.h>
#include <string.h>
int main()
{
    int n,x,i;
    char a[201];
    while(~scanf("%d",&n))
    {
		getchar();
		while(n--)
		{
			gets(a);
			x=strlen(a);
			for(i=x-1;i>=0;i--)
			{
				printf("%c",a[i]);
			}
			printf("\n");
			memset(a,0,sizeof(a));
		}
    }
    return 0;
}