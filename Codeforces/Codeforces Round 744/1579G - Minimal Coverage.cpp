#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e4+10;
int a[MAX],dp[2][2020];
int main()
{
	int T,n,i,j,f,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		f=0;
		memset(dp[f],0x3f,sizeof dp[f]);
		dp[f][0]=0;
		for(i=1;i<=n;i++)
		{
			f^=1;
			memset(dp[f],0x3f,sizeof dp[f]);
			for(j=0;j<=2000;j++)
			{
				dp[f][max(j-a[i],0)]=min(dp[f][max(j-a[i],0)],dp[!f][j]+a[i]);
				if(j+a[i]<=2000) dp[f][j+a[i]]=min(dp[f][j+a[i]],max(dp[!f][j]-a[i],0));
			}
		}
		ans=INF;
		for(j=0;j<=2000;j++) ans=min(ans,dp[f][j]+j);
		printf("%d\n",ans);
	}
	return 0;
}
/*
显然答案不超过 2V=2000，发现可能是一个O(nV)dp。
这里状态设计比较有趣，
dp[i][j]表示考虑了前i条线段，离左端点距离为j，离右端点距离的最小值。
这个状态可以同时表示结尾和左端点。
转移就是看往左放还是往右放了。
*/
