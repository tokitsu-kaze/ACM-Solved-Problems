#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
const ll mod=998244353;
struct LCA
{
	static const int N=MAX;
	static const int LOGN=log2(N)+3;
	int fa[N][LOGN],dep[N],limt,bin[LOGN];
	void dfs(int x,int pre,vector<int> mp[])
	{
		int i;
		for(i=1;bin[i]<=dep[x];i++) fa[x][i]=fa[fa[x][i-1]][i-1];
		for(auto &to:mp[x])
		{
			if(to==pre) continue;
			dep[to]=dep[x]+1;
			fa[to][0]=x;
			dfs(to,x,mp);
		}
	}
	void work(int n,int root,vector<int> mp[])
	{
		int i;
		for(limt=1;(1<<(limt-1))<n;limt++);
		for(i=bin[0]=1;i<=limt;i++) bin[i]=(bin[i-1]<<1);
		for(i=0;i<=n;i++) memset(fa[i],0,sizeof fa[i]);
		dep[root]=0;
		dfs(root,-1,mp);
	}
	int go(int x,int d)
	{
		for(int i=0;i<=limt&&d;i++)
		{
			if(bin[i]&d)
			{
				d^=bin[i];
				x=fa[x][i];
			}
		}
		return x;
	}
	int lca(int x,int y)
	{
		if(dep[x]<dep[y]) swap(x,y);
		x=go(x,dep[x]-dep[y]);
		if(x==y) return x;
		for(int i=limt;~i;i--)
		{
			if(fa[x][i]!=fa[y][i])
			{
				x=fa[x][i];
				y=fa[y][i];
			}
		}
		return fa[x][0];
	}
}lca;
vector<int> mp[MAX];
int bit[MAX][52];
void dfs(int x,int fa,int h)
{
	int i;
	bit[x][0]=1;
	for(i=1;i<=50;i++) bit[x][i]=1ll*bit[x][i-1]*h%mod;
	for(i=1;i<=50;i++) (bit[x][i]+=bit[fa][i])%=mod;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x,h+1);
	}
}
int main()
{
	int n,q,i,a,b,k;
	ll ans;
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	{
		mp[i].clear();
		memset(bit[i],0,sizeof bit[i]);
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	lca.work(n,1,mp);
	dfs(1,0,0);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d",&a,&b,&k);
		ans=bit[a][k]+bit[b][k];
		ans-=bit[lca.lca(a,b)][k];
		ans-=bit[lca.fa[lca.lca(a,b)][0]][k];
		ans=(ans%mod+mod)%mod;
		printf("%lld\n",ans);
	}
	return 0;
}

