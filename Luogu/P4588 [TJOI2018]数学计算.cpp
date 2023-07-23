#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int mod;
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	type a[MAX],v[MAX<<2],tag[MAX<<2],qv;
	void pushup(int id)
	{
		v[id]=v[ls]*v[rs]%mod;
	}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		v[id]=1;
		if(l==r)
		{
			//init
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
			//do something
			v[id]=qv;
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	type res;
	void query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			//do something
			res=res*v[id]%mod;
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls);
		if(qr>mid) query(mid+1,r,rs);
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r,type v)
	{
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	type ask(int l,int r)//init res
	{
		ql=l;
		qr=r;
		res=1;
		query(1,n,1);
		return res;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
int main()
{
	int t,q,op,x,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&q,&mod);
		tr.build(q);
		for(i=1;i<=q;i++)
		{
			scanf("%d%d",&op,&x);
			if(op==1) tr.upd(i,i,x);
			else tr.upd(x,x,1);
			printf("%lld\n",tr.ask(1,q));
		}
	}
	return 0;
}
