#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=(1<<18)+10;
const int mod=998244353;
char s[MAX];
int dp[MAX];
int n;
string dfs(int x)
{
	string l,r,now;
	int ls,rs;
	ls=(x<<1);
	rs=ls+1;
	now="";
	now+=s[x];
	if(ls>n)
	{
		dp[x]=1;
		return now;
	}
	l=dfs(ls);
	r=dfs(rs);
	now+=min(l+r,r+l);
	dp[x]=1LL*dp[ls]*dp[rs]%mod;
	if(l!=r) dp[x]=2*dp[x]%mod;
	return now;
}
int main()
{
	int k;
	scanf("%d",&k);
	n=(1<<k)-1;
	scanf("%s",s+1);
	dfs(1);
	printf("%d\n",dp[1]);
	return 0;
}
/*
每个节点方案数是dp[ls]*dp[rs]。然后决策换还是不换，换就*2。
但还要看子树是否同构，同构就不能*2。
判断方法可以按照最小字典序的前序，由于层高是log，直接暴力比较。
*/
