#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
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
bool vis[MAX<<1];
int sz[MAX<<1],val[MAX<<1],n,tot;
ll ans;
void get_sz(int x,int fa)
{
	if(x<=n) tot++;
	for(auto &to:g[x])
	{
		if(to==fa) continue;
		get_sz(to,x);
	}
}
void dfs(int x,int fa)
{
//	cout<<x<<" "<<fa<<endl;
	vis[x]=1;
	if(x<=n)
	{
		sz[x]=1;
		val[x]=-1;
	}
	else
	{
		sz[x]=0;
		val[x]=g[x].size();
	}
	for(auto &to:g[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		ans+=2LL*sz[x]*sz[to]*val[x];
		sz[x]+=sz[to];
	}
	ans+=2LL*(tot-sz[x])*sz[x]*val[x];
}
int main()
{
	int m,i,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) mp[i].clear();
	while(m--)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	rst.build(n,mp,g);
	ans=0;
	for(i=1;i<=2*n;i++) vis[i]=0;
	for(i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		tot=0;
		get_sz(i,0);
		dfs(i,0);
	}
	printf("%lld\n",ans);
	return 0;
}
