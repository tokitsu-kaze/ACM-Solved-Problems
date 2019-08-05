////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-01 16:32:03
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1096
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1452KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,m,i,j,a,b[10000];
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&m);
			for(j=0;j<m;j++)
			{
				scanf("%d",&a);
				b[i]=b[i]+a;
			}
		}
		for(i=0;i<n;i++)
		{
			printf("%d\n",b[i]);
			if(i!=n-1) printf("\n");
		}
	}
	return 0;
}