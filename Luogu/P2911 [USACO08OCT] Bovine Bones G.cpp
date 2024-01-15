#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=80+10;
int dp[4][MAX];
int main()
{
	int s[4],sum,mx,pos;
	int i,j,k;
	scanf("%d%d%d",&s[1],&s[2],&s[3]);
	memset(dp,0,sizeof dp);
	dp[0][0]=1;
	sum=0;
	for(i=1;i<=3;i++)
	{
		for(j=0;j<=sum;j++)
		{
			dp[i][j+1]+=dp[i-1][j];
			dp[i][j+s[i]+1]-=dp[i-1][j];
		}
		sum+=s[i];
		for(j=1;j<=sum;j++)
		{
			dp[i][j]+=dp[i][j-1];
		}
	}
	mx=pos=0;
	for(i=1;i<=sum;i++)
	{
		if(mx<dp[3][i])
		{
			mx=dp[3][i];
			pos=i;
		}
	}
	printf("%d\n",pos);
	return 0;
}

