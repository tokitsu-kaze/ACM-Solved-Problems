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
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=100+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int pre[111],mp[111][111];
struct node
{
	int x,y,v;
}a[111*111];
void init(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		pre[i]=i;
	}
	mem(mp,0);
}
int cmp(node a,node b)
{
	if(a.v==b.v)
	{
		if(a.x==b.x) return a.y<b.y;
		return a.x<b.x;
	}
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
		mp[a.x][a.y]=1;
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
	int t,i,j,v,n,m,cnt,flag;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d",&n);
			m=0;
			init(n);
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					scanf("%d",&v);
					if(v==0) continue;
					a[m].v=v;
					a[m].x=i;
					a[m++].y=j;
				}
			}
			kruskal(m);
			cnt=0;
			for(i=1;i<=n;i++)
			{
				if(pre[i]==i) cnt++;
			}
			flag=0;
			if(cnt!=1) puts("-1");
			else
			{
				for(i=1;i<=n;i++)
				{
					for(j=1;j<=n;j++)
					{
						if(mp[i][j])
						{
							if(!flag)
							{
								printf("%d %d",i,j);
								flag=1;
							}
							else printf(" %d %d",i,j);
						}
					}
				}
				puts("");
			}
		}
	}
	return 0;
}