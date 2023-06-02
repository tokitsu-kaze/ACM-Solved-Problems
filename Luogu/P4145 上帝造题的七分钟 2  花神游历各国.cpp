#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	type a[MAX],v[MAX<<2],mx[MAX<<2],qv;
	void pushup(int id)
	{
		v[id]=v[ls]+v[rs];
		mx[id]=max(mx[ls],mx[rs]);
	}
	void build(int l,int r,int id)
	{
		mx[id]=0;
		if(l==r)
		{
			v[id]=a[l];
			mx[id]=v[id];
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)
	{
		if(mx[id]==1) return;
		if(l==r)
		{
			v[id]=sqrt(v[id]);
			mx[id]=v[id];
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	type res;
	void query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			res+=v[id];
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls);
		if(qr>mid) query(mid+1,r,rs);
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r)
	{
		ql=l;
		qr=r;
		update(1,n,1);
	}
	type ask(int l,int r)//init res
	{
		ql=l;
		qr=r;
		res=0;
		query(1,n,1);
		return res;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
int main()
{
	int n,m,i,op,l,r;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld",&tr.a[i]);
	tr.build(n);
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%d%d",&op,&l,&r);
		if(l>r) swap(l,r);
		if(op==0) tr.upd(l,r);
		else printf("%lld\n",tr.ask(l,r));
	}
	return 0;
}
