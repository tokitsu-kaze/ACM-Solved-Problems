#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=500+10;
int dp[MAX][MAX],a[MAX],dp2[MAX];
int main()
{
	int n,i,j,len,l,r;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(dp,0,sizeof dp);
	for(i=1;i<=n;i++) dp[i][i]=a[i];
	for(len=2;len<=n;len++)
	{
		for(l=1;l+len-1<=n;l++)
		{
			r=l+len-1;
			for(i=l;i<r;i++)
			{
				if(!dp[l][i]) continue;
				if(!dp[i+1][r]) continue;
				if(dp[l][i]==dp[i+1][r])
				{
					dp[l][r]=dp[l][i]+1;
					break;
				}
			}
		}
	}
	memset(dp2,0x3f,sizeof dp2);
	dp2[0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=i-1;~j;j--)
		{
			if(dp[j+1][i]==0) continue;
			dp2[i]=min(dp2[i],dp2[j]+1);
		}
	}
	printf("%d\n",dp2[n]);
	return 0;
}
/*
比较典的题。
有个性质是，如果能合成一个数，那么这个数是唯一的。
我们考虑求出那些能合成一个数的区间，然后再做线性dp。
*/
