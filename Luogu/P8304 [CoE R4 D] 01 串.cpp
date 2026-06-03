#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
struct Segment_Tree
{
	#define type int
	static const type inf=INF;
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2];
	struct node
	{
		type sum,lmx,rmx,mx,cnt1;
		void init(){sum=0;lmx=rmx=mx=-inf;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.sum=x.sum+y.sum;
		res.lmx=max(x.lmx,x.sum+y.lmx);
		res.rmx=max(y.rmx,y.sum+x.rmx);
		res.mx=max({x.mx,y.mx,x.rmx+y.lmx});
		res.cnt1=x.cnt1+y.cnt1;
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
			if(a[l]==-1) t[id]={a[l],0,0,0,0};
			else t[id]={a[l],1,1,1,1};
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
			a[l]*=-1;
			if(a[l]==-1) t[id]={a[l],0,0,0,0};
			else t[id]={a[l],1,1,1,1};
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
	void upd(int l)
	{
		ql=qr=l;
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
char s[MAX];
int main()
{
	int n,q,i,l,r,ans;
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
	{
		if(s[i]=='1') tr.a[i]=1;
		else tr.a[i]=-1;
	}
	tr.build(n);
	while(q--)
	{
		scanf("%d%d",&l,&r);
		auto res=tr.ask(l,r);
		ans=2*res.cnt1-res.mx;
		if(ans==0) ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}

