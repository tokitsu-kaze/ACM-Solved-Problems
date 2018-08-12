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
int pre[51],ans;
struct node
{
	int x,y,v;
}a[2511];
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
	return a.v<b.v;
}
int find(int x)
{
	if(pre[x]!=x) pre[x]=find(pre[x]);
	return pre[x];
}
void merge(node a)
{
	int ra,rb;
	ra=find(a.x);
	rb=find(a.y);
	if(ra!=rb)
	{
		pre[ra]=rb;
		ans+=a.v;
	}
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
	int n,m,i;
	while(~scanf("%d",&n)&&n)
	{
		init(n);
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
		}
		ans=0;
		kruskal(m);
		printf("%d\n",ans);
	}
	return 0;
}