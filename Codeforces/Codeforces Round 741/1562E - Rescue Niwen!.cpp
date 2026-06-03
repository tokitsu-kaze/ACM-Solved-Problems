#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
int lcp[MAX][MAX];
void LCP(char *s,int n) // s[1..n]
{
	int i,j;
	for(i=1;i<=n;i++) lcp[n][i]=(s[n]==s[i]);
	for(i=1;i<=n;i++) lcp[i][n]=(s[i]==s[n]);
	for(i=n-1;i;i--)
	{
		for(j=n-1;j>=i;j--)
		{
			if(s[i]==s[j]) lcp[i][j]=lcp[i+1][j+1]+1;
			else lcp[i][j]=0;
		}
	}
}
/*
lcp[i][j]: longest common prefix of s[1..i] and s[1..j] (i<j)
*/
char s[MAX];
int dp[MAX];
int main()
{
	int T,n,i,j,ans,len;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		LCP(s,n);
		for(i=0;i<=n+1;i++) dp[i]=0;
		ans=n;
		for(i=1;i<=n;i++)
		{
			dp[i]=n-i+1;
			for(j=1;j<i;j++)
			{
				len=lcp[j][i];
				if(i+len>n || s[i+len]<=s[j+len]) continue;
				dp[i]=max(dp[i],dp[j]+n-(i+len-1));
			}
			ans=max(ans,dp[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
观察样例发现从某个串为前缀选到最后一定不劣。
但根据倒数第3个样例发现不能只比较第一个字符，
发现只要i开始的某个前缀比前面j开始的某个前缀大，即可转移。
dp[i]表示从i开始的答案。
考虑从j开始的串转移，发现可转移的情况为：
s[i+lcp(j,i)]>s[j+lcp(j,i)]
每次转移产生贡献 n-(i+len-1)，并且对之后的转移不影响。
*/
