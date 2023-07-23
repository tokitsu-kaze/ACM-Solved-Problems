#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> mp[12];
ll dp[(1<<10)+5][(1<<10)+5];
int main()
{
	int n,m,k,s,t,i,j,a,b;
	ll ans;
	scanf("%d%d%d",&n,&m,&k);
	for(i=0;i<n;i++) mp[i].clear();
	memset(dp,0,sizeof dp);
	while(m--)
	{
		scanf("%d%d",&a,&b);
		a--;
		b--;
		mp[a].push_back(b);
		mp[b].push_back(a);
		dp[(1<<a)|(1<<b)][(1<<a)|(1<<b)]=2;
	}
	for(s=0;s<(1<<n);s++)
	{
		for(t=s;t;t=s&(t-1))
		{
			if(!dp[s][t]) continue;
			dp[s][t]/=__builtin_popcount(t);
			for(i=0;i<n;i++)
			{
				if(!((s>>i)&1)) continue;
				for(auto &to:mp[i])
				{
					if((s>>to)&1) continue;
					if((t>>i)&1) dp[s|(1<<to)][(t^(1<<i))^(1<<to)]+=dp[s][t];
					else dp[s|(1<<to)][t|(1<<to)]+=dp[s][t];
				}
			}
		}
	}
	ans=0;
	for(i=0;i<(1<<n);i++)
	{
		if(__builtin_popcount(i)==k) ans+=dp[(1<<n)-1][i];
	}
	printf("%lld\n",ans);
	return 0;
}
