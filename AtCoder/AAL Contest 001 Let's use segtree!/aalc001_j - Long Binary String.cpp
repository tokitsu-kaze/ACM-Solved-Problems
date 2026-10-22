#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Segment_Tree
{
	#define type ll
	static const int LOG=61*4; //range upd more *4
	struct node
	{
		type v;
		void init(){v=0;}
	}t[MAX*LOG],null_node;
	int root[MAX],ls[MAX*LOG],rs[MAX*LOG],rt,tot,qop;
	int st[MAX*LOG],top;
	int revtag[MAX*LOG];
	type ql,qr,n;
	Segment_Tree &operator[](const int _rt){this->rt=_rt;return *this;}
	void init(type _n)
	{
		n=_n;
		rt=1;
		tot=top=0;
		t[0].init();
		ls[0]=rs[0]=0;
		null_node.init();
	}
	void build(){root[rt]=0;}
	void delnode(int id){st[top++]=id;}
	int newnode()
	{
		int id;
		id=top?st[--top]:++tot;
		t[id].init();
		ls[id]=rs[id]=0;
		revtag[id]=0;
		return id;
	}
	node merge_node(node x,node y)
	{
		node res;
		res.v=x.v+y.v;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls[id]],t[rs[id]]);}
	void pushdown(type l,type r,int id)
	{
		if(!revtag[id]) return;
		if(!ls[id]) ls[id]=newnode();
		if(!rs[id]) rs[id]=newnode();
		type mid=(l+r)>>1;
		t[ls[id]].v=(mid-l+1)-t[ls[id]].v;
		t[rs[id]].v=(r-mid)-t[rs[id]].v;
		revtag[ls[id]]^=revtag[id];
		revtag[rs[id]]^=revtag[id];
		revtag[id]=0;
	}
	void update(type l,type r,int &id)
	{
		if(!id) id=newnode();
		if(l>=ql&&r<=qr)
		{
			t[id].v=(r-l+1)-t[id].v;
			revtag[id]^=1;
			return;
		}
		pushdown(l,r,id);
		type mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls[id]);
		if(qr>mid) update(mid+1,r,rs[id]);
		pushup(id);
	}
	node query(type l,type r,int id)
	{
		if(!id) return null_node;
		if(l>=ql&&r<=qr) return t[id];
		pushdown(l,r,id);
		type mid=(l+r)>>1;
		if(qr<=mid) return query(l,mid,ls[id]);
		if(ql>mid) return query(mid+1,r,rs[id]);
		return merge_node(query(l,mid,ls[id]),query(mid+1,r,rs[id]));
	}
	void upd(type l,type r)
	{
		ql=l;
		qr=r;
		update(1,n,root[rt]);
	}
	type ask(type l,type r)
	{
		ql=l;
		qr=r;
		return query(1,n,root[rt]).v;
	}
	#undef type
}tr;
/*
tr.init(n);
tr.build();
tr.upd(l,r,v);
tr.ask(l,r);
Segment_Tree::node res=tr.merge_node(nodex,nodey);
*/
int main()
{
	int q,op;
	ll l,r;
	scanf("%d",&q);
	tr.init(1e18);
	tr.build();
	while(q--)
	{
		scanf("%d%lld%lld",&op,&l,&r);
		if(op==1) tr.upd(l,r);
		else printf("%lld\n",tr.ask(l,r));
	}
	return 0;
}
