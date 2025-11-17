#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=(1<<22)+10;
const int mod=998244353;
ll dp[MAX];
int main()
{
	int n,i,j,s;
	ll ans;
	char t[25],pre;
	scanf("%d",&n);
	scanf("%s",t);
	memset(dp,0,sizeof dp);
	dp[0]=1;
	for(s=0;s<(1<<n);s++)
	{
		pre='?';
		for(i=0;i<n;i++)
		{
			if((s>>i)&1) continue;
			if(pre==t[i]) continue;
			dp[s|(1<<i)]+=dp[s];
			if(dp[s|(1<<i)]>=mod) dp[s|(1<<i)]-=mod;
			pre=t[i];
		}
	}
	printf("%lld\n",dp[(1<<n)-1]);
	return 0;
}
