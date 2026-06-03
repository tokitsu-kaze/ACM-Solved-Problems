#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=80+10;
mt19937 rd(time(0));
int mp[MAX][MAX],dp[12][MAX],col[MAX];
int main()
{
	int n,k,i,j,x,y,LIMT,ans;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++) scanf("%d",&mp[i][j]);
	}
	LIMT=5000;
	ans=INF;
	while(LIMT--)
	{
		for(i=1;i<=n;i++) col[i]=rd()%2;
		memset(dp,0x3f,sizeof dp);
		dp[0][1]=0;
		for(i=1;i<=k;i++)
		{
			for(x=1;x<=n;x++)
			{
				for(y=1;y<=n;y++)
				{
					if(col[x]==col[y]) continue;
					dp[i][y]=min(dp[i][y],dp[i-1][x]+mp[x][y]);
				}
			}
		}
		ans=min(ans,dp[k][1]);
	}
	printf("%d\n",ans);
	return 0;
}
/*
没有奇环说明是二分图，
但没想到随机染色然后直接跑类似floyd的dp即可。
*/
