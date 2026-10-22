#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
const int mod=1e9+7;
ll dp[2][22][2];
int main()
{
	int n,k,x,y,i,f,now;
	scanf("%d",&n);
	k=0;
	while(1<<(k+1)<=n) k++;
	f=0;
	memset(dp[f],0,sizeof dp[f]);
	dp[f][k][0]=1;
	if(3*(1<<(k-1))<=n) dp[f][k-1][1]=1;
	for(i=2;i<=n;i++)
	{
		f^=1;
		memset(dp[f],0,sizeof dp[f]);
		for(x=0;x<=k;x++)
		{
			for(y=0;y<=1;y++)
			{
				if(y==0) now=1;
				else now=3;
				now<<=x;
				dp[f][x][y]=(dp[f][x][y]+dp[!f][x][y]*(n/now-(i-1)))%mod;
				if(x+1<=k) dp[f][x][y]=(dp[f][x][y]+dp[!f][x+1][y]*(n/now-n/(now*2)))%mod;
				if(y+1<=1) dp[f][x][y]=(dp[f][x][y]+dp[!f][x][y+1]*(n/now-n/(now*3)))%mod;
			}
		}
	}
	printf("%lld\n",dp[f][0][0]);
	return 0;
}
/*
求1-n 排列中，前缀gcd种类数最多的排列数量。
前缀gcd是递减的，考虑第一个数填什么会最大。
发现质因子有尽可能多的 2，并且不可能有 5，因为 2*2<5。
又发现 3 最多 1 个，因为 2^3<3^2，有 2 个 3 不如换 3 个 2。
dp[i][x][y] 表示排列已经选了 i 个数，当前前缀gcd有 x 个 2，y 个 3。
转移考虑：不变/减少 1 个 2/减少 1 个 3。
不变就是算一下当前有多少可以填，减去前缀已经填的；
减少 2 或者 3，要容斥一下。以 2 举例：n/(2^x*3^y)-n/(2^(x+1)*3^y)。
*/
