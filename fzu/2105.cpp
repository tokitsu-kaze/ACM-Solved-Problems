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
const int MAX=1000000+10;
const int EDGE=100000+10;//±ßµÄÌõÊı
typedef long long ll;
struct node
{
	int l,r,tag;
	int calmid()
	{
		return (l+r)/2;
	}
}tree[4*MAX];
int s[MAX];
void build(int l,int r,int id)
{
	int mid;
	tree[id].l=l;
	tree[id].r=r;
	tree[id].tag=-1;
	if(l==r)
	{
		tree[id].tag=s[l];
		return;
	}
	mid=tree[id].calmid();
	build(l,mid,id*2);
	build(mid+1,r,id*2+1);
	if(tree[id*2].tag==tree[id*2+1].tag&&tree[id].tag==-1) tree[id].tag=tree[id*2].tag;
}
void update(int l,int r,int id,int v,int flag)
{
	int mid;
	if(tree[id].l>=l&&tree[id].r<=r)
	{
		if(tree[id].tag!=-1)
		{
			if(flag==1) tree[id].tag&=v;
			else if(flag==2) tree[id].tag^=v;
			else if(flag==3) tree[id].tag|=v;
			return;
		}
	}
	if(tree[id].tag!=-1)
	{
		tree[id*2].tag=tree[id].tag;
		tree[id*2+1].tag=tree[id].tag;
		tree[id].tag=-1;
	}
	mid=tree[id].calmid();
	if(r<=mid) update(l,r,id*2,v,flag);
	else if(l>=mid+1) update(l,r,id*2+1,v,flag);
	else
	{
		update(l,mid,id*2,v,flag);
		update(mid+1,r,id*2+1,v,flag);
	}
	if(tree[id*2].tag==tree[id*2+1].tag&&tree[id*2].tag!=-1) tree[id].tag=tree[id*2].tag;
}
int query(int l,int r,int id)
{
	int mid;
	if(tree[id].l==l&&tree[id].r==r)
	{
		if(tree[id].tag!=-1) return tree[id].tag*(r-l+1);
	}
	if(tree[id].tag!=-1)
	{
		tree[id*2].tag=tree[id].tag;
		tree[id*2+1].tag=tree[id].tag;
		tree[id].tag=-1;
	}
	mid=tree[id].calmid();
	if(r<=mid) return query(l,r,id*2);
	else if(l>=mid+1) return query(l,r,id*2+1);
	return query(l,mid,id*2)+query(mid+1,r,id*2+1);
	if(tree[id*2].tag==tree[id*2+1].tag&&tree[id*2].tag!=-1) tree[id].tag=tree[id*2].tag;
}
int main()
{
	int t,n,m,i,a,b,c,d;
	char op[11];
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d%d",&n,&m);
			mem(s,0);
			for(i=1;i<=n;i++)
			{
				scanf("%d",&s[i]);
			}
			build(1,n,1);
			while(m--)
			{
				getchar();
				scanf("%s",op);
				if(op[0]=='S')
				{
					scanf("%d%d",&a,&b);
					printf("%d\n",query(a+1,b+1,1));
				}
				else 
				{
					if(op[0]=='A') d=1;
					else if(op[0]=='X') d=2;
					else if(op[0]=='O') d=3;
					scanf("%d%d%d",&c,&a,&b);
					update(a+1,b+1,1,c,d);
				}
			}
		}
	}
	return 0;
}