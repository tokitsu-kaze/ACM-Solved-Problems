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
		type mx,mn,sum;
		void init(){mn=inf;mx=-inf;sum=0;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.mx=max(x.mx,y.mx);
		res.mn=min(x.mn,y.mn);
		res.sum=x.sum+y.sum;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void maintain(int l,int r,int id,type v)
	{
		t[id].mn+=v;
		t[id].mx+=v;
		t[id].sum+=(r-l+1)*v;
		tag[id]+=v;
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
			t[id]={l,l,l};
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
		if(l>r) return null_node.sum;
		ql=l;
		qr=r;
		return query(1,n,1).sum;
	}
	int findl(int l,int r,int id)
	{
		if(l==r)
		{
			if(t[id].mx!=qv) return 1e9;
			return l;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(t[ls].mx<qv) return findl(mid+1,r,rs);
		return findl(l,mid,ls);
	}
	int findl(type v)
	{
		qv=v;
		return findl(1,n,1);
	}
	int findr(int l,int r,int id)
	{
		if(l==r)
		{
			if(t[id].mx!=qv) return -1e9;
			return l;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(t[rs].mn>qv) return findr(l,mid,ls);
		return findr(mid+1,r,rs);
	}
	int findr(type v)
	{
		qv=v;
		return findr(1,n,1);
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
int n,m,a[MAX];
ll work(int f)
{
	int i,l,r,qv;
	tr.build(n);
	for(i=1;i<=m+1;i++)
	{
		tr.upd(1,n,f);
		
		if(f==-1) qv=0;
		else qv=n+1;
		l=tr.findl(qv);
		r=tr.findr(qv);
		if(l<=r) tr.upd(l,r,-f);
		
		if(i==m+1) break;
		
		l=tr.findl(a[i]);
		r=tr.findr(a[i]);
		if(l<=r) tr.upd(l,r,-f);
	}
	return tr.ask(1,n);
}
int main()
{
	int i;
	ll ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) scanf("%d",&a[i]);
	if(n==1) return 0*puts("0");
	ans=n;
	ans-=work(-1); // l
	ans+=work(1); // r
	printf("%lld\n",ans);
	return 0;
}
/*
首先发现对于每个x，最终的y是一个区间。
考虑维护每个y的左右端点。
以左端点为例，每次左端点相当于全局减 1，减完看等于 ai 的值 需要加回去。
发现维护过程中，值也是单调的，等于 ai 的值肯定是个区间，线段树上二分找一下。
要注意的全局操作的时候，超出[1,n]范围的，要给他掰回来。
*/
