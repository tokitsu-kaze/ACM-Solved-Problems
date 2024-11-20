#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=(1<<16)+10;
int sumw[MAX],mxt[MAX],dp[MAX],w[17],t[17];
int main()
{
	int W,n,i,j;
	scanf("%d%d",&W,&n);
	for(i=0;i<n;i++) scanf("%d%d",&t[i],&w[i]);
	for(i=0;i<(1<<n);i++)
	{
		sumw[i]=mxt[i]=0;
		for(j=0;j<n;j++)
		{
			if(!((i>>j)&1)) continue;
			sumw[i]+=w[j];
			mxt[i]=max(mxt[i],t[j]);
		}
	}
	dp[0]=0;
	for(i=1;i<(1<<n);i++)
	{
		dp[i]=INF;
		for(j=i;j;j=(j-1)&i)
		{
			if(sumw[j]<=W) dp[i]=min(dp[i],dp[i^j]+mxt[j]);
		}
	}
	printf("%d\n",dp[(1<<n)-1]);
	return 0;
}
