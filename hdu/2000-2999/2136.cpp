////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-30 22:12:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2136
////Problem Title: 
////Run result: Accept
////Run time:327MS
////Run memory:5488KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 1000000+5
using namespace std;
int prime[maxn];
int main()
{
	int n,i,j,s=0;
	for(i=2;i<maxn;i++)
	{
		if(prime[i]==0)
		{
			s++;
			for(j=i;j<maxn;j+=i)
			{
				prime[j]=s;
			}
		}
	}
	while (~scanf("%d",&n))
	{
		if(n==1) printf("0\n");
		else printf("%d\n",prime[n]);
	}
	return 0;
}