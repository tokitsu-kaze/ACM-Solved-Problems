#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int dp[MAX],a[3010];
int main()
{
	int n,i,j,K,ans,sum;
	scanf("%d",&n);
	sum=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if(n<=20) K=5000*n;
	else if(n<=200) K=5000*10;
	else K=5000*2;
	for(i=1;i<=K;i++) dp[i]=0;
	dp[0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=K;j>=a[i];j--)
		{
			dp[j]+=dp[j-a[i]];
			dp[j]=min(dp[j],2);
		}
	}
	ans=-1;
	for(i=1;i<=min(K+1,sum/2)-1;i++)
	{
		if(dp[i]>=2)
		{
			ans=sum-2*i;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
