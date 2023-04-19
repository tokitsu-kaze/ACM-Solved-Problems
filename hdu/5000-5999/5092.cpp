#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int mp[111][111],dp[111][111];
int pre[111][111];
int main()
{
	int t,cas=1,i,j,n,m,tmp,x,y,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(dp,0x3f,sizeof dp);
		dp[0][0]=0;
		for(i=1;i<=n;i++) dp[i][0]=0;
		for(i=1;i<=m;i++) dp[0][i]=0;
		memset(pre,0,sizeof pre);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}
		printf("Case %d\n",cas++);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(j>1)
				{
					tmp=dp[i-1][j-1]+mp[i][j];
					if(tmp<=dp[i][j])
					{
						dp[i][j]=tmp;
						pre[i][j]=j-1;
					}
				}
				tmp=dp[i-1][j]+mp[i][j];
				if(tmp<=dp[i][j])
				{
					dp[i][j]=tmp;
					pre[i][j]=j;
				}
				if(j<m)
				{
					tmp=dp[i-1][j+1]+mp[i][j];
					if(tmp<=dp[i][j])
					{
						dp[i][j]=tmp;
						pre[i][j]=j+1;
					}
				}
			}
		}
		ans=INF;
		x=n;
		for(i=1;i<=m;i++)
		{
			if(dp[n][i]<=ans)
			{
				ans=dp[n][i];
				y=i;
			}
		}
		vector<int> res;
		while(x&&y)
		{
			res.push_back(y);
			y=pre[x][y];
			x--;
		}
		reverse(res.begin(),res.end());
		for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i==res.size()-1]);
	}
	return 0;
}
