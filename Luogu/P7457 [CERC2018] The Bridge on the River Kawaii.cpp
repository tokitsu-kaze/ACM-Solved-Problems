#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
struct Disjoint_Set_Union
{
	pair<int,int> st[MAX];
	int pre[MAX],top,sz[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
			sz[i]=1;
		}
		top=0;
	}
	int find(int x)
	{
		while(x!=pre[x]) x=pre[x];
		return x;
	}
	bool merge(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x==y)
		{
			st[top++]={-1,-1};
			return 0;
		}
		if(sz[x]>sz[y]) swap(x,y);
		pre[x]=y;
		sz[y]+=sz[x];
		st[top++]={x,y};
		return 1;
	}
	void roll_back()
	{
		pair<int,int> now=st[--top];
		if(now.first==-1) return;
		pre[now.first]=now.first;
		sz[now.second]-=sz[now.first];
	}
}dsu;
struct qst{int x,y,v,id;};
int ans[MAX];
struct Segment_Tree
{
	#define type qst
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qlimt;
	type qv;
	struct node
	{
		vector<type> v;
		void init(){v.clear();}
	}t[MAX<<2];
	void build(int l,int r,int id)
	{
		t[id].init();
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			t[id].v.push_back(qv);
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
	}
	void dfs(int l,int r,int id)
	{
		if(l>r) return;
		for(auto &it:t[id].v)
		{
			if(it.v>=0&&it.v<=qlimt) dsu.merge(it.x,it.y);
		}
		if(l==r)
		{
			for(auto &it:t[id].v)
			{
				if(it.v>=0) continue;
				if(ans[it.id]!=-1) continue;
				if(dsu.find(it.x)==dsu.find(it.y)) ans[it.id]=qlimt;
			}
			for(auto &it:t[id].v)
			{
				if(it.v>=0&&it.v<=qlimt) dsu.roll_back();
			}
			return;
		}
		int mid=(l+r)>>1;
		dfs(l,mid,ls);
		dfs(mid+1,r,rs);
		for(auto &it:t[id].v)
		{
			if(it.v>=0&&it.v<=qlimt) dsu.roll_back();
		}
	}
	void build(int _n)
	{
		n=_n;
		build(1,n,1);
	}
	void upd(int l,int r,type v)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	void ask(int limt)
	{
		qlimt=limt;
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
int main()
{
	int n,q,i,op,x,y,v,tot;
	scanf("%d%d",&n,&q);
	tr.build(q);
	map<pair<int,int>,pair<int,int>> lst;
	tot=0;
	for(i=1;i<=q;i++)
	{
		scanf("%d%d%d",&op,&x,&y);
		x++;
		y++;
		if(x>y) swap(x,y);
		if(op==0)
		{
			scanf("%d",&v);
			assert(!lst.count({x,y}));
			lst[{x,y}]={i,v};
		}
		else if(op==1)
		{
			assert(lst.count({x,y}));
			tr.upd(lst[{x,y}].first,i-1,{x,y,lst[{x,y}].second,0});
			lst.erase({x,y});
		}
		else tr.upd(i,i,{x,y,-1,++tot});
	}
	for(auto &it:lst)
	{
		tr.upd(it.second.first,q,
			{it.first.first,it.first.second,it.second.second,0});
	}
	for(i=1;i<=tot;i++) ans[i]=-1;
	for(i=0;i<=10;i++)
	{
		dsu.init(n);
		tr.ask(i);
	}
	for(i=1;i<=tot;i++) printf("%d\n",ans[i]);
	return 0;
}
