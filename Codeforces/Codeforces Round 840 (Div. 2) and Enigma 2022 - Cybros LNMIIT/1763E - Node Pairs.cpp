#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int dp[MAX];
int main()
{
	int i,j,p;
	scanf("%d",&p);
	memset(dp,0x3f,sizeof dp);
	dp[0]=0;
	dp[1]=2;
	for(i=2;i<=p;i++)
	{
		for(j=1;;j++)
		{
			if(i-j*(j-1)/2<0) break;
			dp[i]=min(dp[i],dp[i-j*(j-1)/2]+j);
		}
	}
	printf("%d %lld\n",dp[p],1LL*dp[p]*(dp[p]-1)/2-p);
	return 0;
}
