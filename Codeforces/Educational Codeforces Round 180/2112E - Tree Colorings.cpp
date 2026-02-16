#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int dp[MAX];
vector<int> fac[MAX];
int main()
{
	int T,m,i,j;
	for(i=1;i<=MAX-10;i++)
	{
		for(j=i+i;j<=MAX-10;j+=i)
		{
			fac[j].push_back(i);
		}
	}
	memset(dp,-1,sizeof dp);
	dp[1]=1;
	for(i=3;i<=MAX-10;i+=2)
	{
		dp[i]=INF;
		for(auto &it:fac[i])
		{
			dp[i]=min(dp[i],dp[it]+dp[i/it-2]);
		}
	}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&m);
		printf("%d\n",dp[m]);
	}
	return 0;
}
