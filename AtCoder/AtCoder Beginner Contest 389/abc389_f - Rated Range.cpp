#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e5+10;
const int mod=998244353;
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
		type mn,mx;
		void init(){mn=INF,mx=-INF;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.mn=min(x.mn,y.mn);
		res.mx=max(x.mx,y.mx);
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		t[ls].mn+=tag[id];
		t[ls].mx+=tag[id];
		t[rs].mn+=tag[id];
		t[rs].mx+=tag[id];
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
			t[id].mn=t[id].mx=l;
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
			t[id].mn+=qv;
			t[id].mx+=qv;
			tag[id]+=qv;
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	int get_pos_l(int l,int r,int id)
	{
		if(l==r) return l;
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(t[ls].mx<qv) return get_pos_l(mid+1,r,rs);
		else return get_pos_l(l,mid,ls);
	}
	int get_pos_r(int l,int r,int id)
	{
		if(l==r) return l;
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(t[rs].mn>qv) return get_pos_r(l,mid,ls);
		else return get_pos_r(mid+1,r,rs);
	}
	int ans[MAX];
	void dfs(int l,int r,int id)
	{
		if(l==r)
		{
			assert(t[id].mn==t[id].mx);
			ans[l]=t[id].mx;
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		dfs(l,mid,ls);
		dfs(mid+1,r,rs);
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
	int get_l(int x)
	{
		qv=x;
		return get_pos_l(1,n,1);
	}
	int get_r(int x)
	{
		qv=x;
		return get_pos_r(1,n,1);
	} 
	void ask()
	{
		dfs(1,n,1);
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
	int n,q,i,x,l,r,nl,nr;
	scanf("%d",&n);
	tr.build(5e5);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&l,&r);
		nl=tr.get_l(l);
		nr=tr.get_r(r);
//		printf("%d %d\n",nl,nr);
		tr.upd(nl,nr,1);
	}
	tr.ask();
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&x);
		printf("%d\n",tr.ans[x]);
	}
	return 0;
}
