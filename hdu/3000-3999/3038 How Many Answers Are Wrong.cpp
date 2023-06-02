////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-07 21:35:27
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3038
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:2940KB
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
#define MAX 200000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int pre[MAX];
int sum[MAX];
int ans;
void init(int n)
{
	int i;
	for(i=0;i<=n;i++)
	{
		pre[i]=i;
	}
}
int find(int x)
{
	int temp;
	if(pre[x]!=x)
	{
		temp=pre[x];
		pre[x]=find(pre[x]);
		sum[x]+=sum[temp];
	}
	return pre[x];
}
void merge(int l,int r,int s)
{
	int la,ra;
	la=find(l);
	ra=find(r);
	if(la!=ra)
	{
		pre[la]=ra;
		sum[la]=sum[r]-sum[l]+s;
	}
	else
	{
		if(sum[l]-sum[r]!=s) ans++;
	}
}
int main()
{
	int n,m,l,r,s;
	while(~scanf("%d%d",&n,&m))
	{
		init(n);
		mem(sum,0);
		ans=0;
		while(m--)
		{
			scanf("%d%d%d",&l,&r,&s);
			l--;
			merge(l,r,s);
		}
		printf("%d\n",ans);
	}
	return 0;
}