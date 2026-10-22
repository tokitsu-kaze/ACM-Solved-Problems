#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
struct Strongly_Connected_Components
{
	int scc_cnt,tot;
	int low[MAX],dfn[MAX],col[MAX],sz[MAX];
	int st[MAX],top,flag[MAX];
	vector<int> mp[MAX];
	void dfs(int x)
	{
		int tmp;
		st[top++]=x;
		flag[x]=1;
		low[x]=dfn[x]=++tot;
		for(auto &to:mp[x])
		{
			if(!dfn[to]) // dfn must be cleared
			{
				dfs(to);
				low[x]=min(low[x],low[to]);
			}
			else if(flag[to]) low[x]=min(low[x],dfn[to]);
		}
		if(low[x]==dfn[x])
		{
			scc_cnt++;
			do
			{
				tmp=st[--top];
				flag[tmp]=0;
				col[tmp]=scc_cnt;
				sz[scc_cnt]++;
			}while(tmp!=x);
		}
	}
	void work(int n,vector<int> *_mp)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			col[i]=sz[i]=flag[i]=dfn[i]=0;
			mp[i].assign(_mp[i].begin(),_mp[i].end());
		}
		scc_cnt=top=tot=0;
		for(i=1;i<=n;i++)
		{
			if(col[i]) continue;
			dfs(i);
		}
	}
	void rebuild(int n,vector<int> *g)
	{
		int i;
		for(i=1;i<=n;i++) g[i].clear();
		for(i=1;i<=n;i++)
		{
			for(auto &to:mp[i])
			{
				if(col[i]==col[to]) continue;
				g[col[i]].push_back(col[to]);
			}
		}
	}
}scc;
/*
scc.work(n,mp);
*/
vector<int> mp[MAX];
int main()
{
	int T,n,m,i,j,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) mp[i].clear();
		while(m--)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
		}
		scc.work(n,mp);
		if(scc.scc_cnt==1)
		{
			puts("No");
			continue;
		}
		puts("Yes");
		printf("%d %d\n",scc.sz[1],n-scc.sz[1]);
		for(i=1,j=0;i<=n;i++)
		{
			if(scc.col[i]==1)
			{
				j++;
				printf("%d%c",i," \n"[j==scc.sz[1]]);
			}
		}
		for(i=1,j=0;i<=n;i++)
		{
			if(scc.col[i]!=1)
			{
				j++;
				printf("%d%c",i," \n"[j==n-scc.sz[1]]);
			}
		}
	}
	return 0;
}
/*
考虑拆点，居民和猫连边。
问题转化成，恰好选出n个点，至少有一个人一只猫，并且n个点是独立集。
那也就是说，选一个人，对应的猫就不能选，似乎是二分图。
不是，那也就是说，人和猫必选选一个，如果不选人，就必须选猫。

接着发现，强连通内一个点选了人，整个强连通都选人。
不用拆点。考虑全选猫，然后再至少选一个人。所以选人的 scc 需要没有出度。
由于跑 tarjan 时，第一个被找到的 scc，就是因为没有出度，所以才被找到并且回溯的。
所以第一个 scc 就是没有出度的，这个 scc 全选人。
这样能简化代码。
*/
