#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2000+10;
int a[MAX];
ll dp[MAX];
int main()
{
	int n,i,j;
	ll s;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	dp[0]=0;
	for(i=1;i<=n;i++)
	{
		dp[i]=LLINF;
		s=0;
		for(j=i;j;j--)
		{
			s+=a[j];
			dp[i]=min(dp[i],dp[j-1]+s*s);
		}
	}
	printf("%lld\n",dp[n]);
	return 0;
}
