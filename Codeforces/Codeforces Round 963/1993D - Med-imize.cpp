#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int a[MAX],v[MAX],n,k,dp[MAX];
int ck(int x)
{
	int i;
	for(i=1;i<=n;i++) v[i]=(a[i]>=x?1:-1);
	dp[0]=0;
	for(i=1;i<=n;i++)
	{
		dp[i]=-INF;
		if(i-k>=0) dp[i]=max(dp[i],dp[i-k]);
		if(i%k==1) dp[i]=max(dp[i],v[i]);
		else dp[i]=max(dp[i],dp[i-1]+v[i]);
	}
	return dp[n]>0;
}
int main()
{
	int T,i,l,r,mid;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		l=1;
		r=1e9;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid+1)) l=mid+1;
			else r=mid;
		}
		printf("%d\n",l);
	}
	return 0;
}

