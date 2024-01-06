#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	struct node
	{
		type mx,sum;
		void init()
		{
			mx=sum=0;
		}
	}t[MAX<<2];
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	node merge(node x,node y)
	{
		node res;
		res.sum=x.sum+y.sum;
		res.mx=max(x.mx,y.mx);
		return res;
	}
	void pushup(int id){t[id]=merge(t[ls],t[rs]);}
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
			t[id].sum=t[id].mx=a[l];
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
			if(qop==3)
			{
				t[id].mx=t[id].sum=qv;
				return;
			}
			else
			{
				if(t[id].mx<qv) return;
				if(l==r)
				{
					t[id].sum%=qv;
					t[id].mx=t[id].sum;
					return;
				}
			}
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
		return merge(query(l,mid,ls),query(mid+1,r,rs));
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
	type ask(int l,int r)
	{
		ql=l;
		qr=r;
		return query(1,n,1).sum;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
int main()
{
	int n,m,i,op,l,r,x;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%lld",&tr.a[i]);
	tr.build(n);
	while(m--)
	{
		scanf("%d%d%d",&op,&l,&r);
		if(op==1) printf("%lld\n",tr.ask(l,r));
		else if(op==2)
		{
			scanf("%d",&x);
			tr.upd(l,r,x,op);
		}
		else tr.upd(l,l,r,op);
	}
	return 0;
}
