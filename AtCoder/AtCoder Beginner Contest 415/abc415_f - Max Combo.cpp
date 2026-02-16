#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
struct Segment_Tree
{
	#define type int
	static const type inf=INF;
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type tag[MAX<<2];
	char s[MAX],qv;
	struct node
	{
		char lc,rc;
		type len,lmx,rmx,ans;
		void init(){}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.lc=x.lc;
		res.rc=y.rc;
		res.len=x.len+y.len;
		if(x.lmx==x.len && x.lc==y.lc) res.lmx=x.len+y.lmx;
		else res.lmx=x.lmx;
		if(y.rmx==y.len && y.rc==x.rc) res.rmx=y.len+x.rmx;
		else res.rmx=y.rmx;
		res.ans=max(x.ans,y.ans);
		if(x.rc==y.lc) res.ans=max(res.ans,x.rmx+y.lmx);
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
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
			t[id]={s[l],s[l],1,1,1,1};
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
			t[id]={qv,qv,1,1,1,1};
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
	void upd(int l,int r,char v)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	type ask(int l,int r)
	{
		if(l>r) return 0;
		ql=l;
		qr=r;
		return query(1,n,1).ans;
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
	int n,q,op,l,r;
	char ch[2];
	scanf("%d%d",&n,&q);
	scanf("%s",tr.s+1);
	tr.build(n);
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%s",&l,ch);
			tr.upd(l,l,ch[0]);
		}
		else
		{
			scanf("%d%d",&l,&r);
			printf("%d\n",tr.ask(l,r));
		}
	}
	return 0;
}
