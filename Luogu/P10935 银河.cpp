#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
struct node{int to,w;};
struct Strongly_Connected_Components
{
	int scc_cnt,tot;
	int low[MAX],dfn[MAX],col[MAX],sz[MAX];
	int st[MAX],top,flag[MAX];
	vector<node> *mp;
	void dfs(int x)
	{
		int tmp;
		st[top++]=x;
		flag[x]=1;
		low[x]=dfn[x]=++tot;
		for(auto &it:mp[x])
		{
			int to=it.to;
			if(!dfn[to])
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
	void work(int n,vector<node> *_mp)
	{
		int i;
		mp=_mp;
		for(i=1;i<=n;i++) col[i]=sz[i]=flag[i]=0;
		scc_cnt=top=tot=0;
		for(i=1;i<=n;i++)
		{
			if(col[i]) continue;
			dfs(i);
		}
	}
	bool rebuild(int n,vector<node> *g,int *in)
	{
		int i;
		for(i=1;i<=n;i++) g[i].clear();
		for(i=1;i<=n;i++)
		{
			for(auto &it:mp[i])
			{
				int to=it.to;
				if(col[i]==col[to])
				{
					if(it.w) return 0;
					continue;
				}
				g[col[i]].push_back({col[to],it.w});
				in[col[to]]++;
			}
		}
		return 1;
	}
}scc;
/*
scc.work(n,mp);
*/
int dp[MAX];
void topsort(int n,vector<node> *mp,int *in)
{
	int i;
	queue<int> q;
	for(i=1;i<=n;i++)
	{
		if(!in[i]) q.push(i);
		dp[i]=0;
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto &it:mp[x])
		{
			int to=it.to;
			in[to]--;
			if(!in[to]) q.push(to);
			dp[to]=max(dp[to],dp[x]+it.w);
		}
	}
}
vector<node> mp[MAX],new_mp[MAX];
void add_edge(int x,int y,int w){mp[x].push_back({y,w});}
int in[MAX];
int main()
{
	int n,k,i,op,a,b,d;
	ll ans;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		new_mp[i].clear();
		in[i]=0;
	}
	while(k--)
	{
		scanf("%d%d%d",&op,&a,&b);
		if(op==1)
		{
			// xa==xb  ->   xa>=xb, xa<=xb
			add_edge(a,b,0);
			add_edge(b,a,0);
		}
		else if(op==2)
		{
			// xa<xb  ->   xa+1<=xb
			add_edge(a,b,1);
		}
		else if(op==3)
		{
			// xa>=xb
			add_edge(b,a,0);
		}
		else if(op==4)
		{
			// xa>xb  ->   xa>=xb+1
			add_edge(b,a,1);
		}
		else
		{
			// xa<=xb
			add_edge(a,b,0);
		}
	}
	scc.work(n,mp);
	if(!scc.rebuild(n,new_mp,in)) return 0*puts("-1");
	topsort(scc.scc_cnt,new_mp,in);
	ans=n;
	for(i=1;i<=n;i++) ans+=dp[scc.col[i]];
	printf("%lld\n",ans);
	return 0;
}
