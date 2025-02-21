#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int MAX=5000+10;
char s[MAX];
int dp[MAX],g[MAX][MAX];
int main()
{
	int n,i,j,len,l,r;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++) g[i][i]=1;
	for(i=1;i<n;i++)
	{
		if(s[i]==s[i+1]) g[i][i+1]=1;
	}
	for(len=3;len<=n;len++)
	{
		for(l=1;l+len-1<=n;l++)
		{
			r=l+len-1;
			if(s[l]==s[r]) g[l][r]=g[l+1][r-1];
			else g[l][r]=0;
		}
	}
	dp[0]=INF;
	for(i=1;i<=n;i++)
	{
		dp[i]=1;
		for(j=1;j<=i;j++)
		{
			if(g[j][i]==0) continue;
//			cout<<j<<" "<<i<<endl;
			dp[i]=max(dp[i],min(dp[j-1],i-j+1));
		}
	}
	printf("%d\n",dp[n]);
	return 0;
}
