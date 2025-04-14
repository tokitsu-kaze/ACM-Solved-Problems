#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
vector<int> mp[MAX];
int dep[MAX],cnt[MAX],sum[MAX],mxdep[MAX],sz[MAX];
void dfs(int x,int fa)
{
	sz[x]=1;
	dep[x]=dep[fa]+1;
	cnt[dep[x]]++;
	mxdep[x]=dep[x];
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		sz[x]+=sz[to];
		mxdep[x]=max(mxdep[x],mxdep[to]);
	}
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		if(mxdep[to]<mxdep[x])
		{
			sum[mxdep[to]+1]+=sz[to];
			sz[x]-=sz[to];
		}
	}
}
int main()
{
	int T,i,n,ans,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<=n+1;i++)
		{
			mp[i].clear();
			cnt[i]=dep[i]=mxdep[i]=sum[i]=0;
		}
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		dep[0]=0;
		dfs(1,0);
		for(i=1;i<=n;i++) sum[i]+=sum[i-1];
		for(i=n;i;i--) cnt[i]+=cnt[i+1];
		ans=n-1;
//		for(i=1;i<=n;i++) printf("%d %d %d\n",i,cnt[i],sum[i]);
		for(i=1;i<=mxdep[1];i++) ans=min(ans,cnt[i+1]+sum[i]);
		printf("%d\n",ans);
	}
	return 0;
}

