#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int dp[MAX][3][2],v[MAX][3];
int main()
{
	int n,i,j,k,z,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&v[i][j]);
		}
	}
	ans=0;
	for(z=0;z<3;z++)
	{
		memset(dp[1],0,sizeof dp[1]);
		for(j=0;j<3;j++)
		{
			if(j==z) continue;
			else dp[1][j][j>z]=v[1][j];
		}
		for(i=2;i<n;i++)
		{
			memset(dp[i],0,sizeof dp[i]);
			for(j=0;j<3;j++) // now
			{
				for(k=0;k<3;k++) // pre
				{
					if(j==k) continue;
					dp[i][j][j>k]=max(dp[i][j][j>k],
									  dp[i-1][k][k>j]+v[i][j]);
				}
			}
		}
		for(j=0;j<3;j++)
		{
			if(j==z) continue;
			ans=max(ans,dp[n-1][j][j>z]+v[n][z]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
6
1 3 2
3 1 2
1 2 3
1 3 2
2 1 3
2 3 2
*/
