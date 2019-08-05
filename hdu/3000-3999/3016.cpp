////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-29 15:29:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3016
////Problem Title: 
////Run result: Accept
////Run time:358MS
////Run memory:8536KB
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
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=100000+10;
const ll mod=1e9+6;
struct tree
{
	int l,r,id,tag;
	int calmid()
	{
		return (l+r)>>1;
	}
}tree[4*MAX];
struct node
{
	int l,r;
	int h,x,y,v;
	void input()
	{
		scanf("%d%d%d%d",&h,&x,&y,&v);
	}
	friend bool operator<(node a,node b)
	{
		return a.h<b.h;
	}
}a[MAX];
void build(int l,int r,int id)
{
	int mid;
	tree[id].l=l;
	tree[id].r=r;
	tree[id].id=0;
	tree[id].tag=0;
	if(l==r) return;
	mid=tree[id].calmid();
	build(l,mid,id<<1);
	build(mid+1,r,id<<1|1);
}
void pushdown(int id)
{
	if(tree[id].tag)
	{
		tree[id<<1].id=tree[id<<1|1].id=tree[id].id;
		tree[id<<1].tag=tree[id<<1|1].tag=1;
		tree[id].tag=0;
	}
}
void update(int l,int r,int id,int v)
{
	int mid;
	if(tree[id].l==l&&tree[id].r==r)
	{
		tree[id].id=v;
		tree[id].tag=1;
		return;
	}
	pushdown(id);
	mid=tree[id].calmid();
	if(r<=mid) update(l,r,id<<1,v);
	else if(l>=mid+1) update(l,r,id<<1|1,v);
	else
	{
		update(l,mid,id<<1,v);
		update(mid+1,r,id<<1|1,v);
	}
}
int query(int p,int id)
{
	int mid;
	if(tree[id].l==tree[id].r) return tree[id].id;
	pushdown(id);
	mid=tree[id].calmid();
	if(p<=mid) query(p,id<<1);
	else query(p,id<<1|1);
}
int dp[MAX];
int main()
{
	int n,i;
	while(~scanf("%d",&n))
	{
		a[0].v=0;
		a[0].x=100010;
		a[0].y=1;
		a[0].h=0;
		for(i=1;i<=n;i++)
		{
			a[i].input();
			a[0].x=min(a[0].x,a[i].x);
			a[0].y=max(a[0].y,a[i].y);
		}
		build(a[0].x,a[0].y,1);
		sort(a,a+n+1);
		for(i=0;i<=n;i++)
		{
			a[i].l=query(a[i].x,1);
			a[i].r=query(a[i].y,1);
			update(a[i].x,a[i].y,1,i);
		}
		mem(dp,0);
		dp[n]=100+a[n].v;
		for(i=n;i>=1;i--)
		{
			int l,r;
			l=a[i].l;
			r=a[i].r;
			dp[l]=max(dp[l],dp[i]+a[l].v);
			dp[r]=max(dp[r],dp[i]+a[r].v);
		}
		if(dp[0]>0) printf("%d\n",dp[0]);
		else puts("-1");
	}
	return 0;
}