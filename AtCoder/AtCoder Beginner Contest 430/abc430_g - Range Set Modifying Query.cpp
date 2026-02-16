#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
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
		type mx,cnt;
		void init(){mx=0;cnt=1;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		if(x.mx>y.mx) res=x;
		else if(x.mx<y.mx) res=y;
		else
		{
			res.mx=x.mx;
			res.cnt=x.cnt+y.cnt;
		}
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		tag[ls]+=tag[id];
		tag[rs]+=tag[id];
		t[ls].mx+=tag[id];
		t[rs].mx+=tag[id];
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
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
			t[id].mx+=qv;
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
		for(auto it=itl;it!=itr;it++)
		{
			tr.upd((*it).l,(*it).r,v-(*it).v);
//			printf("l,r: %d %d\n",(*it).l,(*it).r);
		}
		odt.erase(itl,itr);
		odt.insert({l,r,v});
	}
	#undef init_val
	#undef type
}odt[61];
int main()
{
	int n,q,i,op,l,r,x;
	scanf("%d%d",&n,&q);
	for(i=1;i<=60;i++) odt[i].init(n);
	tr.build(n);
	while(q--)
	{
		scanf("%d%d%d",&op,&l,&r);
		if(op==1||op==2) scanf("%d",&x);
		if(op==1) odt[x].assign(l,r,1);
		else if(op==2) odt[x].assign(l,r,0);
		else
		{
			auto res=tr.ask(l,r);
			printf("%d %d\n",res.mx,res.cnt);
		}
	}
	return 0;
}
