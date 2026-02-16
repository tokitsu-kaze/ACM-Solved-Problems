#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int a[MAX],dp[MAX],lst[(1<<20)+10];
int main()
{
	int n,k,i,now;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(lst,-1,sizeof lst);
	memset(dp,0,sizeof dp);
	now=0;
	lst[0]=0;
	for(i=1;i<=n;i++)
	{
		now^=a[i];
		dp[i]=dp[i-1];
		if(lst[now^k]>=0) dp[i]=max(dp[i],dp[lst[now^k]]+1);
		lst[now]=i;
	}
	printf("%d\n",dp[n]);
	return 0;
}
