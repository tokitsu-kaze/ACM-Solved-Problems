#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
struct Round_Square_Tree
{
	int tot,id,bcc_cnt;
	int low[MAX],dfn[MAX];
	int st[MAX],top;
	vector<int> *mp,*g;
	void dfs(int x,int fa)
	{
		int i,tmp,k;
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
int fa[MAX<<1];
void dfs(int x,int pre)
{
	fa[x]=pre;
	for(auto &to:g[x])
	{
		if(to==pre) continue;
		dfs(to,x);
	}
}
int main()
{
	int n,m,i,a,b,res,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++) mp[i].clear();
	while(1)
	{
		scanf("%d%d",&a,&b);
		if(a==b) break;
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	rst.build(n,mp,g);
	scanf("%d%d",&a,&b);
	fa[b]=-1;
	dfs(a,0);
	if(fa[b]==-1) return 0*puts("No solution");
	res=n+1;
	x=b;
	while(x&&x!=a)
	{
		if(x!=a && x!=b) res=min(res,x);
		x=fa[x];
	}
	if(res==n+1) puts("No solution");
	else printf("%d\n",res);
	return 0;
}
