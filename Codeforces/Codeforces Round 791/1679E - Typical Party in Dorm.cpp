#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=(1<<17)+10;
const int mod=998244353;
ll qpow(ll a,ll b)
{
	ll res=1;
	while(b>0)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
char s[1010];
int dp[MAX][18];
int need[1010][1010],cnt[1010][1010],sum[1010];
int pw[18][1010];
int main()
{
	int n,S,i,j,l,r,len,q,sta;
	char qst[22];
	scanf("%d",&n);
	scanf("%s",s+1);
	for(i=1;i<=17;i++)
	{
		pw[i][0]=1;
		for(j=1;j<=n;j++) pw[i][j]=1LL*pw[i][j-1]*i%mod;
	}
	memset(need,0,sizeof need);
	memset(cnt,0,sizeof cnt);
	sum[0]=0;
	for(i=1;i<=n;i++)
	{
		sum[i]=sum[i-1];
		if(s[i]=='?')
		{
			cnt[i][i]++;
			sum[i]++;
		}
	}
	for(i=1;i<n;i++)
	{
		if(s[i]=='?' && s[i+1]=='?') cnt[i][i+1]++;
		else if(s[i]=='?') need[i][i+1]|=(1<<(s[i+1]-'a'));
		else if(s[i+1]=='?') need[i][i+1]|=(1<<(s[i]-'a'));
		else if(s[i]!=s[i+1]) need[i][i+1]=-1;
	}
	for(len=3;len<=n;len++)
	{
		for(l=1;l+len-1<=n;l++)
		{
			r=l+len-1;
			if(need[l+1][r-1]==-1)
			{
				need[l][r]=-1;
				continue;
			}
			cnt[l][r]=cnt[l+1][r-1];
			need[l][r]=need[l+1][r-1];
			if(s[l]=='?' && s[r]=='?') cnt[l][r]++;
			else if(s[l]=='?') need[l][r]|=(1<<(s[r]-'a'));
			else if(s[r]=='?') need[l][r]|=(1<<(s[l]-'a'));
			else if(s[l]!=s[r]) need[l][r]=-1;
		}
	}
	memset(dp,0,sizeof dp);
	for(l=1;l<=n;l++)
	{
		for(r=l;r<=n;r++)
		{
			if(need[l][r]==-1) continue;
			cnt[l][r]+=sum[n]-(sum[r]-sum[l-1]);
			for(i=__builtin_popcount(need[l][r]);i<=17;i++)
			{
				(dp[need[l][r]][i]+=pw[i][cnt[l][r]])%=mod;
			}
		}
	}
	for(i=0;i<17;i++)
	{
		for(S=0;S<(1<<17);S++)
		{
			if(!((S>>i)&1)) continue;
			for(j=1;j<=17;j++)
			{
				dp[S][j]=(dp[S][j]+dp[S^(1<<i)][j])%mod;
			}
		}
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%s",qst);
		len=strlen(qst);
		sta=0;
		for(i=0;i<len;i++) sta|=(1<<(qst[i]-'a'));
		printf("%d\n",dp[sta][len]);
	}
	return 0;
}
/*
先考虑固定长度的回文有多少种方案。
发现有一部分是能确定填什么，另一部分两边都是?。
所以方案数就是，|S| ^ (cnt?-cnt确定?+1)/2。
考虑计算每种回文的贡献。
可以用区间dp计算出，需要的集合以及?个数。
然后再做个高维前缀和，好像就做完了。

3
???
3
a
ab
abc

*/
