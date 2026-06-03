#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
const int mod=998244353;
vector<int> pos[MAX];
int dp[MAX],sum[MAX],a[MAX],cnt[MAX];
int main()
{
	int n,i,ans,p;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		pos[i].clear();
		cnt[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		pos[a[i]].push_back(i);
	}
	dp[0]=sum[0]=1;
	for(i=1;i<=n;i++)
	{
		cnt[a[i]]++;
		if(cnt[a[i]]>=a[i])
		{
			p=cnt[a[i]]-a[i];
			dp[i]=sum[pos[a[i]][p]-1];
			if(cnt[a[i]]>a[i]) dp[i]-=sum[pos[a[i]][p-1]];
			if(dp[i]<0) dp[i]+=mod;
		}
		else dp[i]=0;
		sum[i]=(sum[i-1]+dp[i])%mod;
	}
	ans=0;
	for(i=1;i<=n;i++) ans=(ans+dp[i])%mod;
	printf("%d\n",ans);
	return 0;
}
