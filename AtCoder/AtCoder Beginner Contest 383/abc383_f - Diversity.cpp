#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=50000+10;
const int mod=998244353;
int p[505],c[505];
ll u[505];
ll dp[MAX][2];
vector<int> id[505];
int main()
{
	int n,i,j,k,x;
	ll ans;
	scanf("%d%d%d",&n,&x,&k);
	for(i=1;i<=n;i++) id[i].clear();
	for(i=1;i<=n;i++)
	{
		scanf("%d%lld%d",&p[i],&u[i],&c[i]);
		id[c[i]].push_back(i);
	}
	memset(dp,0,sizeof dp);
	for(i=1;i<=n;i++)
	{
		for(j=x;j>=0;j--) dp[j][0]=max(dp[j][0],dp[j][1]);
		for(auto &it:id[i])
		{
			for(j=x;j>=p[it];j--)
			{
				dp[j][1]=max(dp[j][1],dp[j-p[it]][0]+u[it]+k);
				dp[j][1]=max(dp[j][1],dp[j-p[it]][1]+u[it]);
			}
		}
	}
	ans=0;
	for(i=0;i<=x;i++) ans=max({ans,dp[i][0],dp[i][1]});
	printf("%lld\n",ans);
	return 0;
}
