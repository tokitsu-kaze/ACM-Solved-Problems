#include <bits/stdc++.h>
using namespace std;
const int MAX=1e4+10;
struct Strongly_Connected_Components
{
	int scc_cnt,tot;
	int low[MAX],dfn[MAX],col[MAX],sz[MAX];
	int st[MAX],top,flag[MAX];
	void dfs(int x,vector<int> *mp)
	{
		int tmp;
		st[top++]=x;
		flag[x]=1;
		low[x]=dfn[x]=++tot;
		for(auto &to:mp[x])
		{
			if(!dfn[to])
			{
				dfs(to,mp);
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
	void work(int n,vector<int> *mp)
	{
		int i;
		for(i=1;i<=n;i++) col[i]=sz[i]=flag[i]=0;
		scc_cnt=top=tot=0;
		for(i=1;i<=n;i++)
		{
			if(col[i]) continue;
			dfs(i,mp);
		}
	}
}scc;
vector<int> mp[MAX];
int main()
{
	int n,m,i,a,b,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) mp[i].clear();
	while(m--)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
	}
	scc.work(n,mp);
	ans=0;
	for(i=1;i<=scc.scc_cnt;i++) ans+=(scc.sz[i]>1);
	printf("%d\n",ans);
	return 0;
}
