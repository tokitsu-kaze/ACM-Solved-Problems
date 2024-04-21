#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=1000+10;
const int mod=1e9+7;
char a[MAX],b[MAX];
int dp[2][205][205][2];
int main()
{
	int n,m,k,i,j,l,f;
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s",a+1);
	scanf("%s",b+1);
	memset(dp,0,sizeof dp);
	f=0;
	dp[f][0][0][0]=1;
	for(i=1;i<=n;i++)
	{
		f^=1;
		memset(dp[f],0,sizeof dp[f]);
		dp[f][0][0][0]=1;
		for(j=1;j<=m&&j<=i;j++)
		{
			for(l=1;l<=k&&l<=j;l++)
			{
				dp[f][j][l][0]=dp[f^1][j][l][0]+dp[f^1][j][l][1];
				if(dp[f][j][l][0]>=mod) dp[f][j][l][0]-=mod;
				
				dp[f][j][l][1]=0;
				if(a[i]==b[j])
				{
					
					dp[f][j][l][1]+=dp[f^1][j-1][l][1];
					dp[f][j][l][1]+=dp[f^1][j-1][l-1][1];
					if(dp[f][j][l][1]>=mod) dp[f][j][l][1]-=mod;
					dp[f][j][l][1]+=dp[f^1][j-1][l-1][0];
					if(dp[f][j][l][1]>=mod) dp[f][j][l][1]-=mod;
				}
			}
		}
	}
	printf("%d\n",(dp[f][m][k][0]+dp[f][m][k][1])%mod);
	return 0;
}

