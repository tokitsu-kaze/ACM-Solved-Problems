#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,i,x,ans;
	scanf("%d",&n);
	map<int,int> dp;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		dp[x]=max(dp[x],1);
		if(dp.count(x-1)) dp[x]=max(dp[x],dp[x-1]+1);
	}
	ans=0;
	for(auto &it:dp) ans=max(ans,it.second);
	printf("%d\n",ans);
	return 0;
}
