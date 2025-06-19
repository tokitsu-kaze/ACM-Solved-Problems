#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
const int mod=1e9+7;
int dp[MAX],mn[MAX];
const int fm=1e5;
int main()
{
	int op,y,n,m,i,j;
	ll x,nex;
	memset(dp,-1,sizeof dp);
	dp[0]=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d%lld%d",&op,&x,&y);
		for(j=0;j<=m;j++)
		{
			if(dp[j]==-1) mn[j]=INF;
			else mn[j]=0;
		}
		if(op==1)
		{
			x=(x+fm-1)/fm;
			for(j=x;j<=m;j++) mn[j]=min(mn[j],mn[j-x]+1);
		}
		else
		{
			for(j=1;j<=m;j++)
			{
				nex=(j*x+fm-1)/fm;
				if(nex>m) break;
				mn[nex]=min(mn[nex],mn[j]+1);
			}
		}
		for(j=1;j<=m;j++)
		{
			if(dp[j]==-1 && mn[j]<=y) dp[j]=i;
		}
	}
	for(i=1;i<=m;i++) printf("%d%c",dp[i]," \n"[i==m]);
	return 0;
}
