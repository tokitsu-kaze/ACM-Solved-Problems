////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-20 20:40:19
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2189
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1392KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
    int t,n,m,c1[1001],c2[1001],prime[151],i,j,k,h,flag;
    prime[1]=2;
    for(i=3,h=1;i<=150;i++)
    {
		flag=0;
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0) prime[++h]=i;
	}
	memset(c1,0,sizeof(c1));
	memset(c2,0,sizeof(c2));
	for(i=0;i<=150;i+=2)
	{
		c1[i]=1;
	}
	for(i=2;i<=h;i++)
	{
		for(j=0;j<=150;j++)
		{
			for(k=0;k+j<=150;k+=prime[i])
			{
				c2[k+j]+=c1[j];
			}
		}
		for(j=0;j<=150;j++)
		{
			c1[j]=c2[j];
			c2[j]=0;
		}
	}
    while(~scanf("%d",&t))
    {
        while(t--)
        {
			scanf("%d",&n);
			printf("%d\n",c1[n]);
		}
    }
    return 0;
}