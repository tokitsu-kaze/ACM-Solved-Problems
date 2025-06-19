#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],dp[MAX];
int main()
{
	int T,n,i,pos,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		a[0]=-1;
		dp[0]=0;
		ans=0;
		for(i=1;i<=n;i++)
		{
			pos=lower_bound(a,a+1+i,a[i]-1)-a-1;
			dp[i]=dp[pos]+1;
			ans=max(ans,dp[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
