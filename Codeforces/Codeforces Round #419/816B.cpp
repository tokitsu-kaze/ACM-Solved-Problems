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
#include <ctime>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=200000+10;
const ll mod=10000;
struct tree
{
	int l,r,cnt,tag;
	int getmid()
	{
		return (l+r)>>1;
	}
}tree[4*MAX];
void build(int l,int r,int id)
{
	int mid;
	tree[id].l=l;
	tree[id].r=r;
	tree[id].cnt=0;
	tree[id].tag=0;
	if(l==r) return;
	mid=tree[id].getmid();
	build(l,mid,id<<1);
	build(mid+1,r,id<<1|1);
}
void pushdown(int id)
{
	
	tree[id<<1].tag+=tree[id].tag;
	tree[id<<1|1].tag+=tree[id].tag;
	tree[id<<1].cnt+=tree[id].tag;
	tree[id<<1|1].cnt+=tree[id].tag;
	tree[id].tag=0;
}
void update(int l,int r,int id)
{
	int mid;
	if(l<=tree[id].l&&r>=tree[id].r)
	{
		tree[id].tag++;
		tree[id].cnt++;
		return;
	}
	if(tree[id].tag) pushdown(id);
	mid=tree[id].getmid();
	if(r<=mid) update(l,r,id<<1);
	else if(l>mid) update(l,r,id<<1|1);
	else
	{
		update(l,mid,id<<1);
		update(mid+1,r,id<<1|1);
	}
}
int query(int l,int r,int id)
{
	int mid;
	if(tree[id].l==l&&tree[id].r==r) return tree[id].cnt;
	if(tree[id].tag) pushdown(id);
	mid=tree[id].getmid();
	if(r<=mid) return query(l,r,id<<1);
	else if(l>=mid+1) return query(l,r,id<<1|1);
}
int v[MAX];
int main()
{
	int n,m,a,b,i,k;
	while(~scanf("%d%d%d",&n,&k,&m))
	{
		build(1,200000,1);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			update(a,b,1);
		}
		mem(v,0);
		for(i=1;i<=MAX-10;i++)
		{
			v[i]=v[i-1]+(query(i,i,1)>=k?1:0);
		}
		while(m--)
		{
			scanf("%d%d",&a,&b);
			printf("%d\n",v[b]-v[a-1]);
		}
	}
	return 0;
}
/*
3 3 4
91 94
92 97
91 99
92 94
93 97
95 96
90 100

3 2 2
1 1
1 2
1 3
1 1
1 200000
*/