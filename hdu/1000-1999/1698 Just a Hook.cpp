////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-12 18:25:04
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1698
////Problem Title: 
////Run result: Accept
////Run time:1014MS
////Run memory:6704KB
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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define eps 1e-9
#define MAX 100000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
struct tree
{
	int l,r,v;
	int lazy,tag;
}tree[4*MAX];
void pushup(int id)
{
	tree[id].v=tree[id*2].v+tree[id*2+1].v;
}
void pushdown(int id,int m)
{
	int t=tree[id].tag;
	if(tree[id].lazy)
	{
		tree[id].lazy=0;
		tree[id*2].lazy=1;
		tree[id*2+1].lazy=1;
		tree[id*2].tag=t;
		tree[id*2+1].tag=t;
		tree[id*2].v=(m-m/2)*t;
		tree[id*2+1].v=(m/2)*t;
	}
}
void build(int l,int r,int id)
{
	int mid;
	tree[id].l=l;
	tree[id].r=r;
	tree[id].v=1;
	tree[id].lazy=0;
	tree[id].tag=1;
	if(l==r) return;
	mid=(tree[id].l+tree[id].r)/2;
	build(l,mid,id*2);
	build(mid+1,r,id*2+1);
	pushup(id);
}
void update(int l,int r,int v,int id)
{
	int mid;
	if(tree[id].l==l&&tree[id].r==r)
	{
		tree[id].v=(r-l+1)*v;
		tree[id].lazy=1;
		tree[id].tag=v;
		return;
	}
	mid=(tree[id].l+tree[id].r)/2;
	pushdown(id,tree[id].r-tree[id].l+1);
	if(r<=mid)
	{
		update(l,r,v,id*2);
	}
	else if(l>=mid+1)
	{
		update(l,r,v,id*2+1);
	}
	else
	{
		update(l,mid,v,id*2);
		update(mid+1,r,v,id*2+1);
	}
	pushup(id);
}
int main()
{
	int t,n,k,a,b,c,cas;
	while(~scanf("%d",&t))
	{
		cas=1;
		while(t--)
		{
			scanf("%d",&n);
			build(1,n,1);
			scanf("%d",&k);
			while(k--)
			{
				scanf("%d%d%d",&a,&b,&c);
				update(a,b,c,1);
			}
			printf("Case %d: The total value of the hook is %d.\n",cas++,tree[1].v);
		}
	}
    return 0;
}