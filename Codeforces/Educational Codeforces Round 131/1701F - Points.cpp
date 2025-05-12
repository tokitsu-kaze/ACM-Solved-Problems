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
		type cnt,sum;
		void init(){cnt=sum=0;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.cnt=x.cnt+y.cnt;
		res.sum=x.sum+y.sum;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		int mid=(l+r)>>1;
		if(tag[id])
		{
			t[ls].sum+=tag[id]*t[ls].cnt;
			t[rs].sum+=tag[id]*t[rs].cnt;
			tag[ls]+=tag[id];
			tag[rs]+=tag[id];
			tag[id]=0;
		}
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
			if(qop==1) t[id].cnt+=qv;
			else
			{
				t[id].sum+=qv*t[id].cnt;
				tag[id]+=qv;
			}
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
		if(l>r) return 0;
		ql=l;
		qr=r;
		if(op==1) return query(1,n,1).cnt;
		else return query(1,n,1).sum;
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
int vis[MAX];
int main()
{
	int n,q,d,i,x;
	ll ans,cnt;
	scanf("%d%d",&q,&d);
	n=2e5;
	tr.build(n);
	memset(vis,0,sizeof vis);
	ans=0;
	while(q--)
	{
		scanf("%d",&x);
		if(vis[x])
		{
			// del
			cnt=tr.ask(x,x,2);
			ans-=cnt*(cnt-1)/2;
			ans-=tr.ask(max(1,x-d),x-1,2);
			ans+=tr.ask(max(1,x-d),x-1,1);
			tr.upd(x,x,-cnt,2);
			tr.upd(x,x,-1,1);
			tr.upd(max(1,x-d),x-1,-1,2);
			
		}
		else
		{
			// insert
			cnt=tr.ask(x+1,min(n,x+d),1);
			ans+=cnt*(cnt-1)/2;
			ans+=tr.ask(max(1,x-d),x-1,2);
			tr.upd(x,x,1,1);
			tr.upd(x,x,cnt,2);
			tr.upd(max(1,x-d),x-1,1,2);
		}
		vis[x]^=1;
		printf("%lld\n",ans);
	}
	return 0;
}
