#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
int dp[MAX][2][2][2][12];
int main()
{
	int n,i,j,a,b,c,x,ans;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			x&=1;
			memset(dp[i],0,sizeof dp[i]);
			dp[i][0][0][x][1]=1;
			for(a=0;a<2;a++)
			{
				for(b=0;b<2;b++)
				{
					for(c=0;c<2;c++)
					{
						for(j=1;j<=6;j++)
						{
							dp[i][a][b][c][j]=(dp[i][a][b][c][j]+dp[i-1][a][b][c][j])%mod;
							dp[i][b][c][x][j]=(dp[i][b][c][x][j]+dp[i-1][a][b][c][j-1])%mod;
						}
						dp[i][b][c][x][4]=(dp[i][b][c][x][4]+dp[i-1][a][b][c][6])%mod;
					}
				}
			}
			for(a=0;a<2;a++)
			{
				for(b=0;b<2;b++)
				{
					for(c=0;c<2;c++)
					{
						if(!((a+b+c)&1)) continue;
						for(j=3;j<=6;j++)
						{
							dp[i][a][b][c][j]=0;
						}
					}
				}
			}
		}
		ans=0;
		for(a=0;a<2;a++)
		{
			for(b=0;b<2;b++)
			{
				for(c=0;c<2;c++)
				{
					if((a+b+c)&1) continue;
					for(j=3;j<=6;j++)
					{
						ans=(ans+dp[n][a][b][c][j])%mod;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

