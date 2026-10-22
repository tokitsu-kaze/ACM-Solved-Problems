#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct Segment_Tree
{
	#define type ll
	static const type inf=LLINF;
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	struct node
	{
		type v;
		void init(){v=inf;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.v=min(x.v,y.v);
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void maintain(int l,int r,int id,type qv)
	{
		t[id].v=min(t[id].v,qv);
		tag[id]=min(tag[id],qv);
	}
	void pushdown(int l,int r,int id)
	{
		if(tag[id]!=inf)
		{
			int mid=(l+r)>>1;
			maintain(l,mid,ls,tag[id]);
			maintain(mid+1,r,rs,tag[id]);
			tag[id]=inf;
		}
	}
	void build(int l,int r,int id)
	{
		tag[id]=inf;
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
ll dp[MAX];
struct node{int r,v;};
vector<node> qst[MAX];
int main()
{
	int n,s,t,i,l,r,v;
	scanf("%d%d%d",&n,&s,&t);
	s++;
	t++;
	for(i=s;i<=t;i++) qst[i].clear();
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&l,&r,&v);
		l++;
		r++;
		qst[l].push_back({r,v});
	}
	tr.build(t);
	dp[s-1]=0;
	for(i=s;i<=t;i++)
	{
		for(auto &it:qst[i]) tr.upd(i,it.r,dp[i-1]+it.v);
		dp[i]=tr.ask(i,i);
	}
	if(dp[t]==tr.inf) dp[t]=-1;
	printf("%lld\n",dp[t]);
	return 0;
}

