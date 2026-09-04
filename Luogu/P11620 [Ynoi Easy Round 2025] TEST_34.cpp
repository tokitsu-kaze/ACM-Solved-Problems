#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=5e4+10;
struct Base
{
	#define type int
	#define mx 30
	type d[mx+3];
	void init()
	{
		memset(d,0,sizeof(d));
	}
	bool insert(type x)
	{
		for(int i=mx;~i;i--)
		{
			if(!(x&(1LL<<i))) continue;
			if(!d[i])
			{
				d[i]=x;
				break;
			}
			x^=d[i];
		}
		return x>0;
	}
	type ask_max(type v=0) // ask max{res xor v}
	{
		type res=v;
		for(int i=mx;~i;i--)
		{
			if((res^d[i])>res) res^=d[i];
		}
		return res;
	}
	void merge(Base x)
	{
		for(int i=mx;~i;i--)
		{
			if(x.d[i]) insert(x.d[i]);
		}
	}
	#undef type
}bs;
struct Segment_Tree
{
	#define type int
	#define ls (id<<1)
	#define rs (id<<1|1)
	struct node
	{
		Base v;
		void init()
		{
			v.init();
		}
	}t[MAX<<2];
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	node merge(node x,node y)
	{
		node res;
		res=x;
		res.v.merge(y.v);
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
			t[id].v.insert(a[l]);
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
			t[id].v.init();
			a[l]^=qv;
			t[id].v.insert(a[l]);
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
		return merge(query(l,mid,ls),query(mid+1,r,rs));
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r,type v)
	{
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	Base ask(int l,int r)
	{
		ql=l;
		qr=r;
		return query(1,n,1).v;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
struct Fenwick_Tree
{
	#define type int
	type bit[MAX],tmp[MAX];
	const int LOG=log2(MAX)+1;
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) bit[i]=0;
	}
	int lowbit(int x){return x&(-x);}
	type get(int x)
	{
		type res=0;
		for(;x;x-=lowbit(x)) res^=bit[x];
		return res;
	}
	void upd(int x,type v)
	{
		for(;x<=n;x+=lowbit(x)) bit[x]^=v;
	}
	type ask(int l,int r)
	{
		if(l>r) return 0;
		if(l-1<=0) return get(r);
		return get(r)^get(l-1);
	}
	#undef type
}tra;
int main()
{
	int n,m,i,op,l,r,v;
	Base res;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&tr.a[i]);
	for(i=n-1;i;i--) tr.a[i+1]^=tr.a[i];
	tra.init(n);
	for(i=1;i<=n;i++) tra.upd(i,tr.a[i]);
	tr.build(n);
	while(m--)
	{
		scanf("%d%d%d%d",&op,&l,&r,&v);
		if(op==1)
		{
			tr.upd(l,l,v);
			tra.upd(l,v);
			if(r+1<=n)
			{
				tr.upd(r+1,r+1,v);
				tra.upd(r+1,v);
			}
		}
		else
		{
			res.init();
			res.insert(tra.ask(1,l));
			if(l+1<=r)
			{
				auto res2=tr.ask(l+1,r);
				res.merge(res2);
			}
			printf("%d\n",res.ask_max(v));
		}
	}
	return 0;
}
