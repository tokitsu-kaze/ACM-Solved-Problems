#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
struct Edge_Biconnected_Component
{
	int bcc_cnt,tot;
	int low[MAX],dfn[MAX],col[MAX];
	int st[MAX],top;
	vector<int> mp[MAX];
	vector<pair<int,int>> bridge;
	void dfs(int x,int fa)
	{
		int to,i,tmp,k;
		st[top++]=x;
		low[x]=dfn[x]=++tot;
		k=0;
		for(auto &to:mp[x])
		{
			if(to==fa&&!k) 
			{
				k++;
				continue;
			}
			if(!dfn[to])
			{
				dfs(to,x);
				low[x]=min(low[x],low[to]);
				if(low[to]>dfn[x]) bridge.push_back({x,to});
			}
			else low[x]=min(low[x],dfn[to]);
		}
		if(low[x]==dfn[x])
		{
			bcc_cnt++;
			do
			{
				tmp=st[--top];
				col[tmp]=bcc_cnt;
			}while(tmp!=x);
		}
	}
	void work(int n,vector<int> *_mp)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			low[i]=dfn[i]=0;
			mp[i]=_mp[i];
		}
		bcc_cnt=top=tot=0;
		bridge.clear();
		for(i=1;i<=n;i++)
		{
			if(!dfn[i]) dfs(i,i);
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
}bcc;
/*
bcc.work(n,mp);
*/
vector<int> mp[MAX];
int main()
{
	int n,m,i,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) mp[i].clear();
	while(m--)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	bcc.work(n,mp);
	vector<pair<int,int>> res=bcc.bridge;
	sort(res.begin(),res.end());
	for(auto &it:res) printf("%d %d\n",it.first,it.second);
	return 0;
}
