#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
ll dp[MAX][3][2][2][2];
int a[MAX],b[MAX];
int main()
{
	int T,n,i,j,k,nexj;
	ll x,r0,r1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld",&n,&x);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		memset(dp[0],-0x3f,sizeof dp[0]);
		dp[0][0][0][0][0]=0;
		for(i=1;i<=n;i++)
		{
			memset(dp[i],-0x3f,sizeof dp[i]);
			for(j=0;j<=2;j++)
			{
				for(k=0;k<=1;k++)
				{
					dp[i][j][k][0][0]=max(dp[i-1][j][k][0][0],dp[i-1][j][k][0][1]);
					dp[i][j][k][1][0]=max(dp[i-1][j][k][1][0],dp[i-1][j][k][1][1]);
				}
			}
			dp[i][1][1][b[i]][1]=a[i];
			for(j=1;j<=2;j++)
			{
				nexj=min(j+1,2);
				if(b[i])
				{
					dp[i][nexj][0][1][1]=max(dp[i][nexj][0][1][1],dp[i-1][j][0][0][1]+a[i]);
					dp[i][nexj][0][1][1]=max(dp[i][nexj][0][1][1],dp[i-1][j][0][1][1]+a[i]);
					dp[i][nexj][0][1][1]=max(dp[i][nexj][0][1][1],dp[i-1][j][0][0][0]+a[i]);
					dp[i][nexj][0][1][1]=max(dp[i][nexj][0][1][1],dp[i-1][j][0][1][0]+a[i]);
					dp[i][nexj][0][1][1]=max(dp[i][nexj][0][1][1],dp[i-1][j][1][0][0]+a[i]);
					dp[i][nexj][0][1][1]=max(dp[i][nexj][0][1][1],dp[i-1][j][1][1][0]+a[i]);
					
					dp[i][nexj][1][1][1]=max(dp[i][nexj][1][1][1],dp[i-1][j][1][0][1]+a[i]);
					dp[i][nexj][1][1][1]=max(dp[i][nexj][1][1][1],dp[i-1][j][1][1][1]+a[i]);
				}
				else
				{
					dp[i][nexj][0][1][1]=max(dp[i][nexj][0][1][1],dp[i-1][j][0][1][1]+a[i]);
					dp[i][nexj][0][1][1]=max(dp[i][nexj][0][1][1],dp[i-1][j][0][1][0]+a[i]);
					dp[i][nexj][0][1][1]=max(dp[i][nexj][0][1][1],dp[i-1][j][1][1][0]+a[i]);
					dp[i][nexj][1][1][1]=max(dp[i][nexj][1][1][1],dp[i-1][j][1][1][1]+a[i]);
					
					dp[i][nexj][0][0][1]=max(dp[i][nexj][0][0][1],dp[i-1][j][0][0][1]+a[i]);
					dp[i][nexj][0][0][1]=max(dp[i][nexj][0][0][1],dp[i-1][j][0][0][0]+a[i]);
					dp[i][nexj][0][0][1]=max(dp[i][nexj][0][0][1],dp[i-1][j][1][0][0]+a[i]);
					dp[i][nexj][1][0][1]=max(dp[i][nexj][1][0][1],dp[i-1][j][1][0][1]+a[i]);
				}
			}
		}
		r0=max(dp[n][2][0][0][0],dp[n][2][0][0][1]);
		r1=max(dp[n][2][0][1][0],dp[n][2][0][1][1]);
		if(r0>=x || r1>=x) puts("0");
		else printf("%lld\n",x-r1);
	}
	return 0;
}
/*
dp[i][min(选了几个数,2)][当前是否是子区间][是否选择了bi=1的i][当前是否选择]
*/
