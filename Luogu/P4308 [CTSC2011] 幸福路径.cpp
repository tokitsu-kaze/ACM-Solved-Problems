#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e6+10;
const int LIMT=30;
double dp[LIMT+5][105][105];
int main()
{
	int n,m,i,j,k,stp,a,b,s;
	double v[105],p;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%lf",&v[i]);
	scanf("%d",&s);
	scanf("%lf",&p);
	memset(dp,0xc2,sizeof dp);
	for(i=1;i<=n;i++) dp[0][i][i]=0;
	while(m--)
	{
		scanf("%d%d",&a,&b);
		dp[0][a][b]=v[b]*p;
	}
	for(stp=1;stp<=LIMT;stp++)
	{
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				if(dp[stp-1][i][k]<0) continue;
				for(j=1;j<=n;j++)
				{
					if(dp[stp-1][k][j]<0) continue;
					dp[stp][i][j]=max(dp[stp][i][j],
					  dp[stp-1][i][k]+dp[stp-1][k][j]*p);
				}
			}
		}
		p*=p;
	}
	printf("%.1f\n",*max_element(dp[LIMT][s]+1,dp[LIMT][s]+1+n)+v[s]);
	return 0;
}
