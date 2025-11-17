#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node{int l,r,id;}a[MAX];
ll dp[MAX][2];
int main()
{
	int T,n,i,j,l,r,cnt,mx;
	ll ans,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		now=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&l,&r);
			now+=r-2LL*l;
			a[i]={l,r,i};
		}
		sort(a+1,a+1+n,[](node x,node y){
			if(x.l+x.r==y.l+y.r) return x.l>y.l;
			return x.l+x.r>y.l+y.r;
		});
		dp[0][0]=0;
		dp[0][1]=-LLINF;
		for(i=1;i<=(n+1)/2;i++)
		{
			dp[i][0]=dp[i-1][0]+a[i].l+a[i].r;
			dp[i][1]=max(dp[i-1][1]+a[i].l+a[i].r,dp[i-1][0]+a[i].l);
		}
		mx=0;
		for(i=(n+1)/2;i<=n;i++) mx=max(mx,a[i].l);
		if(n%2==0) ans=dp[n/2][0];
		else
		{
			ans=dp[(n+1)/2][1];
			ans=max(ans,dp[n/2][0]+mx);
		}
		printf("%lld\n",ans+now);
	}
	return 0;
}
