#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3000+10;
int dp[MAX][MAX],a[MAX],b[MAX];
int main()
{
	int n,x,y,i,j,ans,ok;
	scanf("%d%d%d",&n,&x,&y);
	for(i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	memset(dp,-0x3f,sizeof dp);
	dp[0][x]=y;
	ans=0;
	for(i=1;i<=n;i++)
	{
		ok=0;
		for(j=0;j<=x;j++)
		{
			if(j+a[i]<=x) dp[i][j]=max(dp[i][j],dp[i-1][j+a[i]]);
			dp[i][j]=max(dp[i][j],dp[i-1][j]-b[i]);
			if(dp[i][j]>=0) ok=1;
		}
		if(ok) ans=i;
		else break;
	}
	printf("%d\n",ans);
	return 0;
}
