#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2000+10;
int dp[MAX][MAX];
char s[MAX],t[MAX];
int main()
{
	int T,n,i,j,now[26],tmp[26],ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		scanf("%s",t+1);
		memset(now,0,sizeof now);
		for(i=1;i<=n;i++) now[s[i]-'a']++;
		ok=1;
		for(i=1;i<=n;i++)
		{
			now[t[i]-'a']--;
			if(now[t[i]-'a']<0) ok=0;
		}
		if(!ok)
		{
			puts("-1");
			continue;
		}
		reverse(s+1,s+1+n);
		reverse(t+1,t+1+n);
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++) dp[i][j]=0;
		}
		memset(now,0,sizeof now);
		for(i=1;i<=n;i++)
		{
			now[s[i]-'a']++;
			for(j=0;j<26;j++) tmp[j]=now[j];
			ok=1;
			for(j=1;j<=i;j++)
			{
				tmp[t[j]-'a']--;
				if(tmp[t[j]-'a']<0) ok=0;
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				if(s[i]==t[j] && ok) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
			}
		}
		printf("%d\n",n-dp[n][n]);
	}
	return 0;
}
/*
1
5
abcac
cbcaa

ans=3

cacba
aacbc

把后面的插入到前面感觉不太方便思考。
我们把整个串 reverse 过来，操作变成把前面的插入到后面。
考虑哪些位置可以不动，求一个类似 LCS 的东西。
发现若 si 不动，si 匹配 tj，需要满足 t[1..j] 的字符集包含于 s[1..i]。
*/
