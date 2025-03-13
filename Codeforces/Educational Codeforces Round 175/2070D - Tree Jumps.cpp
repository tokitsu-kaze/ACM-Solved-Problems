#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
const int mod=998244353;
vector<int> mp[MAX],res[MAX];
int d[MAX],dp[MAX],fa[MAX],sum[MAX];
void dfs(int x,int pre)
{
	d[x]=d[pre]+1;
	res[d[x]].push_back(x);
	for(auto &to:mp[x]) dfs(to,x);
}
int main()
{
	int T,n,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			res[i].clear();
			dp[i]=0;
		}
		for(i=2;i<=n;i++)
		{
			scanf("%d",&fa[i]);
			mp[fa[i]].push_back(i);
		}
		d[0]=0;
		dfs(1,0);
		dp[1]=sum[1]=ans=1;
		for(i=2;i<=n;i++)
		{
			sum[i]=0;
			for(auto &it:res[i])
			{
				if(i==2) dp[it]=sum[i-1];
				else dp[it]=(sum[i-1]-dp[fa[it]]+mod)%mod;
				sum[i]=(sum[i]+dp[it])%mod;
			}
			ans=(ans+sum[i])%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}
