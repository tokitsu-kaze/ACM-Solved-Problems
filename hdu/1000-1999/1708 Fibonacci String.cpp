////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-28 16:35:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1708
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1424KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
struct fibo
{
	__int64 a[27];
}abc[55];
int main()
{
	int t,n,i,j;
	char c[31];
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			memset(abc,0,sizeof(abc));
			for(j=0;j<=1;j++)
			{
				getchar();
				scanf("%s",c);
				for(i=0;i<strlen(c);i++)
				{
					abc[j].a[c[i]-97]++;
				}
			}
			scanf("%d",&n);
			for(i=2;i<=n;i++)
			{
				for(j=0;j<27;j++)
				{
					abc[i].a[j]=abc[i-1].a[j]+abc[i-2].a[j];
				}
			}
			for(i=0;i<26;i++)
			{
				printf("%c:%I64d\n",i+97,abc[n].a[i]);
			}
			printf("\n");
		}
	}
	return 0;
}