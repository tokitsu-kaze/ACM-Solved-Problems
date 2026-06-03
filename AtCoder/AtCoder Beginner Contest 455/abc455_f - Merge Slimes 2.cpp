#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
const int mod=998244353;
ll qpow(ll a,ll b)
{
	ll res=1;
	while(b>0)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll inv(ll x){return qpow(x,mod-2);}
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
		type sum,sq;
		void init(){sum=sq=0;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.sum=(x.sum+y.sum)%mod;
		res.sq=(x.sq+y.sq)%mod;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void maintain(int id,int l,int r,type v)
	{
		t[id].sq=(t[id].sq+2*v*t[id].sum+v*v%mod*(r-l+1))%mod;
		t[id].sum=(t[id].sum+(r-l+1)*v)%mod;
	}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		maintain(ls,l,mid,tag[id]);
		maintain(rs,mid+1,r,tag[id]);
		tag[ls]=(tag[ls]+tag[id])%mod;
		tag[rs]=(tag[rs]+tag[id])%mod;
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
		if(l==r)
		{
			t[id]={0,0};
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
			maintain(id,l,r,qv);
			tag[id]=(tag[id]+qv)%mod;
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
int main()
{
	int n,q,i,l,r,a;
	ll inv2;
	scanf("%d%d",&n,&q);
	tr.build(n);
	inv2=inv(2);
	while(q--)
	{
		scanf("%d%d%d",&l,&r,&a);
		a%=mod;
		tr.upd(l,r,a);
		auto res=tr.ask(l,r);
//		printf("%lld %lld\n",res.sum,res.sq);
		printf("%lld\n",(res.sum*res.sum%mod-res.sq+mod)*inv2%mod);
	}
	return 0;
}
/*
a*b+(a*c+b*c)+(a*d+b*d+c*d)+...
好像求的是两两乘积之和，合并顺序不重要。
*/
