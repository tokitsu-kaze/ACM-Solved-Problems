#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=5e5+10;
struct Segment_Tree
{
	#define type int
	#define ls (id<<1)
	#define rs (id<<1|1)
	struct node
	{
		type mxa,mnb,mxij,mxjk,mxijk;
		void init()
		{
			mxa=mxij=mxjk=mxijk=-INF;
			mnb=INF;
		}
	}t[MAX<<2];
	int n,ql,qr,qop;
	type a[MAX],b[MAX],tag[MAX<<2],qv;
	node merge(node x,node y)
	{
		node res;
		res.mxa=max(x.mxa,y.mxa);
		res.mnb=min(x.mnb,y.mnb);
		res.mxij=max({x.mxij,y.mxij,x.mxa-y.mnb});
		res.mxjk=max({x.mxjk,y.mxjk,-x.mnb+y.mxa});
		res.mxijk=max({x.mxijk,
					   y.mxijk,
					   x.mxa+y.mxjk,
					   x.mxij+y.mxa});
		return res;
	}
	void pushup(int id){t[id]=merge(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
		if(l==r)
		{
			t[id].mxa=a[l];
			t[id].mnb=b[l];
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
			if(qop==1) t[id].mxa=qv;
			else t[id].mnb=qv;
			return;
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
	void upd(int l,int r,type v,int op)
	{
		ql=l;
		qr=r;
		qv=v;
		qop=op;
		update(1,n,1);
	}
	type ask(int l,int r)
	{
		ql=l;
		qr=r;
		return query(1,n,1).mxijk;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
int main()
{
	int n,q,i,op,x,y;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%d",&tr.a[i]);
	for(i=1;i<=n;i++) scanf("%d",&tr.b[i]);
	tr.build(n);
	while(q--)
	{
		scanf("%d%d%d",&op,&x,&y);
		if(op<=2) tr.upd(x,x,y,op);
		else printf("%d\n",tr.ask(x,y));
	}
	return 0;
}
