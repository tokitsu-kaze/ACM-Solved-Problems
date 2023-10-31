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
#include <set>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=50000+10;
const int EDGE=20000+10;//±ßµÄÌõÊý
typedef long long ll;
int pre[511];
int ans;
struct node
{
	int x,y,v;
}a[500*500+10];
void init(int n)
{
	int i;
	for(i=0;i<n;i++)
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
bool cmp(node a,node b)
{
	return a.v<b.v;
}
void kruskal(int m)
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
	int t,n,m,i;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d%d",&n,&m);
			init(n);
			for(i=0;i<m;i++)
			{
				scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
			}
			ans=0;
			kruskal(m);
			printf("%d\n",ans);
		}
	}
	return 0;
}