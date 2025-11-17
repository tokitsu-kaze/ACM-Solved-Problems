#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int dp[MAX][2],a[MAX],mx[MAX];
int main()
{
	int T,n,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		memset(dp[n+1],0,sizeof dp[n+1]);
		mx[n+1]=0;
		for(i=n;i;i--)
		{
			if(i+a[i]+1>n+1)
			{
				dp[i][0]=0;
				dp[i][1]=mx[i+1]+1;
			}
			else
			{
				if(i+a[i]==n) dp[i][0]=1;
				else if(dp[i+a[i]+1][0]>0) dp[i][0]=dp[i+a[i]+1][0]+1;
				else dp[i][0]=0;
				dp[i][1]=max(dp[i+a[i]+1][1],mx[i+1])+1;
			}
			mx[i]=max(mx[i+1],dp[i][0]);
//			printf("%d %d %d\n",i,dp[i][0],dp[i][1]);
		}
		for(i=1;i<n;i++)
		{
			ans=2;
			if(dp[i+1][0]==a[i]) ans=0;
			else
			{
				if(dp[i+1][1]>=a[i]) ans=1;
				else if(dp[i+1][0]>0) ans=1;
			}
			printf("%d%c",ans," \n"[i==n-1]);
		}
	}
	return 0;
}
/*
主要的问题在于想知道后缀能形成哪些组数，这样就是O(n^2)dp了
发现组数在1..max都能取到，因为转移时是连续的
dp[i][j]表示后缀i..n修改j次后形成若干组testcase的最大组数
最终答案根据dp数组分讨一下，只有0，1，2
*/
