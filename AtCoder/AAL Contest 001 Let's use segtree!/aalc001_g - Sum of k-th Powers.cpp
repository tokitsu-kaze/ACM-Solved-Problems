#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
ll c[5][5];
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	struct node
	{
		type v[5];
		void init(){}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		for(int i=0;i<=4;i++) res.v[i]=(x.v[i]+y.v[i])%mod;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void maintain(int l,int r,int id,type qv)
	{
		int i,j;
		ll res[5],y[5];
		y[0]=1;
		for(i=1;i<=4;i++) y[i]=y[i-1]*qv%mod;
		for(i=0;i<=4;i++)
		{
			res[i]=0;
			for(j=0;j<=i;j++) res[i]=(res[i]+c[i][j]*t[id].v[j]%mod*y[i-j])%mod;
		}
		for(i=0;i<=4;i++) t[id].v[i]=res[i];
		tag[id]=(tag[id]+qv)%mod;
	}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		maintain(l,mid,ls,tag[id]);
		maintain(mid+1,r,rs,tag[id]);
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
		if(l==r)
		{
			t[id].v[0]=1;
			for(int i=1;i<=4;i++) t[id].v[i]=t[id].v[i-1]*a[l]%mod;
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
			maintain(l,r,id,qv);
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
	type ask(int l,int r,int k)
	{
		ql=l;
		qr=r;
		return query(1,n,1).v[k];
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
	int n,q,i,j,op,l,r,x;
	c[0][0]=1;
	for(i=1;i<=4;i++)
	{
		c[i][0]=1;
		for(j=1;j<=4;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%lld",&tr.a[i]);
	tr.build(n);
	while(q--)
	{
		scanf("%d%d%d%d",&op,&l,&r,&x);
		if(op==1) tr.upd(l,r,x);
		else printf("%lld\n",tr.ask(l,r,x));
	}
	return 0;
}
