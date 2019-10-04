#include <bits/stdc++.h>
using namespace std;
long long dp[20000];
long long v[20000];
long long c[20000];
const long long mod=(long long)1e9+7;
int main()
{
	long long T;
	cin>>T;
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		long long n,q;
		scanf("%lld%lld",&n,&q);
		for(long long i=1;i<=n;i++)
		{
			scanf("%lld%lld",&v[i],&c[i]);
		}
		for(long long i=1;i<=n;i++)
		{
			for(long long bit=0;bit<c[i];bit++)
			{
				for(long long j=10000; j>=0; j--)
				{
					if(j - (1<<bit)*v[i] >= 0)
					{
						dp[j]=(dp[j]+dp[j - (1<<bit)*v[i]])%mod;
					}
				}
			}
		}
		while(q--)
		{
			long long s;
			scanf("%lld",&s);
			printf("%lld\n",dp[s]);
		}

	}
	return 0;
}