////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-08 15:35:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1879
////Problem Title: 
////Run result: Accept
////Run time:468MS
////Run memory:1664KB
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
#define MAX 50000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int pre[111],ans;
struct node
{
	int x,y,v,d;
}s[11111];
void init(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		pre[i]=i;
	}
}
int cmp(node a,node b)
{
	if(a.d!=b.d) return a.d>b.d;
	return a.v<b.v;
}
int find(int x)
{
	if(pre[x]!=x) pre[x]=find(pre[x]);
	return pre[x];
}
void merge(node s)
{
	int rx,ry;
	rx=find(s.x);
	ry=find(s.y);
	if(rx!=ry)
	{
		pre[rx]=ry;
		if(!s.d) ans+=s.v;
	}
}
void kruskal(int m)
{
	int i;
	sort(s,s+m,cmp);
	for(i=0;i<m;i++)
	{
		merge(s[i]);
	}
}
int main()
{
	int n,m,i,d;
	while(~scanf("%d",&n)&&n)
	{
		init(n);
		m=n*(n-1)/2;
		ans=0;
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d%d",&s[i].x,&s[i].y,&s[i].v,&s[i].d);
		}
		kruskal(m);
		printf("%d\n",ans);
	}
	return 0;
}