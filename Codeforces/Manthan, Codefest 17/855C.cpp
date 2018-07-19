#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
vector<ll> mp[MAX];
ll n,m,r,tot,dp[MAX][12][3],ans;
void dfs(ll x,ll pre)
{
	ll i,j,k,flag=0,temp[12][3];
	dp[x][0][0]=r-1;
	dp[x][1][1]=1;
	dp[x][0][2]=m-r;
	for(i=0;i<sz(mp[x]);i++)
	{
		ll to=mp[x][i];
		if(to!=pre)
		{
			flag=1;
			dfs(to,x);
			mem(temp,0);
			for(j=0;j<=tot;j++)
			{
				for(k=0;j+k<=tot;k++)
				{
					temp[j+k][0]=(temp[j+k][0]+dp[x][j][0]*(dp[to][k][0]+dp[to][k][1]+dp[to][k][2]))%mod;
					temp[j+k][1]=(temp[j+k][1]+dp[x][j][1]*dp[to][k][0])%mod;
					temp[j+k][2]=(temp[j+k][2]+dp[x][j][2]*(dp[to][k][0]+dp[to][k][2]))%mod;
				}
			}
			for(j=0;j<=tot;j++)
			{
				for(k=0;k<3;k++)
				{
					dp[x][j][k]=temp[j][k];
				}
			}
		}
	}
}
int main()
{
	ll i,j,a,b;
	while(~scanf("%lld%lld",&n,&m))
	{
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		scanf("%lld%lld",&r,&tot);
		mem(dp,0);
		dfs(1,0);
		ans=0;
		for(i=0;i<=tot;i++)
		{
			for(j=0;j<3;j++)
			{
				ans+=dp[1][i][j];
				ans%=mod;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 