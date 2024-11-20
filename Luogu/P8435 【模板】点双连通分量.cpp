#include <bits/stdc++.h>
using namespace std;
const int MAX=5e5+10;
struct Round_Square_Tree
{
	int tot,id,bcc_cnt;
	int low[MAX],dfn[MAX];
	int st[MAX],top;
	vector<int> *mp,*g;
	void dfs(int x,int fa)
	{
		int to,i,tmp,k;
		st[top++]=x;
		low[x]=dfn[x]=++tot;
		for(auto &to:mp[x])
		{
			if(!dfn[to])
			{
				dfs(to,x);
				low[x]=min(low[x],low[to]);
				if(low[to]==dfn[x])
				{
					id++;
					while(top)
					{
						tmp=st[--top];
						g[tmp].push_back(id);
						g[id].push_back(tmp);
						if(tmp==to) break;
					}
					g[x].push_back(id);
					g[id].push_back(x);
				}
			}
			else low[x]=min(low[x],dfn[to]);
		}
	}
	int build(int n,vector<int> *_mp,vector<int> *_g)
	{
		int i;
		mp=_mp;
		g=_g;
		for(i=0;i<=n;i++) low[i]=dfn[i]=0;
		for(i=0;i<=(n<<1);i++) g[i].clear();
		top=tot=0;
		id=n;
		for(i=1;i<=n;i++)
		{
			if(!dfn[i]) dfs(i,i);
		}
		bcc_cnt=id-n;
		return id;
	}
}rst;
/*
vector<int> mp[MAX],g[MAX<<1];
tot=rst.build(n,mp,g);
*/
vector<int> mp[MAX],g[MAX<<1];
int main()
{
	int n,m,i,a,b,tot;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) mp[i].clear();
	while(m--)
	{
		scanf("%d%d",&a,&b);
		if(a==b) continue;
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	vector<int> res;
	for(i=1;i<=n;i++)
	{
		if(mp[i].size()==0) res.push_back(i);
	}
	tot=rst.build(n,mp,g);
	printf("%d\n",rst.bcc_cnt+res.size());
	for(i=n+1;i<=tot;i++)
	{
		printf("%d",g[i].size());
		for(auto &it:g[i]) printf(" %d",it);
		puts("");
	}
	for(auto &it:res) printf("1 %d\n",it);
	return 0;
}
