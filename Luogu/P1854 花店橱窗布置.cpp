#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int a[105][105];
int dp[105][105],pre[105][105];
int main()
{
	int n,m,i,j,k,ans,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	memset(dp,-0x3f,sizeof dp);
	memset(pre,0,sizeof pre);
	for(i=1;i<=m;i++) dp[1][i]=a[1][i];
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			for(k=1;k<=j-1;k++)
			{
				if(dp[i-1][k]+a[i][j]>dp[i][j])
				{
					dp[i][j]=dp[i-1][k]+a[i][j];
					pre[i][j]=k;
				}
			}
		}
	}
	ans=-INF;
	for(i=n;i<=m;i++)
	{
		if(dp[n][i]>ans)
		{
			ans=dp[n][i];
			y=i;
		}
	}
	x=n;
	vector<int> res;
	while(x>0)
	{
		res.push_back(y);
		y=pre[x][y];
		x--;
	}
	reverse(res.begin(),res.end());
	printf("%d\n",ans);
	for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i==res.size()-1]);
	return 0;
}

