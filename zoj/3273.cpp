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
struct node
{
	ll l,r,h;
	ll tag;
}seg[MAX*8];
struct tree
{
	ll l,r,cover,len;
	ll calmid()
	{
		return (l+r)>>1;
	}
}tree[MAX*4];
ll x[MAX*4],k;
void add(ll l,ll r,ll h1,ll h2)
{
	if(l==r) return;
	seg[k].l=l;
	seg[k].r=r;
	seg[k].h=h1;
	seg[k].tag=1;
	k++;
	seg[k].l=l;
	seg[k].r=r;
	seg[k].h=h2;
	seg[k].tag=-1;
	k++;
}
bool cmp(node a,node b)
{
	return a.h<b.h;
}
ll search2(ll l,ll r,ll key)
{
	ll mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(key==x[mid]) return mid;
		else if(key<x[mid]) r=mid-1;
		else l=mid+1;
	}
}
void callen(ll id)
{
	if(tree[id].cover) tree[id].len=x[tree[id].r+1]-x[tree[id].l];
	else if(tree[id].l==tree[id].r) tree[id].len=0;
	else tree[id].len=tree[id<<1].len+tree[id<<1|1].len;
}
void build(ll l,ll r,ll id)
{
	ll mid;
	tree[id].l=l;
	tree[id].r=r;
	tree[id].cover=0;
	tree[id].len=0;
	if(l==r) return;
	mid=tree[id].calmid();
	build(l,mid,id<<1);
	build(mid+1,r,id<<1|1);
}
void updata(ll l,ll r,ll id,ll v)
{
	ll mid;
	if(tree[id].l==l&&tree[id].r==r)
	{
		tree[id].cover+=v;
		callen(id);
		return;
	}
	mid=tree[id].calmid();
	if(r<=mid) updata(l,r,id<<1,v);
	else if(l>=mid+1) updata(l,r,id<<1|1,v);
	else
	{
		updata(l,mid,id<<1,v);
		updata(mid+1,r,id<<1|1,v);
	}
	callen(id);
}
int main()
{
	ll n,i,x1,y1,x2,y2,x3,y3,x4,y4,cnt,kx,ans,l,r;
	while(~scanf("%lld",&n)&&n)
	{
		k=cnt=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
			add(x1,x4,y1,y3);
			add(x4,x2,y1,y4);
			add(x1,x3,y3,y2);
			add(x3,x2,y4,y2);
        	x[cnt++]=x1;
        	x[cnt++]=x2;
        	x[cnt++]=x3;
        	x[cnt++]=x4;
		}
		sort(seg,seg+k,cmp);
		sort(x,x+cnt);
		kx=1;
		for(i=1;i<cnt;i++)
		{
			if(x[i]!=x[i-1]) x[kx++]=x[i];
		}
		build(0,kx-1,1);
		ans=0;
		for(i=0;i<k-1;i++)
		{
			l=search2(0,kx-1,seg[i].l);
			r=search2(0,kx-1,seg[i].r)-1;
			updata(l,r,1,seg[i].tag);
			ans+=(seg[i+1].h-seg[i].h)*tree[1].len;
		}
		printf("%lld\n",ans);
	}
	return 0;
}