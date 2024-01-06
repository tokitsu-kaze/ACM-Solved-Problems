#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	struct node
	{
		int col,same;
		type w;
		void init()
		{
			col=-1;
		}
	}t[MAX<<2];
	int n,ql,qr,qop,coltag[MAX<<2];
	type a[MAX],tag[MAX<<2],qv;
	node merge(node x,node y)
	{
		node res;
		res.w=x.w+y.w;
		res.same=x.same&y.same&(x.col==y.col);
		if(x.col==y.col) res.col=x.col;
		else res.col=-1;
		return res;
	}
	void pushup(int id){t[id]=merge(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		
		int mid=(l+r)>>1;
		if(tag[id])
		{
			t[ls].w+=(mid-l+1)*tag[id];
			t[rs].w+=(r-mid)*tag[id];
			tag[ls]+=tag[id];
			tag[rs]+=tag[id];
			tag[id]=0;
		}
		if(coltag[id])
		{
			t[ls].col=t[rs].col=coltag[id];
			coltag[ls]=coltag[rs]=coltag[id];
			coltag[id]=0;
		}
	}
	void build(int l,int r,int id)
	{
		tag[id]=coltag[id]=0;
		t[id].init();
		if(l==r)
		{
			t[id].col=l;
			t[id].w=0;
			t[id].same=1;
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
			if(t[id].col!=-1)
			{
				t[id].w+=(r-l+1)*abs(t[id].col-qv);
				tag[id]+=abs(t[id].col-qv);
				t[id].col=qv;
				coltag[id]=qv;
				return;
			}
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	node query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr) return t[id];
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(qr<=mid) return query(l,mid,ls);
		if(ql>mid) return query(mid+1,r,rs);
		return merge(query(l,mid,ls),query(mid+1,r,rs));
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r,type v)
	{
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	type ask(int l,int r)
	{
		ql=l;
		qr=r;
		return query(1,n,1).w;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
int main()
{
	int n,m,i,op,l,r,x;
	scanf("%d%d",&n,&m);
	tr.build(n);
	while(m--)
	{
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)
		{
			scanf("%d",&x);
			tr.upd(l,r,x);
		}
		else printf("%lld\n",tr.ask(l,r));
	}
	return 0;
}
