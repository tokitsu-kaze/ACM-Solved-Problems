#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int main()
{
	int T,n,i,j,a[105],dp[105],ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		memset(dp,0,sizeof dp);
		for(i=1;i<=n;i++)
		{
			dp[i]=1;
			for(j=1;j<i;j++)
			{
				if((a[j]&a[i])==a[j]) dp[i]=max(dp[i],dp[j]+1);
			}
		}
		ans=0;
		for(i=1;i<=n;i++) ans=max(ans,dp[i]);
		printf("%d\n",ans);
	}
	return 0;
}
