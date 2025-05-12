#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=(1<<16)+10;
char ss[MAX];
int g[17],w[17],dp[MAX][17];
int main()
{
	int T,n,i,j,s,tot,ans;
	scanf("%d",&T);
	while(T--)
	{
		map<string,int> ha;
		tot=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",ss);
			if(!ha[ss]) ha[ss]=++tot;
			g[i]=ha[ss];
			scanf("%s",ss);
			if(!ha[ss]) ha[ss]=++tot;
			w[i]=ha[ss];
		}
		for(s=0;s<(1<<n);s++) memset(dp[s],0,sizeof dp[s]);
		for(s=0;s<(1<<n);s++)
		{
			if(__builtin_popcount(s)==1)
			{
				for(i=0;i<n;i++)
				{
					if(!((s>>i)&1)) continue;
					dp[s][i]=1;
				}
				continue;
			}
			for(i=0;i<n;i++)
			{
				if(!((s>>i)&1)) continue;
				for(j=0;j<n;j++)
				{
					if(!((s>>j)&1)) continue;
					if(g[i]!=g[j] && w[i]!=w[j]) continue;
					dp[s][i]|=dp[s^(1<<i)][j];
				}
			}
		}
		ans=n;
		for(s=0;s<(1<<n);s++)
		{
			for(i=0;i<n;i++)
			{
				if(dp[s][i]) ans=min(ans,n-__builtin_popcount(s));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
