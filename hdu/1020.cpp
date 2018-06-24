////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-20 21:27:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1020
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1420KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int i,sum,n,len;
    char c[10001];
    while(~scanf("%d",&n))
    {
		getchar();
        while(n--)
        {
			gets(c);
			len=strlen(c);
			sum=1;
			for(i=0;i<len;i++)
			{
				while(c[i]==c[i+1])
				{
					sum++;
					i++;
				}
				if(sum>1)
				{
					printf("%d%c",sum,c[i]);
					sum=1;
				}
				else printf("%c",c[i]);
			}
			printf("\n");
		}
    }
    return 0;
}