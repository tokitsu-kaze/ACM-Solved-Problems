#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int mod=1e8;
int mp[15][15],dp[2][(1<<12)+10];
int main()
{
	int n,m,i,j,f,lf,up,s,s0,s1,ans;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&mp[i][j]);
		}
	}
	f=0;
	memset(dp[f],0,sizeof dp[f]);
	dp[f][0]=1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			f^=1;
			memset(dp[f],0,sizeof dp[f]);
			for(s=0;s<(1<<m);s++)
			{
				if(j==0) lf=0;
				else lf=(s>>(j-1))&1;
				up=(s>>j)&1;
				if(!i && up) continue;
				s0=(((1<<m)-1)^(1<<j))&s;
				s1=s|(1<<j);
				dp[f][s0]=(dp[f][s0]+dp[f^1][s])%mod;
				if(!lf&&!up&&mp[i][j]) dp[f][s1]=(dp[f][s1]+dp[f^1][s])%mod;
			}
		}
	}
	ans=0;
	for(s=0;s<(1<<m);s++) ans=(ans+dp[f][s])%mod;
	printf("%d\n",ans);
	return 0;
}

