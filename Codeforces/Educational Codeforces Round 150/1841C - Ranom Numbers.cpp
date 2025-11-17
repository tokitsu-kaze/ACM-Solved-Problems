#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
ll dp[MAX][6][2];
int main()
{
	int T,n,i,j,k,val[6],t;
	ll ans;
	val[0]=1;
	for(i=1;i<=4;i++) val[i]=val[i-1]*10;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		memset(dp[n],-0x3f,sizeof dp[n]);
		dp[n][s[n]-'A'][0]=val[s[n]-'A'];
		for(j=0;j<5;j++) dp[n][j][1]=val[j];
		for(i=n-1;i;i--)
		{
			memset(dp[i],-0x3f,sizeof dp[i]);
			t=s[i]-'A';
			for(j=0;j<5;j++)
			{
				if(t<j)
				{
					dp[i][j][0]=max(dp[i][j][0],dp[i+1][j][0]-val[t]);
					dp[i][j][1]=max(dp[i][j][1],dp[i+1][j][1]-val[t]);
				}
				else
				{
					dp[i][t][0]=max(dp[i][t][0],dp[i+1][j][0]+val[t]);
					dp[i][t][1]=max(dp[i][t][1],dp[i+1][j][1]+val[t]);
				}
				for(k=0;k<5;k++)
				{
					if(k<j) dp[i][j][1]=max(dp[i][j][1],dp[i+1][j][0]-val[k]);
					else dp[i][k][1]=max(dp[i][k][1],dp[i+1][j][0]+val[k]);
				}
			}
		}
		ans=-LLINF;
		for(j=0;j<5;j++) ans=max({ans,dp[1][j][0],dp[1][j][1]});
		printf("%lld\n",ans);
	}
	return 0;
}
