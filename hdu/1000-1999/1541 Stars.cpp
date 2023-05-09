////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-09 21:26:10
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1541
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:1820KB
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
#define MAX 32000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int a[MAX],c[MAX];
int lowbit(int x)
{
	return x&(-x);
}
int sum(int k)
{
	int ans=0;
	while(k)
	{
		ans+=c[k];
		k-=lowbit(k);
	}
	return ans;
}
void update(int k,int num)
{
	while(k<=MAX)
	{
		c[k]+=num;
		k+=lowbit(k);
	}
}
int main()
{
    int n,i,x,y;
    while(~scanf("%d",&n))
    {
		mem(a,0);
		mem(c,0);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			a[sum(x+1)]++;
			update(x+1,1);
		}
		for(i=0;i<n;i++)
		{
			printf("%d\n",a[i]);
		}
	}
    return 0;
}