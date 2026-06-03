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
	type a[MAX],tag[MAX<<2],qv;
	struct node
	{
		type l,r,lr,sum,len;
		void init(){}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.len=x.len+y.len;
		
		res.l=x.l+y.sum;
		if(x.len>=3) res.l=min(res.l,x.lr+y.sum);
		if(x.len>=2 && y.len>=2) res.l=min(res.l,x.l+y.l);
		
		res.r=x.sum+y.r;
		if(x.len>=2 && y.len>=2) res.r=min(res.r,x.r+y.r);
		if(y.len>=3) res.r=min(res.r,x.sum+y.lr);
		
		if(res.len<=2) res.lr=inf;
		else
		{
			res.lr=x.l+y.r;
			if(x.len>=3) res.lr=min(res.lr,x.lr+y.r);
			if(y.len>=3) res.lr=min(res.lr,x.l+y.lr);
		}
		
		res.sum=x.sum+y.sum;
		if(x.len>=2) res.sum=min(res.sum,x.r+y.sum);
		if(y.len>=2) res.sum=min(res.sum,x.sum+y.l);
		
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
			t[id]={0,0,inf,a[l],1};
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
	node ask(int l,int r)
	{
		if(l>r) return null_node;
		ql=l;
		qr=r;
		return query(1,n,1);
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
int n;
ll cal(int k)
{
	int i;
	ll res=LLINF;
	for(i=1;i<=n-k+1;i++) res=min(res,tr.ask(i,i+k-1).sum);
	return res;
}
int main()
{
	int T,k,i,j;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) scanf("%lld",&tr.a[i]);
		tr.build(n);
/*		for(i=1;i<=n;i++)
		{
			for(j=i;j<=n;j++)
			{
				printf("%d %d %lld\n",i,j,tr.ask(i,j).sum);
			}
		}*/
		ans=LLINF;
		for(i=0;i<=5;i++) ans=min(ans,cal(k+i));
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1
5 5
1 1 4 1 1
*/
