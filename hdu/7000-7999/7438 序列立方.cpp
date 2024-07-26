#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=250+2;
const int mod=998244353;
int a[MAX],dp[MAX][MAX][MAX],bit[MAX][MAX][MAX];
int main()
{
	int n,i,j,k,x,y,z;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(dp,0,sizeof dp);
	memset(bit,0,sizeof bit);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				if(a[i]==a[j]&&a[j]==a[k])
				{
					dp[i][j][k]+=bit[i-1][j-1][k-1]+1;
					if(dp[i][j][k]>=mod) dp[i][j][k]-=mod;
				}
				bit[i][j][k]=((ll)bit[i-1][j][k]+bit[i][j-1][k]+bit[i][j][k-1]
							-bit[i-1][j-1][k]-bit[i-1][j][k-1]-bit[i][j-1][k-1]
							+bit[i-1][j-1][k-1]+dp[i][j][k])%mod;
				if(bit[i][j][k]<0) bit[i][j][k]+=mod;
			}
		}
	}
	printf("%d\n",bit[n][n][n]);
	return 0;
}
