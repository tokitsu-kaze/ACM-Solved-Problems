#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2000+10;
const int mod=998244353;
char mp[MAX][MAX];
int dp[MAX][2],sum[MAX];
int main()
{
	int T,n,m,d,i,j,f,l,r,sq;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&d);
		for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
		for(j=1;j<=m;j++)
		{
			if(mp[n][j]=='X') dp[j][0]=1;
			else dp[j][0]=0;
		}
		sum[0]=0;
		for(j=1;j<=m;j++) sum[j]=(sum[j-1]+dp[j][0])%mod;
		for(j=1;j<=m;j++)
		{
			l=max(1,j-d);
			r=min(m,j+d);
			if(mp[n][j]=='X') dp[j][1]=(sum[r]-sum[l-1])%mod;
			else dp[j][1]=0;
		}
		sum[0]=0;
		for(j=1;j<=m;j++) sum[j]=(sum[j-1]+dp[j][1])%mod;
		for(i=n-1;i;i--)
		{
			for(j=0;j<=m;j++) memset(dp[j],0,sizeof dp[j]);
			for(j=1;j<=m;j++)
			{
				if(mp[i][j]=='#') continue;
				sq=sqrt(d*d-1);
				while((sq+1)*(sq+1)+1<=d*d) sq++;
				l=max(1,j-sq);
				r=min(m,j+sq);
				dp[j][0]=(sum[r]-sum[l-1])%mod;
			}
			sum[0]=0;
			for(j=1;j<=m;j++) sum[j]=(sum[j-1]+dp[j][0])%mod;
			for(j=1;j<=m;j++)
			{
				if(mp[i][j]=='#') continue;
				l=max(1,j-d);
				r=min(m,j+d);
				dp[j][1]=(sum[r]-sum[l-1])%mod;
			}
			sum[0]=0;
			for(j=1;j<=m;j++) sum[j]=(sum[j-1]+dp[j][1])%mod;
		}
		if(sum[m]<0) sum[m]+=mod;
		printf("%d\n",sum[m]);
	}
	return 0;
}
