#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
int cnt[MAX];
int main()
{
	int T,n,i,x;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<=n;i++) cnt[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x+1>n-x) cnt[n-x]++;
			else cnt[x+1]++;
		}
		ans=1;
		for(i=0;i<=n;i++)
		{
			if(cnt[i]==0) continue;
			if(cnt[i]>2) ans=0;
			if(cnt[i]==2 && i==n-i+1) ans=0;
			ans=ans*cnt[i]%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

