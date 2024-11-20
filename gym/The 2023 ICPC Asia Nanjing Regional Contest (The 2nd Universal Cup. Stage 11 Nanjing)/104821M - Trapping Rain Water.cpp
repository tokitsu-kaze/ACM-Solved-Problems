#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	struct node
	{
		type mx,sum;
		void init(){mx=sum=0;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.mx=max(x.mx,y.mx);
		res.sum=x.sum+y.sum;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		t[ls].mx=t[rs].mx=tag[id];
		t[ls].sum=(mid-l+1)*tag[id];
		t[rs].sum=(r-mid)*tag[id];
		tag[ls]=tag[rs]=tag[id];
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
		if(l==r)
		{
			t[id].mx=t[id].sum=a[l];
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
			t[id].mx=qv;
			tag[id]=qv;
			t[id].sum=qv*(r-l+1);
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
		if(l>r) return null_node.sum;
		ql=l;
		qr=r;
		return query(1,n,1).sum;
	}
	int p;
	void dfs(int l,int r,int id)
	{
		if(l==r)
		{
			if(t[id].mx>qv) p=l-1;
			else p=l;
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(mid>=ql)
		{
			if(t[ls].mx>qv) dfs(l,mid,ls);
			else dfs(mid+1,r,rs);
		}
		else dfs(mid+1,r,rs);
	}
	int get_r(int pos,type v)
	{
		ql=pos+1;
		qr=n;
		qv=v;
		p=pos;
		dfs(1,n,1);
		return p;
	}
	#undef type
	#undef ls
	#undef rs
}f,g;
/*
tr.build(n);
tr.upd(l,r,v);
tr.ask(l,r);
Segment_Tree::node res=tr.merge_node(nodex,nodey);
*/
ll a[MAX];
int main()
{
	int T,n,i,q,x,v,r;
	ll sum,mx;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		sum=mx=0;
		f.a[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			sum+=a[i];
			f.a[i]=max(f.a[i-1],a[i]);
			mx=max(mx,a[i]);
		}
		reverse(a+1,a+1+n);
		g.a[0]=0;
		for(i=1;i<=n;i++) g.a[i]=max(g.a[i-1],a[i]);
		reverse(a+1,a+1+n);
		f.build(n);
		g.build(n);
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d",&x,&v);
			a[x]+=v;
			sum+=v;
			mx=max(mx,a[x]);
			if(f.ask(x,x)<a[x])
			{
				r=f.get_r(x,a[x]);
				f.upd(x,r,a[x]);
//				printf("%d %d\n",x,r);
			}
			if(g.ask(n-x+1,n-x+1)<a[x])
			{
				r=g.get_r(n-x+1,a[x]);
				g.upd(n-x+1,r,a[x]);
//				printf("%d %d\n",n-x+1,r);
			}
			printf("%lld\n",f.ask(1,n)+g.ask(1,n)-n*mx-sum);
		}
	}
	return 0;
}
