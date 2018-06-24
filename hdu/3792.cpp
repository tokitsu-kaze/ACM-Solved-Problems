////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-09 21:56:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3792
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:2736KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 100000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int c[MAX];
int lowbit(int x)
{
	return x&(-x);
}
int getsum(int k)
{
	int sum=0;
	while(k>0)
	{
		sum+=c[k];
		k-=lowbit(k);
	}
	return sum;
}
void update(int k,int v)
{
	while(k<=MAX)
	{
		c[k]+=v;
		k+=lowbit(k);
	}
}
int main()
{
    int i,j,k,flag[MAX],prime[MAX],n;
    mem(prime,0);
    mem(flag,0);
    k=0;
    for(i=2;i<MAX;i++)
    {
		if(!flag[i])
		{
			prime[k++]=i;
			for(j=i+i;j<MAX;j+=i)
			{
				flag[j]=1;
			}
		}
	}
	mem(c,0);
	for(i=1;i<k;i++)
	{
		if(prime[i]-prime[i-1]==2) update(prime[i],1);
	}
	while(~scanf("%d",&n)&&n>0)
	{
		if(!n)
		{
			puts("0");
			continue;
		}
		printf("%d\n",getsum(n));
	}
    return 0;
}