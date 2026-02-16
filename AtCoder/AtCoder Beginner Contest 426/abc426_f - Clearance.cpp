#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
struct Segment_Tree
{
	#define type ll
	static const type inf=LLINF;
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv,res;
	struct node
	{
		type mn,mx,sz;
		void init(){mn=inf;sz=0;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.mn=min(x.mn,y.mn);
		res.sz=x.sz+y.sz;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		t[ls].mn-=tag[id];
		t[rs].mn-=tag[id];
		tag[ls]+=tag[id];
		tag[rs]+=tag[id];
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
		if(l==r)
		{
			t[id].mn=t[id].mx=a[l];
			t[id].sz=1;
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)
	{
		if(t[id].sz==0) return;
		if(l>=ql&&r<=qr)
		{
			if(t[id].mn>=qv)
			{
				res+=qv*t[id].sz;
				tag[id]+=qv;
				t[id].mn-=qv;
				return;
			}
		}
		if(l==r)
		{
			res+=t[id].mn;
			t[id].mn=inf;
			t[id].sz=0;
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	void build(int _n)
	{
		n=_n;
		build(1,n,1);
		null_node.init();
	}
	type upd(int l,int r,type v)
	{
		if(l>r) return 0;
		ql=l;
		qr=r;
		qv=v;
		res=0;
		update(1,n,1);
		return res;
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
	int n,i,q,l,r,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld",&tr.a[i]);
	tr.build(n);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d",&l,&r,&k);
		printf("%lld\n",tr.upd(l,r,k));
	}
	return 0;
}
