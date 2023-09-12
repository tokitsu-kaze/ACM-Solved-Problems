#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
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
int in[MAX],out[MAX];
int main()
{
	int n,i,x,cntin,cntout;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		in[i]=out[i]=0;
		mp[i].clear();
		while(scanf("%d",&x)&&x>0) mp[i].push_back(x);
	}
	scc.work(n,mp);
	for(i=1;i<=n;i++)
	{
		for(auto &to:mp[i])
		{
			if(scc.col[i]==scc.col[to]) continue;
			in[scc.col[to]]++;
			out[scc.col[i]]++;
		}
	}
	if(scc.scc_cnt==1)
	{
		puts("1");
		puts("0");
		return 0;
	}
	cntin=cntout=0;
	for(i=1;i<=scc.scc_cnt;i++)
	{
		if(!in[i]) cntin++;
		if(!out[i]) cntout++;
	}
	printf("%d\n",cntin);
	printf("%d\n",max(cntin,cntout));
	return 0;
}
