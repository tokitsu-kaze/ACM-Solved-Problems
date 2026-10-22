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
		type mn,mnp;
		void init(){}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.mn=min(x.mn,y.mn);
		if(res.mn==x.mn) res.mnp=x.mnp;
		else res.mnp=y.mnp;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void maintain(int l,int r,int id,type qv)
	{
		
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
			t[id]={a[l],l};
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
			t[id]={a[l],l};
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
int st[MAX];
void workl(int *x,int n,int *l)
{
	int i,top;
	top=0;
	for(i=n;i;i--)
	{
		while(top && x[st[top-1]]<x[i]) l[st[--top]]=i;
		st[top++]=i;
	}
	while(top>0) l[st[--top]]=1;
}
int p[MAX],a[MAX],l[MAX],c[MAX];
int main()
{
	int n,i,pos;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&p[i]);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		tr.a[i]=a[p[i]];
		c[i]=0;
	}
	tr.build(n);
	workl(p,n,l);
	ans=0;
	for(i=2;i<=n;i++)
	{
		auto res=tr.ask(l[i],i-1);
		pos=res.mnp;
		ans+=res.mn;
		c[pos]++;
		tr.upd(pos,pos,2LL*a[p[pos]]*c[pos]+a[p[pos]]);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
确实是简单题，5分钟不到就会了。
先把代价贡献拆一下，拆成增量：ai*(ci+1)^2-ai*ci^2 -> 2aici+ai
考虑枚举每个点接在前面哪个点，那每次找增量小的接上去即可。
然后还要考虑字典序最小的限制。直觉上应该是弄一个单调栈，
发现只能接到左边比他大的第一个位置之后的区间，
然后线段树区间查询一下。
*/
