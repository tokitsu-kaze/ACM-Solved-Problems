////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-19 18:03:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1028
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1408KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int main()
{
    int c1[122],c2[122],i,j,k,n;
    while(~scanf("%d",&n))
    {
        for(i=0;i<=n;i++)
        {
			c1[i]=1;
			c2[i]=0;
		}
		for(i=2;i<=n;i++)
		{
			for(j=0;j<=n;j++)
			{
				for(k=0;j+k<=n;k+=i)
				{
					c2[j+k]+=c1[j];
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