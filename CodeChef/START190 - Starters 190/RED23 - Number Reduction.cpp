#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,x,i,dp[205];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&x);
		memset(dp,0,sizeof dp);
		dp[x]=1;
		for(i=x;i;i--)
		{
			dp[i]|=dp[i+3];
			dp[i]|=dp[i*2];
		}
		for(i=1;;i++)
		{
			if(dp[i])
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}

