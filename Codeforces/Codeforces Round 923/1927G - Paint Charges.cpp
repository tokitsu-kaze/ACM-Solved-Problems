#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int a[105],dp[105];
int main()
{
	int t,n,i,j,k,l;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		memset(dp,0x3f,sizeof dp);
		dp[0]=0;
		for(i=1;i<=n;i++)
		{
			for(j=max(i-a[i]+1,1);j<=i;j++) dp[i]=min(dp[i],dp[j-1]+1);
			for(j=1;j<i;j++)
			{
				if(j+a[j]-1<i) continue;
				dp[i]=min(dp[i],dp[j-1]+1);
				for(k=j-1;k<=i;k++)
				{
					if(k==j) continue;
					for(l=max(k-a[k]+1,1);l<=j;l++) dp[i]=min(dp[i],dp[l-1]+2);
				}
			}
	//		printf("%d %d\n",i,dp[i]);
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}
/*
3
20
1 1 1 1 6 1 7 1 1 1  1 1 1 1 6 1 7 1 1 1
7
1 1 1 4 1 1 1
34
7 6 1 2 2 13 1 10 3 15   4 3 7 8 3 4 11 6 7 15   12 9 9 4 7 10 8 7 3 5 13 1 2 5
*/
