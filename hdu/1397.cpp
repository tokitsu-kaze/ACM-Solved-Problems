////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-27 23:01:17
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1397
////Problem Title: 
////Run result: Accept
////Run time:358MS
////Run memory:1656KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <math.h>
int prime[65536];
int main()
{
	int n,i,j,flag,count;
	memset(prime,0,sizeof(prime));
	prime[2]=1;
	for(i=3;i<=65535;i++)
	{
		if(i%2) prime[i]=1;
	}
	for(i=3;i<=sqrt(65535);i++)
	{
		if(prime[i])
		{
			for(j=i+i;j<65535;j+=i)
			{
				prime[j]=0;
			}
		}
	}
	while(~scanf("%d",&n))
	{
		if(n==0) break;
		count=0;
		for(i=2;i<=n/2;i++)
		{
			if(prime[i]==1&&prime[n-i]==1) count++;
		}
		printf("%d\n",count);
	}
}