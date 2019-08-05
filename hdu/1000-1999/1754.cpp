////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-10 18:26:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1754
////Problem Title: 
////Run result: Accept
////Run time:1606MS
////Run memory:7736KB
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
struct tree
{
	int l,r,v;
}tree[4*MAX];
void build(int l,int r,int id)
{
	int mid;
	tree[id].l=l;
	tree[id].r=r;
	tree[id].v=0;
	if(l==r) return;
	mid=(tree[id].l+tree[id].r)/2;
	build(l,mid,id*2);
	build(mid+1,r,id*2+1);
}
void update(int l,int r,int v,int id)
{
	int mid;
	if(tree[id].l==l&&tree[id].r==r)
	{
		tree[id].v=v;
		return;
	}
	mid=(tree[id].l+tree[id].r)/2;
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
	tree[id].v=max(tree[id*2].v,tree[id*2+1].v);
}
int query(int l,int r,int id)
{
	if(tree[id].l>r||tree[id].r<l) return 0;
	if(tree[id].l>=l&&tree[id].r<=r)
	{
		return tree[id].v;
	}
	else
	{
		return max(query(l,r,id*2),query(l,r,id*2+1));
	}
}
int main()
{
	int n,m,i,v,a,b;
	char op;
	while(~scanf("%d%d",&n,&m))
	{
		build(1,n,1);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v);
			update(i,i,v,1);
		}
		while(m--)
		{
			getchar();
			scanf("%c %d %d",&op,&a,&b);
			if(op=='Q') printf("%d\n",query(a,b,1));
			else if(op=='U') update(a,a,b,1);
		}
	}
    return 0;
}