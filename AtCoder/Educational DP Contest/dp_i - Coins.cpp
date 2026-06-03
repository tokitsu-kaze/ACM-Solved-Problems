#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3000+10;
const int D=3005;
double dp[2][2*MAX],p[MAX];
int main()
{
	int n,i,j,f;
	double ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lf",&p[i]);
	f=0;
	memset(dp[f],0,sizeof dp[f]);
	dp[f][D]=1;
	for(i=1;i<=n;i++)
	{
		f^=1;
		memset(dp[f],0,sizeof dp[f]);
		for(j=-i+D;j<=i+D;j++)
		{
			dp[f][j]=dp[!f][j-1]*p[i]+dp[!f][j+1]*(1-p[i]);
		}
	}
	ans=0;
	for(j=1+D;j<=n+D;j++) ans+=dp[f][j];
	printf("%.10f\n",ans);
	return 0;
}
