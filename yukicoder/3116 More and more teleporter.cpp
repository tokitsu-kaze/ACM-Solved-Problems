#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Segment_Tree
{
	#define type int
	static const type inf=2e9;
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	struct node
	{
		type pre,suf;
		void init(){pre=suf=inf;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.pre=min(x.pre,y.pre);
		res.suf=min(x.suf,y.suf);
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
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
			//init
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
			if(qop==1) t[id].pre=min(t[id].pre,qv);
			else t[id].suf=min(t[id].suf,qv);
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
	type ask(int l,int r,int op)
	{
		if(l>r) return inf;
		ql=l;
		qr=r;
		if(op==1) return query(1,n,1).pre;
		else return query(1,n,1).suf;
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
	int n,q,i,op,x,c;
	scanf("%d%d",&n,&q);
	tr.build(n);
	while(q--)
	{
		scanf("%d%d",&op,&x);
		if(op==1) printf("%d\n",min({x-1,
						tr.ask(1,x,1)+x,
						tr.ask(x,n,2)-x}));
		else
		{
			scanf("%d",&c);
			tr.upd(x,x,c-x,1);
			tr.upd(x,x,c+x,2);
		}
	}
	return 0;
}
/*
dp[x]=min{dp[j]+x-j} (j<x)
dp[x]=min{dp[j]-j}+x

dp[x]=min{dp[j]+j-x} (j>x)
dp[x]=min{dp[j]+j}-x
*/
