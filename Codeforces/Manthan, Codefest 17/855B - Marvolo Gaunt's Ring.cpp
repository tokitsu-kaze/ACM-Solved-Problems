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
ll a[MAX],c[5],dp[5][MAX],temp[5];
int main()
{
	ll n,i,j,ans;
	while(~scanf("%lld%lld%lld%lld",&n,&c[1],&c[2],&c[3]))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		mem(dp,-0x3f);
		mem(temp,-0x3f);
		temp[0]=0;
		dp[1][0]=0;
		dp[1][1]=a[1]*c[1];
		dp[2][1]=dp[1][1]+a[1]*c[2];
		dp[3][1]=dp[2][1]+a[1]*c[3];
		for(i=1;i<=n;i++)
		{
			dp[0][i]=0;
			for(j=1;j<=3;j++)
			{
				if(i>1) dp[j][i]=temp[j-1]+a[i]*c[j];
				temp[j]=max(dp[j][i],temp[j]);
			}
		}
		ans=-LLINF;
		for(i=1;i<=n;i++)
		{
			ans=max(ans,dp[3][i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}