#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=(1<<22)+10;
int a[MAX],dp[MAX];
int main()
{
	int n,i,j;
	scanf("%d",&n);
	memset(dp,-1,sizeof dp);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		dp[a[i]]=a[i];
	}
	for(i=0;i<(1<<22);i++)
	{
		for(j=0;j<22;j++)
		{
			if(((i>>j)&1) && dp[i^(1<<j)]!=-1) dp[i]=dp[i^(1<<j)];
		}
	}
	for(i=1;i<=n;i++) printf("%d%c",dp[((1<<22)-1)^a[i]]," \n"[i==n]);
	return 0;
}
