#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=3e4+10;
vector<int> pos[MAX];
int dp[MAX];
int main()
{
	int n,i,l,r;
	scanf("%d",&n);
	for(i=0;i<MAX;i++)
	{
		pos[i].clear();
		dp[i]=0;
	}
	while(n--)
	{
		scanf("%d%d",&l,&r);
		l++;
		r++;
		pos[r].push_back(l);
	}
	n=3e4+1;
	for(i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		for(auto &it:pos[i]) dp[i]=max(dp[i],dp[it]+i-it);
	}
	printf("%d\n",dp[n]);
	return 0;
}
