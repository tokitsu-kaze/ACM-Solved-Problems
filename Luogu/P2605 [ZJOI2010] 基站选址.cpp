#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e4+10;
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
		type mn;
		void init(){mn=LLINF;}
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
		t[ls].mn+=tag[id];
		t[rs].mn+=tag[id];
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
			t[id].mn+=qv;
			tag[id]+=qv;
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
	void build(int _n,type *_a)
	{
		n=_n;
		for(int i=1;i<=n;i++) a[i]=_a[i];
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
int d[MAX],c[MAX],s[MAX],l[MAX],r[MAX],w[MAX];
struct node{int l,w;};
vector<node> pos[MAX];
ll dp[MAX];
int main()
{
	int n,k,i,j;
	ll now0;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n+1;i++) pos[i].clear();
	d[1]=0;
	for(i=2;i<=n;i++) scanf("%d",&d[i]);
	for(i=1;i<=n;i++) scanf("%d",&c[i]);
	for(i=1;i<=n;i++) scanf("%d",&s[i]);
	for(i=1;i<=n;i++) scanf("%d",&w[i]);
	n++;
	d[n]=2e9+1;
	c[n]=s[n]=0;
	w[n]=INF;
	k++;
	for(i=1;i<=n;i++)
	{
		l[i]=lower_bound(d+1,d+1+n,d[i]-s[i])-d;
		r[i]=upper_bound(d+1,d+1+n,d[i]+s[i])-d-1;
		pos[r[i]].push_back({l[i],w[i]});
	}
	memset(dp,0x3f,sizeof dp);
	dp[0]=0;
	for(j=1;j<=k;j++)
	{
		tr.build(n,dp);
		now0=0;
		for(i=1;i<=n;i++)
		{
			dp[i]=min(tr.ask(1,i-1),now0)+c[i];
			for(auto &it:pos[i])
			{
				now0+=it.w;
				tr.upd(1,it.l-1,it.w);
			}
		}
	}
	printf("%lld\n",dp[n]);
	return 0;
}
/*
4 3
2 3 4
10 10 10 10
0 0 0 0
1 1 1 1
*/
