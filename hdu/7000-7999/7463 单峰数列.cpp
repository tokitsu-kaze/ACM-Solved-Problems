#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	struct node
	{
		type v,lv,rv;
		int same,up,down,f,len;
		void init(){v=lv=rv=same=up=down=f=len=0;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.len=x.len+y.len;
		res.v=x.v+y.v;
		res.lv=x.lv;
		res.rv=y.rv;
		if(x.rv==y.lv) res.same=(x.same&y.same);
		else res.same=0;
		if(x.rv<y.lv) res.up=(x.up&y.up);
		else res.up=0;
		if(x.rv>y.lv) res.down=(x.down&y.down);
		else res.down=0;
		if(x.f&&y.down&&x.rv>y.lv) res.f=1;
		else if(y.f&&x.up&&x.rv<y.lv) res.f=1;
		else if(x.up&&y.down&&x.rv!=y.lv)
		{
			if(x.rv>y.lv&&x.len>1) res.f=1;
			else if(x.rv<y.lv&&y.len>1) res.f=1;
			else res.f=0;
		}
		else res.f=0;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		t[ls].lv+=tag[id];
		t[ls].rv+=tag[id];
		t[ls].v+=tag[id];
		tag[ls]+=tag[id];
		
		t[rs].lv+=tag[id];
		t[rs].rv+=tag[id];
		t[rs].v+=tag[id];
		tag[rs]+=tag[id];
		
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
		if(l==r)
		{
			t[id].lv=t[id].rv=t[id].v=a[l];
			t[id].up=t[id].down=t[id].same=1;
			t[id].f=0;
			t[id].len=1;
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
			t[id].lv+=qv;
			t[id].rv+=qv;
			t[id].v+=qv;
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
int main()
{
	int n,i,q,op,l,r,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld",&tr.a[i]);
	tr.build(n);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)
		{
			scanf("%d",&x);
			tr.upd(l,r,x);
		}
		else
		{
			auto res=tr.ask(l,r);
			if(op==2) printf("%d\n",res.same);
			else if(op==3) printf("%d\n",res.up);
			else if(op==4) printf("%d\n",res.down);
			else if(op==5) printf("%d\n",res.f);
		}
	}
	return 0;
}
