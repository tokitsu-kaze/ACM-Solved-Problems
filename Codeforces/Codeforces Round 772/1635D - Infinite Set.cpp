#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=1e9+7;
int a[MAX],dp[MAX],sumdp[MAX];
int main()
{
	int n,p,i,x,cnt,ok;
	ll ans;
	scanf("%d%d",&n,&p);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	dp[0]=sumdp[0]=1;
	for(i=1;i<=p;i++)
	{
		dp[i]=dp[i-1];
		if(i-2>=0) dp[i]=(dp[i]+dp[i-2])%mod;
		sumdp[i]=(dp[i]+sumdp[i-1])%mod;
	}
	map<int,int> mp;
	ans=0;
	for(i=1;i<=n;i++)
	{
		x=a[i];
		cnt=0;
		while(x>0)
		{
			x>>=1;
			cnt++;
		}
		ok=1;
		x=a[i];
		while(x>0)
		{
			if(mp.count(x)) ok=0;
			if(x&1) x>>=1;
			else if(!(x&3)) x>>=2;
			else break;
		}
		if(p-cnt>=0 && ok) ans=(ans+sumdp[p-cnt])%mod;
		mp[a[i]]=1;
	}
	printf("%lld\n",ans);
	return 0;
}

