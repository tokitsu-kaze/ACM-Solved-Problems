#include <bits/stdc++.h>
using namespace std;
const int MAX=2e4+10;
bool dp[MAX];
int main()
{
	int n,v,i,j,w;
	memset(dp,0,sizeof dp);
	scanf("%d",&v);
	scanf("%d",&n);
	dp[0]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&w);
		for(j=v;j>=w;j--) dp[j]|=dp[j-w];
	}
	for(i=v;~i;i--)
	{
		if(dp[i])
		{
			printf("%d\n",v-i);
			break;
		}
	}
	return 0;
}

