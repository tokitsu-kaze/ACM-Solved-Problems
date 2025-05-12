#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
int mp[MAX][MAX],a[MAX],b[MAX];
ll dp[MAX][2];
int main()
{
	int T,n,i,j,d[3],tmp;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++) scanf("%d",&mp[i][j]);
		}
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		ans=0;
		dp[1][0]=0;
		dp[1][1]=a[1];
		for(i=2;i<=n;i++)
		{
			memset(d,0,sizeof d);
			memset(dp[i],0x3f,sizeof dp[i]);
			for(j=1;j<=n;j++)
			{
				tmp=mp[i][j]-mp[i-1][j];
				if(tmp>=-1 && tmp<=1) d[tmp+1]=1;
			}
			// 1 0   1 1   0 1
			if(d[0] && d[1] && d[2]) continue;
			if(d[0] && d[1])
			{
				// 1 0   1 1
				// 2 0   2 1
				dp[i][0]=min(dp[i][0],dp[i-1][1]);
			}
			else if(d[0] && d[2])
			{
				// 1 0   0 1
				dp[i][0]=min(dp[i][0],dp[i-1][0]);
				// 2 0   1 1
				dp[i][1]=min(dp[i][1],dp[i-1][1]+a[i]);
			}
			else if(d[1] && d[2])
			{
				// 1 1   0 1
				dp[i][1]=min(dp[i][1],dp[i-1][0]+a[i]);
				// 2 1   1 1
			}
			else if(d[0])
			{
				// 1 0
				dp[i][0]=min(dp[i][1],dp[i-1][0]);
				// 2 0
				dp[i][0]=min(dp[i][0],dp[i-1][1]);
				dp[i][1]=min(dp[i][1],dp[i-1][1]+a[i]);
			}
			else if(d[1])
			{
				// 1 1
				dp[i][1]=min(dp[i][1],dp[i-1][0]+a[i]);
				// 2 1
				dp[i][0]=min(dp[i][0],dp[i-1][1]);
			}
			else if(d[2])
			{
				// 0 1
				dp[i][0]=min(dp[i][0],dp[i-1][0]);
				dp[i][1]=min(dp[i][1],dp[i-1][0]+a[i]);
				// 1 1
				dp[i][1]=min(dp[i][1],dp[i-1][1]+a[i]);
			}
			else
			{
				dp[i][0]=min(dp[i-1][0],dp[i-1][1]);
				dp[i][1]=min(dp[i-1][0],dp[i-1][1])+a[i];
			}
//			cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
//			cout<<d[0]<<" "<<d[1]<<" "<<d[2]<<endl;
		}
		ans+=min(dp[n][0],dp[n][1]);
		
		dp[1][0]=0;
		dp[1][1]=b[1];
		for(i=2;i<=n;i++)
		{
			memset(d,0,sizeof d);
			memset(dp[i],0x3f,sizeof dp[i]);
			for(j=1;j<=n;j++)
			{
				tmp=mp[j][i]-mp[j][i-1];
				if(tmp>=-1 && tmp<=1) d[tmp+1]=1;
			}
			// 1 0   1 1   0 1
			if(d[0] && d[1] && d[2]) continue;
			if(d[0] && d[1])
			{
				// 1 0   1 1
				// 2 0   2 1
				dp[i][0]=min(dp[i][0],dp[i-1][1]);
			}
			else if(d[0] && d[2])
			{
				// 1 0   0 1
				dp[i][0]=min(dp[i][0],dp[i-1][0]);
				// 2 0   1 1
				dp[i][1]=min(dp[i][1],dp[i-1][1]+b[i]);
			}
			else if(d[1] && d[2])
			{
				// 1 1   0 1
				dp[i][1]=min(dp[i][1],dp[i-1][0]+b[i]);
				// 2 1   1 1
			}
			else if(d[0])
			{
				// 1 0
				dp[i][0]=min(dp[i][1],dp[i-1][0]);
				// 2 0
				dp[i][0]=min(dp[i][0],dp[i-1][1]);
				dp[i][1]=min(dp[i][1],dp[i-1][1]+b[i]);
			}
			else if(d[1])
			{
				// 1 1
				dp[i][1]=min(dp[i][1],dp[i-1][0]+b[i]);
				// 2 1
				dp[i][0]=min(dp[i][0],dp[i-1][1]);
			}
			else if(d[2])
			{
				// 0 1
				dp[i][0]=min(dp[i][0],dp[i-1][0]);
				dp[i][1]=min(dp[i][1],dp[i-1][0]+b[i]);
				// 1 1
				dp[i][1]=min(dp[i][1],dp[i-1][1]+b[i]);
			}
			else
			{
				dp[i][0]=min(dp[i-1][0],dp[i-1][1]);
				dp[i][1]=min(dp[i-1][0],dp[i-1][1])+b[i];
			}
//			cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
//			cout<<d[0]<<" "<<d[1]<<" "<<d[2]<<endl;
		}
		ans+=min(dp[n][0],dp[n][1]);
		
		if(ans>=LLINF) ans=-1;
		printf("%lld\n",ans);
	}
	return 0;
}


