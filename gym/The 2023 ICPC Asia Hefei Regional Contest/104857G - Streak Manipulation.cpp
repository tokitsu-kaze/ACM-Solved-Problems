#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
char s[MAX];
int pre[MAX],bit[MAX],n,m,k;
int dp[MAX][7][2];
int ck(int x)
{
	int i,j;
	memset(dp,0x3f,sizeof dp);
	dp[0][0][0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=k;j++)
		{
			if(j>0&&i-x+1>0)
			{
				dp[i][j][1]=min(dp[i][j][1],dp[pre[i-x+1]][j-1][0]+bit[i]-bit[i-x]);
			}
			dp[i][j][0]=min({dp[i][j][0],dp[i-1][j][0],dp[i-1][j][1]});
		}
	}
	return min(dp[n][k][0],dp[n][k][1])<=m;
}
int main()
{
	int i,l,r,mid,lst;
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s",s+1);
	bit[0]=0;
	lst=0;
	pre[0]=0;
	for(i=1;i<=n;i++)
	{
		bit[i]=bit[i-1]+((s[i]-'0')^1);
		pre[i]=lst;
		if(s[i]=='0') lst=i;
	}
	l=1;
	r=n;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid+1)) l=mid+1;
		else r=mid;
	}
	if(ck(l)) printf("%d\n",l);
	else puts("-1");
	return 0;
}
