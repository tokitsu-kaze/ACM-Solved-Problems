#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
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
		if(now==pair<int,int>(-1,-1)) return;
		pre[now.first]=now.first;
		sz[now.second]-=sz[now.first];
	}
}dsu;
struct qst{int x,y;};
int n;
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
	int tag[MAX];
	void dfs(int l,int r,int id,int f)
	{
		if(l>r) return;
		for(auto &it:t[id].v)
		{
			dsu.merge(it.x,it.y+n);
			dsu.merge(it.x+n,it.y);
		}
		for(auto &it:t[id].v)
		{
			if(dsu.find(it.x)==dsu.find(it.x+n)) f=0;
			if(dsu.find(it.y)==dsu.find(it.y+n)) f=0;
		}
		if(l==r)
		{
			tag[l]=f;
			for(auto &it:t[id].v)
			{
				dsu.roll_back();
				dsu.roll_back();
			}
			return;
		}
		int mid=(l+r)>>1;
		dfs(l,mid,ls,f);
		dfs(mid+1,r,rs,f);
		for(auto &it:t[id].v)
		{
			dsu.roll_back();
			dsu.roll_back();
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
	void ask()
	{
		dfs(1,n,1,1);
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
	int m,k,i,a,b,l,r;
	scanf("%d%d%d",&n,&m,&k);
	tr.build(k);
	while(m--)
	{
		scanf("%d%d%d%d",&a,&b,&l,&r);
		l++;
		if(l<=r) tr.upd(l,r,{a,b});
	}
	dsu.init(2*n);
	tr.ask();
	for(i=1;i<=k;i++)
	{
		if(tr.tag[i]) puts("Yes");
		else puts("No");
	}
	return 0;
}
