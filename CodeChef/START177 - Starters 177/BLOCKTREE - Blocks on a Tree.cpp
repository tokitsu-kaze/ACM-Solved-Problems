#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2000+10;
vector<int> mp[MAX];
int n,k,sz[MAX],rx,rfa,res[MAX];
void dfs(int x,int fa)
{
	sz[x]=1;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		sz[x]+=sz[to];
		if(sz[to]==k)
		{
			rx=to;
			rfa=x;
		}
		else if(sz[to]==n-k)
		{
			rx=x;
			rfa=to;
		}
	}
}
void dfs2(int x,int fa)
{
	if(k==0) return;
	k--;
	res[x]=1;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs2(to,x);
	}
}
int main()
{
	int T,i,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			res[i]=0;
		}
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		if(k==0)
		{
			puts("1");
			for(i=1;i<=n;i++) printf("%d%c",0," \n"[i==n]);
			continue;
		}
		if(k==n)
		{
			puts("1");
			for(i=1;i<=n;i++) printf("%d%c",1," \n"[i==n]);
			continue;
		}
		rx=rfa=-1;
		dfs(1,0);
		if(rx!=-1)
		{
			dfs2(rx,rfa);
			puts("2");
			for(i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
		}
		else
		{
			dfs2(1,0);
			puts("3");
			for(i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
		}
	}
	return 0;
}
