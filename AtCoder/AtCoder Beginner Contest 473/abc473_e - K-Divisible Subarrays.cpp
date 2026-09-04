#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int dp[MAX];
int main()
{
	int n,k,i,x,sum;
	scanf("%d%d",&n,&k);
	map<int,int> lst;
	sum=0;
	dp[0]=0;
	lst[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		dp[i]=dp[i-1];
		sum=(sum+x)%k;
		if(lst.count(sum)) dp[i]=max(dp[i],dp[lst[sum]]+1);
		lst[sum]=i;
	}
//	for(i=1;i<=n;i++) printf("%d %d\n",i,dp[i]);
	printf("%d\n",dp[n]);
	return 0;
}
