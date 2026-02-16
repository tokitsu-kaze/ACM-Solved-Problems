#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Segment_Tree
{
	#define type ll
	static const type inf=LLINF;
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],covtag[MAX<<2],revtag[MAX<<2],qv;
	struct node
	{
		type v,sz;
		void init(){}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.v=max(x.v,y.v);
		res.sz=x.sz+y.sz;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		int mid=(l+r)>>1;
		if(covtag[id])
		{
			t[ls].v=t[rs].v=0;
			tag[ls]=tag[rs]=0;
			covtag[ls]=covtag[rs]=1;
			covtag[id]=0;
		}
		if(revtag[id])
		{
			t[ls].sz=(mid-l+1)-t[ls].sz;
			t[rs].sz=(r-mid)-t[rs].sz;
			revtag[ls]^=1;
			revtag[rs]^=1;
			revtag[id]=0;
		}
		if(tag[id])
		{
			if(t[ls].sz)
			{
				t[ls].v+=tag[id];
				tag[ls]+=tag[id];
			}
			if(t[rs].sz)
			{
				t[rs].v+=tag[id];
				tag[rs]+=tag[id];
			}
			tag[id]=0;
		}
	}
	void build(int l,int r,int id)
	{
		tag[id]=covtag[id]=revtag[id]=0;
		t[id].init();
		if(l==r)
		{
			t[id]={0,1};
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
			if(t[id].sz)
			{
				t[id].v+=qv;
				tag[id]+=qv;
			}
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	void cov(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			t[id].v=0;
			t[id].sz=(r-l+1)-t[id].sz;
			tag[id]=0;
			covtag[id]=1;
			revtag[id]^=1;
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) cov(l,mid,ls);
		if(qr>mid) cov(mid+1,r,rs);
		pushup(id);
	}
	node query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr) return t[id];
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(qr<=mid) return query(l,mid,ls);
		if(ql>mid) return query(mid+1,r,rs);
		return merge_node(query(l,mid,ls),query(mid+1,r,rs));
	}
	void build(int _n)
	{
		n=_n;
		build(1,n,1);
		null_node.init();
	}
	void upd(int l,int r,type v)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	void cov(int l,int r)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		cov(1,n,1);
	}
	type ask(int l,int r)
	{
		if(l>r) return null_node.v;
		ql=l;
		qr=r;
		return query(1,n,1).v;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
/*
tr.build(n);
tr.upd(l,r,v);
tr.ask(l,r);
Segment_Tree::node res=tr.merge_node(nodex,nodey);
*/
int main()
{
	int n,q,op,l,r,x;
	scanf("%d%d",&n,&q);
	tr.build(n);
	while(q--)
	{
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)
		{
			scanf("%d",&x);
			tr.upd(l,r,x);
		}
		else if(op==2) tr.cov(l,r);
		else printf("%lld\n",tr.ask(l,r));
	}
	return 0;
}
