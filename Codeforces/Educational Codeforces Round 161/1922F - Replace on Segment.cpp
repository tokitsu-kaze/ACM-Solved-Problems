#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
int dp[105][105][105],g[105][105][105],a[105];
int main()
{
	int t,n,m,i,j,k,l,r,len,mid,cost,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<=m;i++)
		{
			for(j=0;j<=n;j++)
			{
				for(k=0;k<=n;k++)
				{
					dp[i][j][k]=g[i][j][k]=INF;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			for(k=1;k<=m;k++)
			{
				dp[k][i][i]=1;
				g[k][i][i]=0;
			}
			dp[a[i]][i][i]=0;
			g[a[i]][i][i]=1;
		}
		for(len=2;len<=n;len++)
		{
			for(l=1;l+len-1<=n;l++)
			{
				r=l+len-1;
				for(i=1;i<=m;i++)
				{
					if(a[l]!=i) g[i][l][r]=min(g[i][l][r],g[i][l+1][r]);
					if(a[r]!=i) g[i][l][r]=min(g[i][l][r],g[i][l][r-1]);
					for(mid=l;mid<r;mid++)
					{
						dp[i][l][r]=min(dp[i][l][r],dp[i][l][mid]+dp[i][mid+1][r]);
						g[i][l][r]=min(g[i][l][r],g[i][l][mid]+g[i][mid+1][r]);
					}
					dp[i][l][r]=min(dp[i][l][r],g[i][l][r]+1);
					for(j=1;j<=m;j++)
					{
						if(i==j) continue;
						g[j][l][r]=min(g[j][l][r],dp[i][l][r]);
					}
				}
			}
		}
		ans=INF;
		for(i=1;i<=m;i++) ans=min(ans,dp[i][1][n]);
		printf("%d\n",ans);
	}
	return 0;
}
