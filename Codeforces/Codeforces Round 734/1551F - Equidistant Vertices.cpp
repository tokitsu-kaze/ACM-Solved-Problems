#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=100+10;
const int mod=1e9+7;
vector<int> mp[MAX];
int cnt[MAX][MAX],dp[2][MAX];
void dfs(int x,int fa,int be,int h)
{
	cnt[be][h]++;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x,be,h+1);
	}
}
int main()
{
	int T,n,k,a,b,x,i,j,sum,ans,f;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		if(k==2)
		{
			printf("%lld\n",(1LL*n*(n-1)/2)%mod);
			continue;
		}
		ans=0;
		for(x=1;x<=n;x++)
		{
			for(auto &to:mp[x])
			{
				memset(cnt[to],0,sizeof cnt[to]);
				dfs(to,x,to,1);
			}
			for(i=1;i<=n;i++)
			{
				sum=0;
				for(auto &to:mp[x]) sum+=cnt[to][i];
				if(sum<k) continue;
				f=0;
				memset(dp[f],0,sizeof dp[f]);
				dp[f][0]=1;
				for(auto &to:mp[x])
				{
					f^=1;
					memset(dp[f],0,sizeof dp[f]);
					for(j=0;j<=k;j++)
					{
						dp[f][j]=dp[!f][j];
						if(j>0) dp[f][j]=(dp[f][j]+1LL*dp[!f][j-1]*cnt[to][i])%mod;
					}
				}
				ans=(ans+dp[f][k])%mod;
			}	
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
以中心为根，并且根只能是lca，也就是说每个子树只能选一个，然后做dp。
注意特判k=2。
*/
