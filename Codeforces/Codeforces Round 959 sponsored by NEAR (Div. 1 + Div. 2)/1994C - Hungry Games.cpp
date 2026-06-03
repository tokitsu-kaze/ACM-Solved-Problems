#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],dp[MAX];
int main()
{
	int T,n,x,i,j;
	ll now,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&x);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		dp[n+1]=0;
		now=0;
		ans=1LL*n*(n+1)/2;
		for(i=n,j=n;i;i--)
		{
			now+=a[i];
			while(now>x)
			{
				now-=a[j];
				j--;
			}
			if(j<n)
			{
				j++;
				now+=a[j];
			}
			if(now>x) dp[i]=dp[j+1]+1;
			else dp[i]=0;
			ans-=dp[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
不为0感觉不好做，考虑总的减去为0的。
考虑枚举左端点，统计有多少个右端点。
发现右端点可以从右往左dp过来。
每次双指针找到最短区间。
*/
