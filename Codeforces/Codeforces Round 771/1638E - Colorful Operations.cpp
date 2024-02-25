#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=1e6+10;
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	struct node
	{
		type v;
		void init(){v=0;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		t[ls].v+=tag[id];
		t[rs].v+=tag[id];
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
			t[id].v=0;
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
	//	pushup(id);
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			tag[id]+=qv;
			t[id].v+=qv;
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
	//	pushup(id);
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
ll val[MAX];
struct ODT
{
	#define type ll
	struct ODT_node
	{
		int l,r,c;
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
		odt.insert({1,n,1,0});
	}
	odt_iter find(int x){return --odt.upper_bound({x,0,1,-LLINF});}
	odt_iter split(int x)
	{
		if(x>n) return odt.end();
		odt_iter it=find(x);
		if(it->l==x) return it;
		int l=it->l,r=it->r;
		int c=it->c;
		type v=it->v;
		odt.erase(it);
		odt.insert({l,x-1,c,v});
		return odt.insert({x,r,c,v}).first;
	}
	void assign(int l,int r,int c)
	{
		odt_iter itr=split(r+1),itl=split(l),it;
		for(it=itl;it!=itr;it++) tr.upd((*it).l,(*it).r,(*it).v+val[(*it).c]);
		odt.erase(itl,itr);
		odt.insert({l,r,c,-val[c]});
	}
	type ask(int pos)
	{
		odt_iter it=find(pos);
		return (*it).v+val[(*it).c]+tr.ask(pos,pos);
	}
	#undef type
}odt;
int main()
{
	int n,q,i,l,r,c,x;
	char op[11];
	scanf("%d%d",&n,&q);
	memset(val,0,sizeof val);
	odt.init(n);
	tr.build(n);
	while(q--)
	{
		scanf("%s",op);
		if(op[0]=='C')
		{
			scanf("%d%d%d",&l,&r,&c);
			odt.assign(l,r,c);
		}
		else if(op[0]=='A')
		{
			scanf("%d%d",&c,&x);
			val[c]+=x;
		}
		else
		{
			scanf("%d",&x);
			printf("%lld\n",odt.ask(x));
		}
	}
	return 0;
}
