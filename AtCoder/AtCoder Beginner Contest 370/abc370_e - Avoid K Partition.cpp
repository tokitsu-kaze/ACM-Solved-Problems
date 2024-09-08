#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
const int mod=998244353;
ll a[MAX],bit[MAX];
int dp[MAX],bitdp[MAX];
int main()
{
	int n,i;
	ll k;
	scanf("%d%lld",&n,&k);
	bit[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		bit[i]=bit[i-1]+a[i];
	}
	dp[0]=bitdp[0]=1;
	map<ll,int> mp;
	mp[0]=1;
	for(i=1;i<=n;i++)
	{
		dp[i]=bitdp[i-1];
		if(mp.count(bit[i]-k)) dp[i]=(dp[i]-mp[bit[i]-k]+mod)%mod;
		bitdp[i]=(bitdp[i-1]+dp[i])%mod;
		mp[bit[i]]=(mp[bit[i]]+dp[i])%mod;
//		cout<<i<<" "<<pos<<" "<<dp[i]<<endl;
	}
	printf("%d\n",dp[n]);
	return 0;
}

