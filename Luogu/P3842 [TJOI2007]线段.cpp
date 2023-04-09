#include<bits/stdc++.h>
using namespace std;
const int MAX=2e4+10;
int dp[MAX][2];
int main()
{
	int n,i,l,r,prel,prer;
	scanf("%d",&n);
	memset(dp,0x3f,sizeof dp);
	dp[0][0]=dp[0][1]=0;
	prel=prer=1;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&l,&r);
		//从上一层的左边转移 
		if(prel>=r)
		{
			dp[i][0]=min(dp[i][0],dp[i-1][0]+prel-l);
			dp[i][1]=min(dp[i][1],dp[i-1][0]+prel-l+r-l);
		}
		else
		{
			dp[i][0]=min(dp[i][0],dp[i-1][0]+r-prel+r-l);
			if(prel<l) dp[i][1]=min(dp[i][1],dp[i-1][0]+r-prel);
			else dp[i][1]=min(dp[i][1],dp[i-1][0]+prel-l+r-l);
		}
		
		//从上一层的右边转移 
		if(prer>=r)
		{
			dp[i][0]=min(dp[i][0],dp[i-1][1]+prer-l);
			dp[i][1]=min(dp[i][1],dp[i-1][1]+prer-l+r-l);
		}
		else
		{
			dp[i][0]=min(dp[i][0],dp[i-1][1]+r-prer+r-l);
			if(prer<l) dp[i][1]=min(dp[i][1],dp[i-1][1]+r-prer);
			else dp[i][1]=min(dp[i][1],dp[i-1][1]+prer-l+r-l);
		}
		if(i<n)
		{
			//下楼要一步 
			dp[i][0]++;
			dp[i][1]++;
		}
		else
		{
			//最后要走到(n,n) 
			dp[i][0]+=n-l;
			dp[i][1]+=n-r;
		}
		prel=l;
		prer=r;
	}
/*	for(i=1;i<=n;i++)
	{
		printf("%d %d %d\n",i,dp[i][0],dp[i][1]);
	}*/
	printf("%d\n",min(dp[n][0],dp[n][1]));
	return 0;
}

