////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-28 17:34:53
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1799
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:16960KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int a[2001][2001];
int main ()  
{
    int i,j,m,n,t;
    for(i=0;i<2001;i++)
    {
		a[i][i]=1;
		a[i][0]=1;
	}
	for(i=2;i<2001;i++)
	{
		for(j=1;j<i;j++)
		{
			a[i][j]=(a[i-1][j]+a[i-1][j-1])%1007;
		}
	}
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d%d",&m,&n);
			printf("%d\n",a[n][m]);
		}
	}
    return 0;  
}