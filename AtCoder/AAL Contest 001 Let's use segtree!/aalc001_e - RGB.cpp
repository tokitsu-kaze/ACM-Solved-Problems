#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
struct Segment_Tree
{
	#define type ll
	static const type inf=INF;
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	char s[MAX];
	struct node
	{
		type sx,sy,sz,sxy,syz,sxyz;
		void init(){}
	}t[MAX<<2],null_node;
	node merge_node(node l,node r)
	{
		node res;
		res.sx=(l.sx+r.sx)%mod;
		res.sy=(l.sy+r.sy)%mod;
		res.sz=(l.sz+r.sz)%mod;
		res.sxy=(l.sxy+r.sxy+l.sx*r.sy)%mod;
		res.syz=(l.syz+r.syz+l.sy*r.sz)%mod;
		res.sxyz=(l.sxyz+r.sxyz+l.sx*r.syz+l.sxy*r.sz)%mod;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
		if(l==r)
		{
			if(s[l]=='R') t[id]={a[l],0,0,0,0,0};
			else if(s[l]=='G') t[id]={0,a[l],0,0,0,0};
			else t[id]={0,0,a[l],0,0,0};
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
			a[l]=qv;
			if(s[l]=='R') t[id]={a[l],0,0,0,0,0};
			else if(s[l]=='G') t[id]={0,a[l],0,0,0,0};
			else t[id]={0,0,a[l],0,0,0};
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
		ql=l;
		qr=r;
		return query(1,n,1).sxyz;
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
	int n,q,i,op,x,y;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%lld",&tr.a[i]);
	scanf("%s",tr.s+1);
	tr.build(n);
	while(q--)
	{
		scanf("%d%d%d",&op,&x,&y);
		if(op==1) tr.upd(x,x,y);
		else printf("%d\n",tr.ask(x,y));
	}
	return 0;
}
