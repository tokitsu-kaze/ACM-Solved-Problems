////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-19 18:27:12
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1398
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1404KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int main()
{
    int c1[301],c2[301],i,j,k,n;
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        for(i=0;i<=n;i++)
        {
			c1[i]=1;
			c2[i]=0;
		}
		for(i=2;i*i<=n;i++)
		{
			for(j=0;j<=n;j++)
			{
				for(k=0;k+j<=n;k+=i*i)
				{
					c2[k+j]+=c1[j];
				}
			}
			for(j=0;j<=n;j++)
			{
				c1[j]=c2[j];
				c2[j]=0;
			}
		}
		printf("%d\n",c1[n]);
    }
    return 0;
}