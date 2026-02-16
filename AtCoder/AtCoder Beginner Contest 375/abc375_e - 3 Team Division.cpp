#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[105],b[105],dp[2][505][505];
int main()
{
	int n,i,x,y,f,sum;
	scanf("%d",&n);
	sum=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		sum+=b[i];
	}
	if(sum%3)
	{
		puts("-1");
		return 0;
	}
	sum/=3;
	memset(dp,0x3f,sizeof dp);
	f=0;
	dp[f][0][0]=0;
	for(i=1;i<=n;i++)
	{
		f^=1;
		for(x=0;x<=sum;x++)
		{
			for(y=0;y<=sum;y++)
			{
				dp[f][x][y]=dp[!f][x][y]+(a[i]!=3);
				if(x>=b[i]) dp[f][x][y]=min(dp[f][x][y],dp[!f][x-b[i]][y]+(a[i]!=1));
				if(y>=b[i]) dp[f][x][y]=min(dp[f][x][y],dp[!f][x][y-b[i]]+(a[i]!=2));
			}
		}
	}
	if(dp[f][sum][sum]>=INF) puts("-1");
	else printf("%d\n",dp[f][sum][sum]);
	return 0;
}
