#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
double dp[630][630];
int main()
{
	int n,i,j;
	scanf("%d",&n);
	n/=2;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++) dp[i][j]=0;
	}
	for(i=2;i<=n;i++) dp[i][0]=dp[0][i]=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			dp[i][j]=(dp[i-1][j]+dp[i][j-1])/2;
		}
	}
	printf("%.4f\n",dp[n][n]);
	return 0;
}
