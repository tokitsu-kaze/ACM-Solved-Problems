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
	type a[MAX],b[MAX],qv;
	struct node
	{
		type lmx05,rmx05,lmx15,rmx15,mx10,mx20,suma,mxmid;
		void init(){lmx05=rmx05=lmx15=rmx15=mx10=mx20=mxmid=-inf;suma=0;}
	}t[MAX<<2],null_node;
	void init_leaf(int id,int p)
	{
		t[id].suma=a[p];
		t[id].lmx05=t[id].rmx05=a[p]+b[p];
		t[id].mx10=a[p]+b[p]+b[p];
	}
	node merge_node(node x,node y)
	{
		node res;
		res.suma=x.suma+y.suma;
		res.mxmid=max({x.mxmid+y.suma,y.mxmid+x.suma,x.lmx05+y.rmx05});
		res.lmx05=max(x.lmx05,x.suma+y.lmx05);
		res.rmx05=max(y.rmx05,y.suma+x.rmx05);
		res.lmx15=max({x.lmx15,x.suma+y.lmx15,x.lmx05+y.mx10,x.mxmid+y.lmx05});
		res.rmx15=max({y.rmx15,y.suma+x.rmx15,y.rmx05+x.mx10,y.mxmid+x.rmx05});
		res.mx10=max({x.mx10,y.mx10,x.rmx05+y.lmx05});
		res.mx20=max({x.mx20,y.mx20,x.mx10+y.mx10,x.rmx15+y.lmx05,x.rmx05+y.lmx15});
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void build(int l,int r,int id)
	{
		t[id].init();
		if(l==r)
		{
			init_leaf(id,l);
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
			if(qop==1) a[l]=qv;
			else b[l]=qv;
			init_leaf(id,l);
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	node query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr) return t[id];
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
	void upd(int l,int r,type v,int op)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
		qop=op;
		update(1,n,1);
	}
	type ask(int l,int r)
	{
		if(l>r) return null_node.mx20;
		ql=l;
		qr=r;
		return query(1,n,1).mx20;
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
	int n,q,i,op,p,x,l,r;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld",&tr.a[i]);
	for(i=1;i<=n;i++) scanf("%lld",&tr.b[i]);
	tr.build(n);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&op);
		if(op==1||op==2)
		{
			scanf("%d%d",&p,&x);
			tr.upd(p,p,x,op);
		}
		else
		{
			scanf("%d%d",&l,&r);
			printf("%lld\n",tr.ask(l,r));
		}
	}
	return 0;
}

