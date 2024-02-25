#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
struct Segment_Tree
{
	#define type int
	static const type inf=INF;
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	struct node
	{
		type v,lmx[2],rmx[2],mx;
		int len;
		void init(){lmx[0]=lmx[1]=rmx[0]=rmx[1]=mx=-inf;len=0;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.len=x.len+y.len;
		res.lmx[0]=x.lmx[0];
		if(x.lmx[0]==x.len) res.lmx[0]=max(res.lmx[0],x.len+y.lmx[x.len&1]);
		res.lmx[1]=x.lmx[1];
		if(x.lmx[1]==x.len) res.lmx[1]=max(res.lmx[1],x.len+y.lmx[(x.len&1)^1]);
		res.rmx[0]=y.rmx[0];
		if(y.rmx[0]==y.len) res.rmx[0]=max(res.rmx[0],y.len+x.rmx[y.len&1]);
		res.rmx[1]=y.rmx[1];
		if(y.rmx[1]==y.len) res.rmx[1]=max(res.rmx[1],y.len+x.rmx[(y.len&1)^1]);
		res.mx=max({x.mx,y.mx,x.rmx[0]+y.lmx[1],x.rmx[1]+y.lmx[0]});
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
			t[id].v=0;
			t[id].len=1;
			t[id].lmx[0]=t[id].rmx[0]=1;
			t[id].mx=1;
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
			t[id].v^=1;
			t[id].lmx[t[id].v]=t[id].rmx[t[id].v]=1;
			t[id].lmx[t[id].v^1]=t[id].rmx[t[id].v^1]=-inf;
			t[id].mx=1;
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
	void upd(int l,int r,type v)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	type ask(int l,int r)
	{
		if(l>r) return null_node.mx;
		ql=l;
		qr=r;
		return query(1,n,1).mx;
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
	int n,q,x;
	scanf("%d%d",&n,&q);
	tr.build(n);
	while(q--)
	{
		scanf("%d",&x);
		tr.upd(x,x,1);
		printf("%d\n",tr.ask(1,n));
	}
	return 0;
}
