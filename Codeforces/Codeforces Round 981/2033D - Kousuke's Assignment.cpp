#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int a[MAX],dp[MAX];
int main()
{
	int T,n,i,j;
	ll bit;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		dp[0]=0;
		map<ll,int> mp;
		mp[0]=0;
		bit=0;
		for(i=1;i<=n;i++)
		{
			bit+=a[i];
			dp[i]=dp[i-1];
			if(mp.count(bit)) dp[i]=max(dp[i],dp[mp[bit]]+1);
			mp[bit]=i;
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}
