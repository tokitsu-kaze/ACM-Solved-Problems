#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e4+10;
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
	void work(int n,vector<int> *_mp)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			col[i]=sz[i]=flag[i]=0;
			mp[i]=_mp[i];
		}
		scc_cnt=top=tot=0;
		for(i=1;i<=n;i++)
		{
			if(col[i]) continue;
			dfs(i);
		}
	}
	void rebuild(int n,vector<int> *g,int *cnt,bitset<10001> *bs)
	{
		int i;
		for(i=1;i<=scc_cnt;i++) bs[i].reset();
		for(i=1;i<=n;i++)
		{
			g[i].clear();
			cnt[col[i]]++;
			bs[col[i]].set(i);
		}
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
bitset<10001> bs[MAX];
vector<int> topsort(int n,vector<int> mp[],int *in)
{
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(!in[i]) q.push(i);
	}
	vector<int> toplist;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		toplist.push_back(x);
		for(auto &to:mp[x])
		{
			in[to]--;
			bs[to]|=bs[x];
			if(!in[to]) q.push(to);
		}
	}
	return toplist;
}
vector<int> mp[MAX];
int cnt[MAX],in[MAX];
int main()
{
	int n,m,i,a,b,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		cnt[i]=in[i]=0;
	}
	while(m--)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
	}
	scc.work(n,mp);
	scc.rebuild(n,mp,cnt,bs);
	for(i=1;i<=scc.scc_cnt;i++)
	{
		for(auto &to:mp[i]) in[to]++;
	}
	topsort(scc.scc_cnt,mp,in);
	ans=0;
	for(i=1;i<=scc.scc_cnt;i++)
	{
		if(bs[i].count()==n) ans+=cnt[i];
	}
	printf("%d\n",ans);
	return 0;
}
/*
4 3
1 2
2 3
1 3
*/
