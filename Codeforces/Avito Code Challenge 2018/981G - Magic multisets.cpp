#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const ll mod=998244353;
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tagadd[MAX<<2],tagmul[MAX<<2],qv;
	struct node
	{
		type v;
		void init(){}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.v=(x.v+y.v)%mod;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		int mid=(l+r)>>1;
		if(tagmul[id]!=1)
		{
			t[ls].v=t[ls].v*tagmul[id]%mod;
			t[rs].v=t[rs].v*tagmul[id]%mod;
			tagmul[ls]=tagmul[ls]*tagmul[id]%mod;
			tagmul[rs]=tagmul[rs]*tagmul[id]%mod;
			tagadd[ls]=tagadd[ls]*tagmul[id]%mod;
			tagadd[rs]=tagadd[rs]*tagmul[id]%mod;
			tagmul[id]=1;
		}
		if(tagadd[id]!=0)
		{
			t[ls].v=(t[ls].v+(mid-l+1)*tagadd[id])%mod;
			t[rs].v=(t[rs].v+(r-mid)*tagadd[id])%mod;
			tagadd[ls]=(tagadd[ls]+tagadd[id])%mod;
			tagadd[rs]=(tagadd[rs]+tagadd[id])%mod;
			tagadd[id]=0;
		}
	}
	void build(int l,int r,int id)
	{
		tagadd[id]=0;
		tagmul[id]=0;
		t[id].init();
		if(l==r)
		{
			t[id].v=0;
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
			if(qv==0)
			{
				t[id].v=(t[id].v+(r-l+1))%mod;
				tagadd[id]++;
			}
			else
			{
				t[id].v=t[id].v*2%mod;
				tagmul[id]=tagmul[id]*2%mod;
				tagadd[id]=tagadd[id]*2%mod;
			}
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
		if(l>r) return null_node.v;
		ql=l;
		qr=r;
		return query(1,n,1).v;
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
struct ODT
{
	#define type int
	#define init_val 0
	struct ODT_node
	{
		int l,r;
		mutable type v;
		inline bool operator<(const ODT_node &o)const {return l<o.l;}
	};
	int n;
	set<ODT_node> odt;
	typedef set<ODT_node>::iterator odt_iter;
	void init(int _n)
	{
		n=_n;
		odt.clear();
		odt.insert({1,n,init_val});
	}
	odt_iter find(int x){return --odt.upper_bound({x,0,init_val});}
	odt_iter split(int x)
	{
		if(x>n) return odt.end();
		odt_iter it=find(x);
		if(it->l==x) return it;
		int l=it->l,r=it->r;
		type v=it->v;
		odt.erase(it);
		odt.insert({l,x-1,v});
		return odt.insert({x,r,v}).first;
	}
	void assign(int l,int r,type v)
	{
		odt_iter itr=split(r+1),itl=split(l);
		odt_iter it;
		for(it=itl;it!=itr;it++) tr.upd((*it).l,(*it).r,(*it).v);
		odt.erase(itl,itr);
		odt.insert({l,r,v});
	}
	#undef init_val
	#undef type
}odt[MAX];
int main()
{
	int n,q,i,op,l,r,x;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) odt[i].init(n);
	tr.build(n);
	while(q--)
	{
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)
		{
			scanf("%d",&x);
			odt[x].assign(l,r,1);
		}
		else printf("%lld\n",tr.ask(l,r));
	}
	return 0;
}
