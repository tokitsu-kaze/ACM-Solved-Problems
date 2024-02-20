#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
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
		type sum,lmx,rmx,mx;
		void init(){sum=0;lmx=rmx=mx=-inf;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.sum=x.sum+y.sum;
		res.lmx=max(x.lmx,x.sum+y.lmx);
		res.rmx=max(y.rmx,y.sum+x.rmx);
		res.mx=max({x.mx,y.mx,x.rmx+y.lmx});
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
			t[id]={a[l],a[l],a[l],a[l]};
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
			type s=t[id].sum+qv;
			t[id]={s,s,s,s};
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
		if(l>r) return null_node.mx;
		ql=l;
		qr=r;
		return query(1,n,1).mx;
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
	int n,m,k,d,i,x,y;
	scanf("%d%d%d%d",&n,&m,&k,&d);
	for(i=1;i<=n;i++) tr.a[i]=-k;
	tr.build(n);
	while(m--)
	{
		scanf("%d%d",&x,&y);
		tr.upd(x,x,y);
		if(tr.ask(1,n)<=1ll*d*k) puts("TAK");
		else puts("NIE");
	}
	return 0;
}
/*
sum{al..ar}<=(r+d-l+1)*k
sum{al..ar}<=(r-l+1)*k+d*k
sum{al-k...ar-k}<=d*k
*/
