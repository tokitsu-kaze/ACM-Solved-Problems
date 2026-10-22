#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
struct Segment_Tree
{
	#define type ll
	static const int LOG=31; //range upd more *4
	static const type inf=LLINF;
	struct node
	{
		type v,mx;
		void init(){v=0;mx=-inf;}
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
		res.mx=max(x.mx,x.v+y.mx);
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls[id]],t[rs[id]]);}
	void pushdown(int l,int r,int id)
	{
		
	}
	void update(int l,int r,int &id)
	{
		if(!id) id=newnode();
		if(l>=ql&&r<=qr)
		{
			t[id].v=qv;
			t[id].mx=qv;
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
	int split(int l,int r,int &id)
	{
		int x;
		if(!id) return 0;
		if(l>=ql&&r<=qr)
		{
			x=id;
			id=0;
			return x;
		}
		pushdown(l,r,id);
		x=newnode();
		int mid=(l+r)>>1;
		if(ql<=mid) ls[x]=split(l,mid,ls[id]);
		if(qr>mid) rs[x]=split(mid+1,r,rs[id]);
		pushup(x);
		pushup(id);
		return x;
	}
	int merge(int l,int r,int x,int y)
	{
		if(!x||!y) return x+y;
		if(l==r)
		{
			//merge info x <- y
			delnode(y);
			return x;
		}
		pushdown(l,r,x);
		pushdown(l,r,y);
		int mid=(l+r)>>1;
		ls[x]=merge(l,mid,ls[x],ls[y]);
		rs[x]=merge(mid+1,r,rs[x],rs[y]);
		pushup(x);
		delnode(y);
		return x;
	}
	void split_segtree(int l,int r,int new_tree)
	{
		ql=l;
		qr=r;
		root[new_tree]=split(1,n,root[rt]);
	}
	void merge_segtree(int y)
	{
		root[rt]=merge(1,n,root[rt],root[y]);
		root[y]=0;
	}
	void upd(int l,int r,type v)
	{
		ql=l;
		qr=r;
		qv=v;
		update(1,n,root[rt]);
	}
	int ck(int l,int r)
	{
		ql=l;
		qr=r;
//		printf("%d %d %lld\n",l,r,query(1,n,root[rt]).mx);
		return query(1,n,root[rt]).mx>0;
	}
	int ask(int x)
	{
		int l,r,mid;
		l=x;
		r=n;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(x,mid)) r=mid;
			else l=mid+1;
		}
		if(ck(x,l)) return l;
		return n+1;
	}
	#undef type
}tr;
/*
tr.init(n);
tr.build();
tr.upd(l,r,v);
tr.ask(l,r);
Segment_Tree::node res=tr.merge_node(nodex,nodey);
---------
tr[x].build();
tr[x].merge_segtree(y);
tr[x].split_segtree(l,r,new_tree);
*/
int main()
{
	int n,q,i,j,op,l,r,x,rt1,rt2;
	scanf("%d%d",&n,&q);
	tr.init(n);
	for(j=0;j<3;j++)
	{
		tr[j].build();
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			tr[j].upd(i,i,x);
		}
	}
	rt1=3;
	rt2=4;
	while(q--)
	{
		scanf("%d",&op);
		if(op<=3)
		{
			scanf("%d%d",&l,&r);
			tr[op-1].split_segtree(l,r,rt1);
			tr[op%3].split_segtree(l,r,rt2);
			tr[op-1].merge_segtree(rt2);
			tr[op%3].merge_segtree(rt1);
		}
		else
		{
			scanf("%d",&x);
			printf("%d\n",tr[0].ask(x));
		}
	}
	return 0;
}
