#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
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
		type mn;
		void init(){mn=inf;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.mn=min(x.mn,y.mn);
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		t[ls].mn=t[rs].mn=t[id].mn;
		tag[ls]=tag[rs]=1;
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
		if(l==r)
		{
			t[id].mn=a[l];
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
			t[id].mn=qv;
			tag[id]=1;
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
		if(l>r) return null_node.mn;
		ql=l;
		qr=r;
		return query(1,n,1).mn;
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
struct node{int x,y,len,id;}a[MAX];
int ans[MAX];
int main()
{
	int n,m,k,i,mn;
	scanf("%d%d%d",&n,&m,&k);
	for(i=0;i<k;i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].len);
		a[i].id=i;
	}
	sort(a,a+k,[](node x,node y){
		return x.x>y.x;
	});
	for(i=1;i<=m;i++) tr.a[i]=n+1;
	tr.build(m);
	for(i=0;i<k;i++)
	{
		mn=tr.ask(a[i].y,a[i].y+a[i].len-1);
		tr.upd(a[i].y,a[i].y+a[i].len-1,mn-1);
		ans[a[i].id]=mn-1;
	}
	for(i=0;i<k;i++) printf("%d\n",ans[i]);
	return 0;
}
