#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=5e5+10;
const int delta=5e5;
int dp[2][MAX*2];
int main()
{
	int n,i,j,x,f,sum;
	scanf("%d",&n);
	f=0;
	memset(dp,-0x3f,sizeof dp);
	dp[f][delta]=0;
	sum=0;
	for(i=1;i<=n;i++)
	{
		f^=1;
		scanf("%d",&x);
		sum+=x;
		for(j=-sum+delta;j<=sum+delta;j++)
		{
			dp[f][j]=dp[f^1][j];
			if(j+x<=2*delta) dp[f][j]=max(dp[f][j],dp[f^1][j+x]+x);
			if(j-x>=0) dp[f][j]=max(dp[f][j],dp[f^1][j-x]+x);
		}
	}
	if(dp[f][delta]>0) printf("%d\n",dp[f][delta]/2);
	else puts("-1");
	return 0;
}
