#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=3e5+10;
struct leftist_tree
{
	#define type ll
	struct node
	{
		int ls,rs,d,id,cnt;
		type v;
		void init(){ls=rs=d=id=cnt=v=0;}
	}t[MAX];
	int root[MAX],rt,tot,sz[MAX];
	type tagadd[MAX],tagmul[MAX],tagcnt[MAX];
	leftist_tree &operator[](const int _rt){this->rt=_rt;return *this;}
	void init(int n=1)
	{
		rt=1;
		tot=0;
		t[0].init();
		sz[0]=0;
		for(int i=0;i<=n;i++) root[i]=0;
	}
	int newnode(type v,int p)
	{
		int id=++tot;
		t[id].init();
		t[id].id=p;
		t[id].v=v;
		sz[id]=1;
		tagadd[id]=tagcnt[id]=0;
		tagmul[id]=1;
		return id;
	}
	void pushdown(int id)
	{
		int ls=t[id].ls;
		int rs=t[id].rs;
		if(tagmul[id]!=1)
		{
			if(ls)
			{
				t[ls].v*=tagmul[id];
				tagmul[ls]*=tagmul[id];
				tagadd[ls]*=tagmul[id];
			}
			if(rs)
			{
				t[rs].v*=tagmul[id];
				tagmul[rs]*=tagmul[id];
				tagadd[rs]*=tagmul[id];
			}
			tagmul[id]=1;
		}
		if(tagadd[id])
		{
			if(ls)
			{
				t[ls].v+=tagadd[id];
				tagadd[ls]+=tagadd[id];
			}
			if(rs)
			{
				t[rs].v+=tagadd[id];
				tagadd[rs]+=tagadd[id];
			}
			tagadd[id]=0;
		}
		if(tagcnt[id])
		{
			if(ls)
			{
				t[ls].cnt+=tagcnt[id];
				tagcnt[ls]+=tagcnt[id];
			}
			if(rs)
			{
				t[rs].cnt+=tagcnt[id];
				tagcnt[rs]+=tagcnt[id];
			}
			tagcnt[id]=0;
		}
	}
	int merge(int x,int y)
	{
		if(x==y) return x;
		if(!x||!y) return x+y;
		if(t[x].v>t[y].v) swap(x,y);
		pushdown(x);
		t[x].rs=merge(t[x].rs,y);
		if(t[t[x].rs].d>t[t[x].ls].d) swap(t[x].ls,t[x].rs);
		t[x].d=t[t[x].rs].d+1;
		sz[x]=sz[t[x].ls]+sz[t[x].rs]+1;
		return x;
	}
	void clear(){root[rt]=0;}
	void join(int y)
	{
		if(rt==y) return;
		root[rt]=merge(root[rt],root[y]);
		root[y]=0;
	}
	void push(type v,int p=0){root[rt]=merge(root[rt],newnode(v,p));}
	void pop()
	{
		int x=root[rt];
		pushdown(x);
		root[rt]=merge(t[x].ls,t[x].rs);
	}
	node top(){return t[root[rt]];}
	bool empty(){return !root[rt];}
	int size(){return sz[root[rt]];}
	void upd(int op,type v)
	{
		int x=root[rt];
		if(op==0)
		{
			tagadd[x]+=v;
			t[x].v+=v;
		}
		else
		{
			tagadd[x]*=v;
			tagmul[x]*=v;
			t[x].v*=v;
		}
		tagcnt[x]++;
		t[x].cnt++;
	}
	#undef type
}q;
/*
q.init();
q.init(n);
q[x].push(x);
q[x].push(x,id);
q[x].top();
q[x].pop();
q[x].join(y);
q[x].clear();
*/
vector<int> mp[MAX];
ll h[MAX],v[MAX];
int a[MAX],ra[MAX],rb[MAX];
void dfs(int x)
{
	for(auto &to:mp[x])
	{
		dfs(to);
		q[x].join(to);
	}
	ra[x]=0;
	while(q[x].size())
	{
		auto it=q[x].top();
		if(it.v>=h[x]) break;
		q[x].pop();
		rb[it.id]=it.cnt;
		ra[x]++;
	}
	q[x].upd(a[x],v[x]);
}
int main()
{
	int n,m,i,fa,c;
	ll s;
	scanf("%d%d",&n,&m);
	q.init(n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&h[i]);
		q[i].clear();
		mp[i].clear();
	}
	a[1]=v[1]=0;
	for(i=2;i<=n;i++)
	{
		scanf("%d%d%lld",&fa,&a[i],&v[i]);
		mp[fa].push_back(i);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld%d",&s,&c);
		q[c].push(s,i);
	}
	dfs(1);
	while(q[1].size())
	{
		auto it=q[1].top();
		q[1].pop();
		rb[it.id]=it.cnt;
	}
	for(i=1;i<=n;i++) printf("%d\n",ra[i]);
	for(i=1;i<=m;i++) printf("%d\n",rb[i]);
	return 0;
}
