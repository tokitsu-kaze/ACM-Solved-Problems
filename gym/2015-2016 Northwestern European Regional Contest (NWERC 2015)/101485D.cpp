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
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
ll n,r,p,dp[MAX];
ll dfs(ll x)
{
	ll temp=(x-1)*p+r,i;
	if(x==1) return 0;
	if(dp[x]!=-1) return dp[x];
	for(i=x;i>=2;i--)
	{
		temp=min(temp,dfs((x+i-1)/i)+(i-1)*p+r);
	}
	return dp[x]=temp;
}
int main()
{
	while(~scanf("%lld%lld%lld",&n,&r,&p))
	{
		mem(dp,-1);
		printf("%lld\n",dfs(n));
	}
	return 0;
}