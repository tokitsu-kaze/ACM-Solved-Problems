#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
int main()
{
	int n,i;
	ll dp[22];
	char s[22];
	scanf("%s",s+1);
	n=strlen(s+1);
	reverse(s+1,s+1+n);
	dp[0]=1;
	for(i=1;i<=n;i++)
	{
		dp[i]=dp[i-1]*(s[i]-'0'+1);
		if(i>1 && s[i]=='1') dp[i]+=dp[i-2]*('9'-s[i-1]);
	}
	printf("%lld\n",dp[n]);
	return 0;
}
