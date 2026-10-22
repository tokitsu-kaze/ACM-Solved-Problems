#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2000+10;
const int mod=1e9;
char s[MAX];
int dp[2][MAX];
int main()
{
	int n,i,j,f;
	scanf("%d",&n);
	scanf("%s",s+1);
	f=0;
	memset(dp[f],0,sizeof dp[f]);
	dp[f][0]=1;
	for(i=1;i<=n;i++)
	{
		f^=1;
		memset(dp[f],0,sizeof dp[f]);
		for(j=0;j<=n;j++)
		{
			dp[f][j]=dp[!f][j];
			if(s[i]=='(' && j>0) dp[f][j]=(dp[f][j]+dp[!f][j-1])%mod;
			if(s[i]==')') dp[f][j]=(dp[f][j]+dp[!f][j+1])%mod;
		}
	}
	printf("%d\n",dp[f][0]);
	return 0;
}
