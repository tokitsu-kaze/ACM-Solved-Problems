#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e6+10;
struct Leftist_Tree
{
	#define type ll
	struct node
	{
		int ls,rs,d,id;
		type v;
		void init(){ls=rs=d=id=v=0;}
	}t[MAX];
	int root[MAX],rt,tot,sz[MAX];
	type tagadd[MAX],tagmul[MAX];
	Leftist_Tree &operator[](const int _rt){this->rt=_rt;return *this;}
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
		tagadd[id]=0;
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
	}
	int merge(int x,int y)
	{
		if(x==y) return x;
		if(!x||!y) return x+y;
		if(t[x].v>t[y].v) swap(x,y); // > small, < big
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
struct Trie
{
	#define type int
	static const int K=2;
	int nex[MAX][K],cnt[MAX];
	int root,tot;
	int getid(char c){return c-'0';}
	int newnode()
	{
		tot++;
		memset(nex[tot],0,sizeof nex[tot]);
		cnt[tot]=0;
		return tot;
	}
	void init()
	{
		tot=0;
		memset(nex[0],0,sizeof nex[0]);
		cnt[0]=0;
		root=newnode();
	}
	void insert(char *s,int n) // s[0..n-1]
	{
		int now,i,t;
		now=root;
		for(i=0;i<n;i++)
		{
			t=getid(s[i]);
			if(!nex[now][t]) nex[now][t]=newnode();
			now=nex[now][t];
		}
		cnt[now]++;
	}
	ll ans;
	void dfs(int id)
	{
		if(nex[id][0])
		{
			dfs(nex[id][0]);
			q[id].join(nex[id][0]);
		}
		if(nex[id][1])
		{
			dfs(nex[id][1]);
			q[id].join(nex[id][1]);
		}
		if(!nex[id][0] && !nex[id][1])
		{
			q[id].push(2,1);
			cnt[id]--;
		}
		else if(nex[id][0] && nex[id][1]);
		else q[id].push(1,0);
		while(cnt[id]>0)
		{
			cnt[id]--;
			auto it=q[id].top();
			q[id].pop();
			ans+=it.v;
			q[id].push(it.v+2-it.id,1);
			if(it.id==1) q[id].push(it.v+2-it.id,1);
		}
		// it.id=0:不是叶子可以直接移动；  =1:是叶子要多一步
		q[id].upd(0,1);
	}
	#undef type
}tr;
/*
tr.init();
tr.insert(s,len); s[0..len-1]
*/
char s[MAX];
int main()
{
	int n,i;
	scanf("%d",&n);
	tr.init();
	while(n--)
	{
		scanf("%s",s);
		tr.insert(s,strlen(s));
	}
	q.init(tr.tot);
	tr.ans=0;
	tr.dfs(tr.root);
	printf("%lld\n",tr.ans);
	return 0;
}
/*
题意为：
给一个二叉树，树上节点有若干个 1，
你需要将所有 1 移动到叶子，没有的节点可以新建， 
问所有 1 移动的总步数至少是多少。 

如果叶子没有，走到叶子，步数为距离； 
如果叶子有，new两个儿子，
把叶子上的移动到其中一个，手上的可以移动到另一个
如果只有一个儿子，可以new一个儿子。 
用堆维护所有可移动的儿子，需要区分是否是叶子。
回溯时堆中所有值都要+1。
启发式合并两个log可以直接做，也可以用左偏树合并和打tag。 
*/
