#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	type a[MAX],v[MAX<<2],tag[MAX<<2],qv;
	void pushup(int id)
	{
		v[id]=v[ls]+v[rs];
	}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		v[ls]+=(mid-l+1)*tag[id];
		v[rs]+=(r-mid)*tag[id];
		tag[ls]+=tag[id];
		tag[rs]+=tag[id];
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		if(l==r)
		{
			v[id]=a[l];
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
			v[id]+=qv*(r-l+1);
			tag[id]+=qv;
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
			res+=v[id];
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
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	type ask(int l,int r)//init res
	{
		ql=l;
		qr=r;
		res=0;
		query(1,n,1);
		return res;
	}
	#undef type
	#undef ls
	#undef rs
}tr,tr2;
int main()
{
	int n,m,i,op,l,r,k,d;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&tr.a[i]);
		tr2.a[i]=0;
	}
	tr.build(n+1);
	tr2.build(n+1);
	while(m--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d%d%d",&l,&r,&k,&d);
			tr.upd(l,r,k);
			tr2.upd(l+1,r,d);
			tr2.upd(r+1,r+1,-1ll*(r-l)*d);
		}
		else
		{
			scanf("%d",&l);
			printf("%lld\n",tr.ask(l,l)+tr2.ask(1,l));
		}
	}
	return 0;
}

