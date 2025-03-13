#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
int dp[MAX],cnt[MAX],a[MAX];
int main()
{
	int T,n,i,j,mex;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<=n;i++)
		{
			cnt[i]=0;
			dp[i]=INF;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]<=n) cnt[a[i]]++;
		}
		for(i=0;i<=n;i++)
		{
			if(cnt[i]==0)
			{
				mex=i;
				break;
			}
		}
		dp[mex]=0;
		for(i=mex;i;i--)
		{
			for(j=0;j<i;j++)
			{
				dp[j]=min(dp[j],dp[i]+(cnt[j]-1)*i+j);
			}
		}
		printf("%d\n",dp[0]);
	}
	return 0;
}
