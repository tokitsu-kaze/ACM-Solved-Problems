#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	struct node
	{
		type v;
		void init(){v=0;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.v=x.v+y.v;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void maintain(int l,int r,int id,type qv)
	{
		t[id].v+=qv*(r-l+1);
		tag[id]+=qv;
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
			t[id].v=0;
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
struct Q{int x,y,id,sgn;};
vector<Q> qst[MAX];
ll ans[MAX];
int l[MAX],r[MAX];
int main()
{
	int n,m,q,i,a,b,c,d;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		qst[i].clear();
	}
	for(i=1;i<=q;i++)
	{
		ans[i]=0;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		qst[a-1].push_back({c,d,i,-1});
		qst[b].push_back({c,d,i,1});
	}
	tr.build(m);
	for(i=1;i<=n;i++)
	{
		tr.upd(l[i],r[i],1);
		for(auto &it:qst[i]) ans[it.id]+=it.sgn*tr.ask(it.x,it.y);
	}
	for(i=1;i<=q;i++) printf("%lld\n",ans[i]);
	return 0;
}
