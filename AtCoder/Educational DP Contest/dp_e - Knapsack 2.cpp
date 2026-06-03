#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int V=1e5;
const int MAX=V+10;
ll dp[MAX];
int main()
{
	int n,W,i,j,w,v,ans;
	scanf("%d%d",&n,&W);
	memset(dp,0x3f,sizeof dp);
	dp[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&w,&v);
		for(j=V;j>=v;j--) dp[j]=min(dp[j],dp[j-v]+w);
	}
	ans=0;
	for(j=V;j;j--)
	{
		if(dp[j]<=W)
		{
			ans=j;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
