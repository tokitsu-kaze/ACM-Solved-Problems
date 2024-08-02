#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e4+10;
vector<int> pos[MAX];
int dp[MAX];
int main()
{
	int n,k,i,p,t;
	scanf("%d%d",&n,&k);
	for(i=0;i<=n;i++) pos[i].clear();
	while(k--)
	{
		scanf("%d%d",&p,&t);
		pos[p].push_back(p+t);
	}
	dp[n+1]=0;
	for(i=n;i;i--)
	{
		if(pos[i].size()==0) dp[i]=dp[i+1]+1;
		else dp[i]=0;
		for(auto &it:pos[i]) dp[i]=max(dp[i],dp[it]);
	}
	printf("%d\n",dp[1]);
	return 0;
}
