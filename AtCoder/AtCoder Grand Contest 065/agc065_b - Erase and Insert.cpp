#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
const int mod=1e9+7;
int dp[2][MAX],p[MAX];
int main()
{
	int n,i,j,f,cnt,suf,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&p[i]);
	f=0;
	for(j=1;j<=n;j++) dp[f][j]=1;
	for(i=n-1;i;i--)
	{
		f^=1;
		for(j=1;j<=n;j++) dp[f][j]=0;
		cnt=1;
		for(j=1;j<=n;j++)
		{
			if(p[j]<i) cnt++;
			else if(p[j]==i) break;
		}
		suf=0;
		for(j=n;j;j--)
		{
			if(cnt<j) dp[f][j]=(dp[f][j]+suf)%mod;
			else dp[f][j]=(0LL+dp[f][j]+suf+dp[!f][j])%mod;
			suf=(suf+dp[!f][j])%mod;
		}
	}
	ans=0;
	for(j=1;j<=n;j++) ans=(ans+dp[f][j])%mod;
	printf("%d\n",ans);
	return 0;
}
/*
变成给定的序列比较难考虑，但是变成一个1-n顺序排列是好考虑的。
发现 Q 是按顺序执行，考虑倒过来执行：
给排列 Q=P，从 i=n..1 顺序执行，每次删除 Q 中数字 i，再把它插入任意位置。
最后要求排列 Q 是 1..n 递增。

由于最后要递增，所以操作到 i 时，i+1..n 数字会作为一个递增子序列在 Q 中出现。
dp[i][j] 表示现在操作到 i，i+1 数字出现的位置为 j 的方案数。
发现需要知道 i 相对于 j 的位置才能转移。
i 在 j 左边时，只有 j-1 个可以插入的位置；在右边时，有 j 个可以插入的位置。
由于 1..i 都没有动过，算一下 i 前面有多少个 1..i-1，再加上 i 本身。
如果个数<j，说明在 j 左边；反之在右边。
转移时枚举当前插入位置，上一次插入位置是一个后缀，O(1) 维护后缀和就能做到 O(n^2)。
*/
