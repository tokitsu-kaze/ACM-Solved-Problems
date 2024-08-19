#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
struct Segment_Tree
{
	#define type int
	static const int LOG=18;
	struct node
	{
		type v;
		void init(){v=0;}
	}t[MAX*LOG],null_node;
	int root[MAX],ls[MAX*LOG],rs[MAX*LOG],rt,tot,qop;
	int st[MAX*LOG],top;
	type ql,qr,qv,n;
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
		
	}
	void update(type l,type r,int &id)
	{
		if(!id) id=newnode();
		if(l>=ql&&r<=qr)
		{
			t[id].v=qv;
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
	int split(type l,type r,int &id)
	{
		int x;
		if(!id) return 0;
		if(l>=ql&&r<=qr)
		{
			x=id;
			id=0;
			return x;
		}
		x=newnode();
		int mid=(l+r)>>1;
		if(ql<=mid) ls[x]=split(l,mid,ls[id]);
		if(qr>mid) rs[x]=split(mid+1,r,rs[id]);
		pushup(x);
		pushup(id);
		return x;
	}
	int merge(type l,type r,int x,int y)
	{
		if(!x||!y) return x+y;
		if(l==r)
		{
			t[x].v=t[y].v;
			delnode(y);
			return x;
		}
		type mid=(l+r)>>1;
		ls[x]=merge(l,mid,ls[x],ls[y]);
		rs[x]=merge(mid+1,r,rs[x],rs[y]);
		pushup(x);
		delnode(y);
		return x;
	}
	void split_segtree(type l,type r,int new_tree)
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
	void upd(type l,type r,type v)
	{
		ql=l;
		qr=r;
		qv=v;
		update(1,n,root[rt]);
	}
	void dfs(int l,int r,int id,char *res)
	{
		if(!id) return;
		if(t[id].v==0) return;
		if(l==r)
		{
			res[l]=rt+'a';
			return;
		}
		int mid=(l+r)>>1;
		dfs(l,mid,ls[id],res);
		dfs(mid+1,r,rs[id],res);
	}
	void work(char *res)
	{
		dfs(1,n,root[rt],res);
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
char s[MAX],res[MAX];
int main()
{
	int n,i,q,l,r,tmprt;
	char x[2],y[2];
	scanf("%s",s+1);
	n=strlen(s+1);
	tr.init(n);
	for(i=0;i<=26;i++) tr[i].build();
	tmprt=26;
	for(i=1;i<=n;i++) tr[s[i]-'a'].upd(i,i,1);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%s%s",&l,&r,x,y);
		if(x[0]==y[0]) continue;
		tr[x[0]-'a'].split_segtree(l,r,tmprt);
		tr[y[0]-'a'].merge_segtree(tmprt);
	}
	for(i=0;i<26;i++) tr[i].work(res);
	res[n+1]='\0';
	puts(res+1);
	return 0;
}
