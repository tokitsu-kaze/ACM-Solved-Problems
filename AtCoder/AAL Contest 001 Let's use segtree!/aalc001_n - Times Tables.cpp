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
		res.v=(x.v+y.v)%mod;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void maintain(int l,int r,int id,type qv)
	{
		tag[id]+=qv;
		if(tag[id]>0) t[id].v=0;
		else
		{
			if(l==r) t[id].v=l;
			else pushup(id);
		}
	}
	void pushdown(int l,int r,int id)
	{
		
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
		if(l==r)
		{
			t[id].v=l;
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		if(tag[id]==0) pushup(id);
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
		if(tag[id]==0) pushup(id);
	}
	node query(int l,int r,int id)
	{
		if(tag[id]>0) return null_node;
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
struct Q{int x,y,op;};
vector<Q> qst[MAX];
int main()
{
	int n,q,i,a,b,c,d;
	ll ans;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) qst[i].clear();
	for(i=1;i<=q;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		qst[a].push_back({b,d,1});
		qst[c+1].push_back({b,d,-1});
	}
	tr.build(n);
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(auto &it:qst[i]) tr.upd(it.x,it.y,it.op);
		ans=(ans+i*tr.ask(1,n))%mod;
//		printf("%d %lld\n",i,ans);
	}
	printf("%lld\n",ans);
	return 0;
}
