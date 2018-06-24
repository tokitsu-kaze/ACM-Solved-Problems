////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-24 21:41:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1284
////Problem Title: 
////Run result: Accept
////Run time:733MS
////Run memory:1644KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int n,i,j,k,c1[32770],c2[32770];
	memset(c1,0,sizeof(c1));
	memset(c2,0,sizeof(c2));
	for(i=0;i<=32767;i++)
	{
		c1[i]=1;
	}
	for(i=2;i<=3;i++)
	{
		for(j=0;j<=32767;j++)
		{
			for(k=0;k+j<=32767;k+=i)
			{
				c2[k+j]+=c1[j];
			}
		}
		for(j=0;j<=32767;j++)
		{
			c1[j]=c2[j];
			c2[j]=0;
		}
	}
	while(~scanf("%d",&n))
	{
		printf("%d\n",c1[n]);
	}
	return 0;
}