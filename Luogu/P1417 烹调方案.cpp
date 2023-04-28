#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
struct node{ll a,b,c;}a[55];
ll dp[MAX];
int main()
{
	int t,n,i,j;
	ll ans;
	scanf("%d%d",&t,&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i].a);
	for(i=1;i<=n;i++) scanf("%lld",&a[i].b);
	for(i=1;i<=n;i++) scanf("%lld",&a[i].c);
	sort(a+1,a+1+n,[&](node x,node y){
		return x.c*y.b<y.c*x.b;
	});
	memset(dp,0,sizeof dp);
	for(i=1;i<=n;i++)
	{
		for(j=t;j>=a[i].c;j--)
		{
			dp[j]=max(dp[j],dp[j-a[i].c]+a[i].a-j*a[i].b);
		}
	}
	ans=0;
	for(i=0;i<=t;i++) ans=max(ans,dp[i]);
	printf("%lld\n",ans);
	return 0;
}
