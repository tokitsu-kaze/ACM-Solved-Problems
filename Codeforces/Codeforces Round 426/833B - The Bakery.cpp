#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=35000+10;
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
		type mx;
		void init(){mx=-inf;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.mx=max(x.mx,y.mx);
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		t[ls].mx+=tag[id];
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
			t[id].mx=a[l];
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
			tag[id]+=qv;
			t[id].mx+=qv;
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
int a[MAX],dp[MAX],lst[MAX];
int main()
{
	int n,k,i,j;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		dp[i]=-INF;
	}
	dp[0]=0;
	for(j=1;j<=k;j++)
	{
		for(i=1;i<=n;i++)
		{
			tr.a[i]=dp[i-1];
			lst[i]=0;
		}
		tr.build(n);
		for(i=1;i<=n;i++)
		{
			tr.upd(lst[a[i]]+1,i,1);
			dp[i]=tr.ask(1,i);
			lst[a[i]]=i;
		}
//		for(i=1;i<=n;i++) printf("%d%c",dp[i]," \n"[i==n]);
	}
	printf("%d\n",dp[n]);
	return 0;
}
/*
dp[j][i]=max{dp[j-1][k]+cnt{k+1..i}}
lst=k, now=i  k+1..i -> dp[j-1][k..i-1]
*/
