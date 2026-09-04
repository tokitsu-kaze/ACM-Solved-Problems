#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=400+10;
char s[MAX],t[MAX];
int dp[MAX][MAX],n,m;
int ck(int x)
{
	int i,j;
	memset(dp,-0x3f,sizeof dp);
	dp[0][0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=x;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(j>=1 && s[i]==t[j]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
			if(dp[i-1][j]>=0 && s[i]==t[x+dp[i-1][j]+1]) dp[i][j]=max(dp[i][j],dp[i-1][j]+1);
		}
	}
	return dp[n][x]==m-x;
}
int main()
{
	int T,i,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1);
		m=strlen(t+1);
		ok=0;
		for(i=1;i<=m;i++) ok|=ck(i);
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
枚举断点 x，dp i,j,k 表示前 i，匹配第一次到 j，匹配第二次到 k。
这样做是O(n^4)的。
接下来两种优化方法，一种：由于是可行性dp，直接bitset。
另一种可以把 k 维度丢进值里。
dp i,j 表示前 i，匹配第一次到 j 第二次最长匹配到多少。
最终看 dp n,x 最长匹配 x 后面的长度是否是 m-x。
*/
