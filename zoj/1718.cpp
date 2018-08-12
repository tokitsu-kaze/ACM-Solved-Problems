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
int pre[111];
double ans;
struct node
{
	int x,y;
	double v;
}a[11111];
bool cmp(node a,node b)
{
	return a.v<b.v;
}
void init(int n)
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
	int ra,rb;
	ra=find(a.x);
	rb=find(a.y);
	if(ra!=rb)
	{
		pre[ra]=rb;
		ans+=a.v;
	}
}
void kruskal(int k)
{
	int i;
	sort(a,a+k,cmp);
	for(i=0;i<k;i++)
	{
		merge(a[i]);
	}
}
int main()
{
	int n,i,j,k;
	double x[11111],y[11111],z[11111],r[11111],dis;
	while(~scanf("%d",&n)&&n)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lf%lf%lf%lf",&x[i],&y[i],&z[i],&r[i]);
		}
		k=0;
		for(i=1;i<n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				dis=sqrt((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i])+(z[j]-z[i])*(z[j]-z[i]))-r[i]-r[j];
				if(dis<0) dis=0;
				a[k].x=i;
				a[k].y=j;
				a[k++].v=dis;
			}
		}
		ans=0;
		init(n);
		kruskal(k);
		printf("%.3lf\n",ans);
	}
	return 0;
}