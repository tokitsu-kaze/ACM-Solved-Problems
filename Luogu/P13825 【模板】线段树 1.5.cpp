#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct Segment_Tree
{
	#define type ull
	static const int LOG=31*4; //range upd more *4
	struct node
	{
		type v;
		void init(){v=0;}
	}t[MAX*LOG],null_node;
	int root[MAX],ls[MAX*LOG],rs[MAX*LOG],rt,tot,qop;
	int st[MAX*LOG],top;
	int ql,qr,n;
	type qv,tag[MAX*LOG];
	Segment_Tree &operator[](const int _rt){this->rt=_rt;return *this;}
	void init(int _n)
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
		tag[id]=0;
		return id;
	}
	node merge_node(node x,node y)
	{
		node res;
		res.v=x.v+y.v;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls[id]],t[rs[id]]);}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		if(!ls[id]) ls[id]=newnode();
		if(!rs[id]) rs[id]=newnode();
		int mid=(l+r)>>1;
		t[ls[id]].v+=(mid-l+1)*tag[id];
		t[rs[id]].v+=(r-mid)*tag[id];
		tag[ls[id]]+=tag[id];
		tag[rs[id]]+=tag[id];
		tag[id]=0;
	}
	void update(int l,int r,int &id)
	{
		if(!id) id=newnode();
		if(l>=ql&&r<=qr)
		{
			t[id].v+=(r-l+1)*qv;
			tag[id]+=qv;
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls[id]);
		if(qr>mid) update(mid+1,r,rs[id]);
		pushup(id);
	}
	node query(int l,int r,int id)
	{
		if(!id) return null_node;
		if(l>=ql&&r<=qr) return t[id];
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(qr<=mid) return query(l,mid,ls[id]);
		if(ql>mid) return query(mid+1,r,rs[id]);
		return merge_node(query(l,mid,ls[id]),query(mid+1,r,rs[id]));
	}
	void upd(int l,int r,type v)
	{
		ql=l;
		qr=r;
		qv=v;
		update(1,n,root[rt]);
	}
	type ask(int l,int r)
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
ull cal(int l,int r)
{
	return 1ULL*(l+r)*(r-l+1)/2;
}
int main()
{
	int n,q,i,op,l,r,x;
	scanf("%d%d",&n,&q);
	tr.init(n);
	tr.build();
	while(q--)
	{
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)
		{
			scanf("%d",&x);
			tr.upd(l,r,x);
		}
		else printf("%llu\n",tr.ask(l,r)+cal(l,r));
	}
	return 0;
}
