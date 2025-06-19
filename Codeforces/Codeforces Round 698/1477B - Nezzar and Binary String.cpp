#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
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
		type v;
		void init(){}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.v=x.v+y.v;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(tag[id]==-1) return;
		int mid=(l+r)>>1;
		t[ls].v=tag[id]*(mid-l+1);
		t[rs].v=tag[id]*(r-mid);
		tag[ls]=tag[rs]=tag[id];
		tag[id]=-1;
	}
	void build(int l,int r,int id)
	{
		tag[id]=-1;
		t[id].init();
		if(l==r)
		{
			t[id].v=a[l];
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
			t[id].v=qv*(r-l+1);
			tag[id]=qv;
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
char s[MAX],f[MAX];
int l[MAX],r[MAX];
int main()
{
	int T,n,q,i,ok,sum;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		scanf("%s",s+1);
		scanf("%s",f+1);
		for(i=1;i<=q;i++) scanf("%d%d",&l[i],&r[i]);
		for(i=1;i<=n;i++) tr.a[i]=f[i]-'0';
		tr.build(n);
		ok=1;
		for(i=q;i;i--)
		{
			sum=tr.ask(l[i],r[i]);
			if(sum*2<r[i]-l[i]+1) tr.upd(l[i],r[i],0);
			else if(sum*2>r[i]-l[i]+1) tr.upd(l[i],r[i],1);
			else ok=0;
		}
		for(i=1;i<=n;i++)
		{
			if(tr.ask(i,i)!=s[i]-'0') ok=0;
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
