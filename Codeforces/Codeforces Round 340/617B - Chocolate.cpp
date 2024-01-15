#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int main()
{
	int n,i,j,a[105],cnt;
	ll dp[105];
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(dp,0,sizeof dp);
	dp[0]=1;
	for(i=1;i<=n;i++)
	{
		cnt=0;
		for(j=i;j;j--)
		{
			cnt+=a[j];
			if(cnt>1) break;
			if(cnt==1) dp[i]+=dp[j-1];
		}
	}
	printf("%lld\n",dp[n]);
	return 0;
}
