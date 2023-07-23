#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qtag;
	type a[MAX],v[MAX<<2],tag[MAX<<2],tag2[MAX<<2],qv;
	void pushup(int id)
	{
		v[id]=max(v[ls],v[rs]);
	}
	void pushdown(int l,int r,int id)
	{
		int mid=(l+r)>>1;
		if(tag[id]!=-LLINF)
		{
			v[ls]=tag[id];
			v[rs]=tag[id];
			tag[ls]=tag[rs]=tag[id];
			tag[id]=-LLINF;
			tag2[ls]=tag2[rs]=0;
		}
		if(tag2[id])
		{
			v[ls]+=tag2[id];
			v[rs]+=tag2[id];
			tag2[ls]+=tag2[id];
			tag2[rs]+=tag2[id];
			tag2[id]=0;
		}
	}
	void build(int l,int r,int id)
	{
		tag[id]=-LLINF;
		tag2[id]=0;
		if(l==r)
		{
			//init
			v[id]=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			//do something
			if(qtag==1)
			{
				v[id]=qv;
				tag[id]=qv;
				tag2[id]=0;
			}
			else
			{
				v[id]+=qv;
				tag2[id]+=qv;
			}
			return;
		}
		pushdown(l,r,id);
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
			//do something
			res=max(res,v[id]);
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls);
		if(qr>mid) query(mid+1,r,rs);
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r,type v,int tag)
	{
		ql=l;
		qr=r;
		qv=v;
		qtag=tag;
		update(1,n,1);
	}
	type ask(int l,int r)//init res
	{
		ql=l;
		qr=r;
		res=-LLINF;
		query(1,n,1);
		return res;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
int main()
{
	int n,q,op,l,r,x,i;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%lld",&tr.a[i]);
	tr.build(n);
	while(q--)
	{
		scanf("%d%d%d",&op,&l,&r);
		if(op==1||op==2)
		{
			scanf("%d",&x);
			tr.upd(l,r,x,op);
		}
		else printf("%lld\n",tr.ask(l,r));
	}
	return 0;
}
