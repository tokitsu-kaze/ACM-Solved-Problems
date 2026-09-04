#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
char s[MAX];
int dis[26][26],dp[MAX],sum[26][MAX],mn[26][MAX];
void floyd(int n)
{
	int i,j,k;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
int main()
{
	int n,m,k,i,j;
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s",s+1);
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++) scanf("%d",&dis[i][j]);
	}
	floyd(m);
	for(j=0;j<m;j++)
	{
		sum[j][0]=0;
		for(i=1;i<=n;i++)
		{
			sum[j][i]=sum[j][i-1]+dis[s[i]-'a'][j];
		}
	}
	memset(dp,0x3f,sizeof dp);
	memset(mn,0x3f,sizeof mn);
	dp[0]=0;
	for(j=0;j<m;j++)
	{
		mn[j][0]=0;
		for(i=1;i<k;i++) mn[j][i]=0;
	}
	for(i=k;i<=n;i++)
	{
		for(j=0;j<m;j++) dp[i]=min(dp[i],sum[j][i]+mn[j][i-k]);
		for(j=0;j<m;j++) mn[j][i]=min(mn[j][i-1],dp[i]-sum[j][i]);
	}
	printf("%d\n",dp[n]);
	return 0;
}
/*
先用 floyd 跑个最短路。
对于每种字母，处理一下全变成它的前缀和。
dp[i] 表示考虑到第 i 个字符的最小答案。
dp[i]=min{dp[j]+sum{j+1..i}}, j<=i-k，
转移稍微转化一下变成：sum[i]-sum[j]+dp[j]。
对 -sum[j]+dp[j] 做一个前缀 min 进行转移即可。
*/
