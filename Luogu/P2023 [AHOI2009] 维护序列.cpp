#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
ll p;
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],v[MAX<<2],tagadd[MAX<<2],tagmul[MAX<<2],qv;
	void pushup(int id)
	{
		v[id]=(v[ls]+v[rs])%p;
	}
	void pushdown(int l,int r,int id)
	{
		int mid=(l+r)>>1;
		if(tagmul[id]!=1)
		{
			v[ls]=v[ls]*tagmul[id]%p;
			v[rs]=v[rs]*tagmul[id]%p;
			tagmul[ls]=tagmul[ls]*tagmul[id]%p;
			tagmul[rs]=tagmul[rs]*tagmul[id]%p;
			tagadd[ls]=tagadd[ls]*tagmul[id]%p;
			tagadd[rs]=tagadd[rs]*tagmul[id]%p;
			tagmul[id]=1;
		}
		if(tagadd[id]!=0)
		{
			v[ls]=(v[ls]+(mid-l+1)*tagadd[id])%p;
			v[rs]=(v[rs]+(r-mid)*tagadd[id])%p;
			tagadd[ls]=(tagadd[ls]+tagadd[id])%p;
			tagadd[rs]=(tagadd[rs]+tagadd[id])%p;
			tagadd[id]=0;
		}
	}
	void build(int l,int r,int id)
	{
		tagmul[id]=1;
		tagadd[id]=0;
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
			if(qop==1)
			{
				v[id]=v[id]*qv%p;
				tagmul[id]=tagmul[id]*qv%p;
				tagadd[id]=tagadd[id]*qv%p;
			}
			else
			{
				v[id]=(v[id]+(r-l+1)*qv)%p;
				tagadd[id]=(tagadd[id]+qv)%p;
			}
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
			res=(res+v[id])%p;
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls);
		if(qr>mid) query(mid+1,r,rs);
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r,type v,int op)
	{
		ql=l;
		qr=r;
		qv=v;
		qop=op;
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
}tr;
int main()
{
	int n,q,i,op,l,r;
	ll k;
	scanf("%d%lld",&n,&p);
	for(i=1;i<=n;i++) scanf("%lld",&tr.a[i]);
	tr.build(n);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d",&op,&l,&r);
		if(op==1 || op==2)
		{
			scanf("%lld",&k);
			tr.upd(l,r,k,op);
		}
		else printf("%lld\n",tr.ask(l,r));
	}
	return 0;
}
