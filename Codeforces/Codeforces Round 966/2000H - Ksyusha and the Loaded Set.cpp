#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=4e6+10;
struct Segment_Tree
{
	#define type int
	static const type inf=INF;
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type qv;
	struct node
	{
		type mn;
		void init(){mn=inf;}
	}t[MAX<<2],null_node;
	set<int> s[MAX];
	node merge_node(node x,node y)
	{
		node res;
		res.mn=min(x.mn,y.mn);
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		
	}
	void build(int l,int r,int id)
	{
		t[id].init();
		if(l==r)
		{
			s[l].clear();
			t[id].mn=inf;
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
			if(qv>0) s[l].insert(qv);
			else s[l].erase(-qv);
			if(s[l].size()>0) t[id].mn=*s[l].begin();
			else t[id].mn=inf;
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
	void upd(int x,type v)
	{
		if(x<1||x>n) return;
		ql=x;
		qr=x;
		qv=v;
		update(1,n,1);
	}
	type ask(int x)
	{
		ql=x;
		qr=n;
		return query(1,n,1).mn;
	}
	void dfs(int l,int r,int id)
	{
		if(t[id].mn==inf) return;
		if(l==r)
		{
			s[l].clear();
			t[id].mn=inf;
			return;
		}
		int mid=(l+r)>>1;
		dfs(l,mid,ls);
		dfs(mid+1,r,rs);
		pushup(id);
	}
	void clear()
	{
		dfs(1,n,1);
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
/*
tr.build(n);
tr.upd(l,r,v);
tr.ask(l,r);
Segment_Tree::node res=tr.merge_node(nodex,nodey);
*/
#define l first
#define r second
set<pair<int,int>> s;
void insert(int x)
{
	auto it=*(--s.upper_bound({x,INF}));
	s.erase(it);
	tr.upd(it.r-it.l+1,-it.l);
	if(it.l==x && it.r>=x+1)
	{
		tr.upd(it.r-it.l,it.l+1);
		s.insert({it.l+1,it.r});
	}
	else if(it.r==x && it.l<=x-1)
	{
		tr.upd(it.r-it.l,it.l);
		s.insert({it.l,it.r-1});
	}
	else if(it.l<x && it.r>x)
	{
		tr.upd(x-it.l,it.l);
		tr.upd(it.r-x,x+1);
		s.insert({it.l,x-1});
		s.insert({x+1,it.r});
	}
//	for(auto &it:s) printf("[%d,%d]\n",it.l,it.r);
}
void del(int x)
{
	auto pre=*(--s.upper_bound({x,INF}));
	auto nex=*s.upper_bound({x,INF});
	s.erase(pre);
	s.erase(nex);
	tr.upd(pre.r-pre.l+1,-pre.l);
	tr.upd(nex.r-nex.l+1,-nex.l);
	if(pre.r+2==nex.l && x==pre.r+1)
	{
		tr.upd(nex.r-pre.l+1,pre.l);
		s.insert({pre.l,nex.r});
	}
	else if(x==pre.r+1)
	{
		tr.upd(pre.r+1-pre.l+1,pre.l);
		tr.upd(nex.r-nex.l+1,nex.l);
		s.insert({pre.l,pre.r+1});
		s.insert(nex);
	}
	else if(x==nex.l-1)
	{
		tr.upd(nex.r-nex.l+2,nex.l-1);
		tr.upd(pre.r-pre.l+1,pre.l);
		s.insert({nex.l-1,nex.r});
		s.insert(pre);
	}
	else
	{
		tr.upd(pre.r-pre.l+1,pre.l);
		tr.upd(nex.r-nex.l+1,nex.l);
		tr.upd(1,x);
		s.insert(pre);
		s.insert(nex);
		s.insert({x,x});
	}
//	for(auto &it:s) printf("[%d,%d]\n",it.l,it.r);
}
#undef l
#undef r
int main()
{
	int t,n,m,x,i;
	char op[2];
	tr.build(MAX-10);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		s.clear();
		s.insert({1,4e6});
		s.insert({-INF,-INF});
		s.insert({INF,INF});
		tr.upd(4e6,1);
		while(n--)
		{
			scanf("%d",&x);
			insert(x);
		}
		scanf("%d",&m);
		vector<int> res;
		while(m--)
		{
			scanf("%s%d",op,&x);
			if(op[0]=='+') insert(x);
			else if(op[0]=='-') del(x);
			else res.push_back(tr.ask(x));
		}
		for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i+1==res.size()]);
		tr.clear();
	}
	return 0;
}
/*
1
4
3 4 6 11
1
? 3
*/
