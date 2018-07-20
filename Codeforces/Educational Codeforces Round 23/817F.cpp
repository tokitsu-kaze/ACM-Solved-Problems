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
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=(int)1e5+10;
const ll mod=1e6;
struct node1
{
	ll op,l,r;
	void input()
	{
		scanf("%lld%lld%lld",&op,&l,&r);
	}
}a[MAX];
ll hash[8*MAX],cnt;
struct node
{
	ll l,r,mid,s,tag,rev;
	node(){}
	node(int a,int b)
	{
		l=a;
		r=b;
		mid=(l+r)>>1;
		s=0;
		tag=-1;
		rev=0;
	}
}tree[32*MAX];
ll getsum(ll l,ll r)
{
	return r-l+1;
} 
void build(ll l,ll r,ll id)
{
	ll mid;
	tree[id]=node(l,r);
	if(l==r) return;
	mid=tree[id].mid;
	build(l,mid,id<<1);
	build(mid+1,r,id<<1|1);
}
void pushdown(ll id)
{
	ll ls,rs;
	ls=id<<1;
	rs=id<<1|1;
	if(tree[id].tag!=-1)
	{
		tree[ls].tag=tree[rs].tag=tree[id].tag;
		tree[ls].s=tree[ls].tag*getsum(tree[ls].l,tree[ls].r);
		tree[rs].s=tree[rs].tag*getsum(tree[rs].l,tree[rs].r);
		tree[ls].rev=tree[rs].rev=0;
		tree[id].tag=-1;
	}
	if(tree[id].rev)
	{
		tree[ls].rev^=1;
		tree[rs].rev^=1;
		tree[ls].s=getsum(tree[ls].l,tree[ls].r)-tree[ls].s;
		tree[rs].s=getsum(tree[rs].l,tree[rs].r)-tree[rs].s;
		tree[id].rev=0;
	}
}
void update(ll l,ll r,ll id,ll v,ll flag)
{
	ll mid;
//	cout<<tree[id].l<<" "<<tree[id].r<<"...."<<endl;
	pushdown(id);
	if(tree[id].l==l&&tree[id].r==r)
	{
		if(flag)
		{
			tree[id].rev^=1;
			tree[id].s=getsum(tree[id].l,tree[id].r)-tree[id].s;
//			cout<<hash[tree[id].l]<<" "<<hash[tree[id].r]<<" "<<tree[id].s<<endl;
		}
		else
		{
			tree[id].s=v*getsum(tree[id].l,tree[id].r);
			tree[id].tag=v;
			tree[id].rev=0;
//			cout<<hash[tree[id].l]<<" "<<hash[tree[id].r]<<" "<<tree[id].s<<endl;
		}
		return;
	}
	
	mid=tree[id].mid;
	if(r<=mid) update(l,r,id<<1,v,flag);
	else if(l>=mid+1) update(l,r,id<<1|1,v,flag);
	else
	{
		update(l,mid,id<<1,v,flag);
		update(mid+1,r,id<<1|1,v,flag);
	}
	tree[id].s=tree[id<<1].s+tree[id<<1|1].s;
//	cout<<hash[tree[id].l]<<" "<<hash[tree[id].r]<<" "<<tree[id].s<<endl;
//	cout<<hash[tree[id<<1].l]<<" "<<hash[tree[id<<1].r]<<" "<<tree[id<<1].s<<endl;
//	cout<<hash[tree[id<<1|1].l]<<" "<<hash[tree[id<<1|1].r]<<" "<<tree[id<<1|1].s<<endl;
}
ll query(ll l,ll r,ll id)
{
	ll mid;
//	cout<<hash[tree[id].l]<<" "<<hash[tree[id].r]<<" "<<tree[id].s<<endl;
	if(tree[id].s==0) return tree[id].l;
	pushdown(id);
	mid=tree[id].mid;
//	cout<<hash[tree[id<<1].l]<<" "<<hash[tree[id<<1].r]<<" "<<tree[id<<1].s<<endl;
	if(tree[id<<1].s<getsum(tree[id].l,mid)) return query(l,mid,id<<1);
	else return query(mid+1,r,id<<1|1);
}
int main()
{
	ll n,l,r,i;
	while(~scanf("%lld",&n))
	{
		cnt=1;
		hash[cnt++]=1;
		hash[cnt++]=(ll)1e18+1;
		for(i=0;i<n;i++)
		{
			a[i].input();
			hash[cnt++]=a[i].l;
			hash[cnt++]=a[i].r;
	//		if(a[i].l>1) hash[cnt++]=a[i].l-1;
			hash[cnt++]=a[i].r+1;
		}
		sort(hash+1,hash+cnt);
		cnt=unique(hash+1,hash+cnt)-(hash+1);
	//	cout<<cnt<<endl;
		build(1,cnt,1);
		for(i=0;i<n;i++)
		{
			a[i].l=lower_bound(hash+1,hash+cnt,a[i].l)-hash;
			a[i].r=lower_bound(hash+1,hash+cnt,a[i].r)-hash;
//			cout<<a[i].l<<" "<<a[i].r<<"******"<<endl;
			if(a[i].op==1) update(a[i].l,a[i].r,1,1,0);
			else if(a[i].op==2) update(a[i].l,a[i].r,1,0,0);
			else if(a[i].op==3) update(a[i].l,a[i].r,1,1,1);
			printf("%lld\n",hash[query(1,cnt,1)]);
		}
	}
	return 0;
}
/*
10
2 9 59
2 8 72
3 19 41
1 1 62
1 50 74
1 53 66
2 59 69
3 66 77
2 62 63
3 57 69


*/