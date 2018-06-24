////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-09 15:09:11
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3371
////Problem Title: 
////Run result: Accept
////Run time:889MS
////Run memory:1832KB
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
#define MAX 3000000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int n,m,k,cnt,ans;
int pre[511];
struct node
{
	int x,y,v;
}a[25010];
int cmp(node a,node b)
{
	return a.v<b.v;
}
void init()
{
	int i;
	for(i=1;i<=n;i++)
	{
		pre[i]=i;
	}
}
int find(int x)
{
	if(pre[x]!=x) pre[x]=find(pre[x]);
	return pre[x];
}
void merge(node a)
{
	int rx,ry;
	rx=find(a.x);
	ry=find(a.y);
	if(rx!=ry)
	{
		pre[rx]=ry;
		ans+=a.v;
	}
}
void kruskal()
{
	int i;
	sort(a,a+m,cmp);
	for(i=0;i<m;i++)
	{
		merge(a[i]);
	}
}
int main()
{
    int t,p,i,b,c;
    while(~scanf("%d",&t))
    {
		while(t--)
		{
			scanf("%d%d%d",&n,&m,&k);
			init();
			for(i=0;i<m;i++)
			{
				scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
			}
			
			while(k--)
			{
				scanf("%d%d",&p,&b);
				p--;
				while(p--)
				{
					scanf("%d",&c);
					pre[find(b)]=find(c);
					b=c;
				}
			}
			cnt=ans=0;
			kruskal();
			for(i=1;i<=n;i++)
			{
				if(pre[i]==i) cnt++;
			}
			if(cnt!=1) puts("-1");
			else printf("%d\n",ans);
		}
	}
    return 0;
}