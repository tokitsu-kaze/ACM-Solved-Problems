#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e5+10;
int a[MAX],dp[MAX][3],pre[MAX];
int main()
{
	int n,i,ans,mx,nmx;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(dp,-0x3f,sizeof dp);
	memset(pre,0,sizeof pre);
	mx=nmx=0;
	dp[0][0]=0;
	for(i=1;i<=n;i++)
	{
		dp[i][0]=max(dp[i-1][0],dp[i-1][2]);
		dp[i][2]=max(0,dp[pre[a[i]]][1]+1);
		if(a[i]!=a[mx]) dp[i][1]=dp[mx][2]+1;
		else dp[i][1]=dp[nmx][2]+1;
		dp[i][1]=max(dp[i][1],1);
		if(dp[i][2]>dp[mx][2])
		{
			if(a[i]==a[mx]) mx=i;
			else
			{
				nmx=mx;
				mx=i;
			}
		}
		else if(dp[i][2]>dp[nmx][2])
		{
			if(a[i]!=a[mx]) nmx=i;
		}
		pre[a[i]]=i;
//		printf("%d %d %d %d %d %d\n",i,mx,nmx,dp[i][0],dp[i][1],dp[i][2]);
	}
	printf("%d\n",max(dp[n][0],dp[n][2]));
	return 0;
}
/*
5
1 1 2 1 1
6
1 1 2 2 1 1
*/
