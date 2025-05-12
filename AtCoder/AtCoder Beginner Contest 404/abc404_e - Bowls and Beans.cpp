#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2000+10;
int c[MAX],a[MAX],dp[MAX];
int main()
{
	int n,i,j,ans,ok;
	scanf("%d",&n);
	for(i=1;i<n;i++) scanf("%d",&c[i]);
	for(i=1;i<n;i++) scanf("%d",&a[i]);
	dp[0]=0;
	for(i=1;i<n;i++)
	{
		dp[i]=INF;
		for(j=i-c[i];j<=i-1;j++)
		{
			if(a[j]) dp[i]=1;
			else dp[i]=min(dp[i],dp[j]+1);
		}
//		cout<<i<<" "<<dp[i]<<endl;
	}
	ans=0;
	for(i=1;i<n;i++) ans+=a[i]*dp[i];
	printf("%d\n",ans);
	return 0;
}
