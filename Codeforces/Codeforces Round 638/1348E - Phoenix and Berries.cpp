#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=500+10;
ll dp[MAX][MAX];
int main()
{
	int n,k,i,x,y,j,nx,a,b;
	ll sum,ans;
	memset(dp,-0x3f,sizeof dp);
	dp[0][0]=0;
	scanf("%d%d",&n,&k);
	sum=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		for(x=0;x<k;x++)
		{
			if(dp[i-1][x]<0) continue;
			y=sum-dp[i-1][x]*k-x;
			
			nx=(x+a)%k;
			dp[i][nx]=max(dp[i][nx],dp[i-1][x]+(a+x)/k+(b+y)/k);
			
			for(j=1;j<=min(k-1,a);j++)
			{
				if(j+b<k) continue;
				nx=(x+a-j)%k;
				dp[i][nx]=max(dp[i][nx],dp[i-1][x]+1+(a+x-j)/k+(b+y-(k-j))/k);
			}
		}
		sum+=a+b;
	}
	ans=0;
	for(x=0;x<k;x++) ans=max(ans,dp[n][x]);
	printf("%lld\n",ans);
	return 0;
}
/*
dp[i][x][y]表示前i个，剩下x红和y蓝的最大值。
x和y一定是<k的，>=k等价于减掉k。所以直接转移要nk^4。
发现其实知道x之后，y也能算出来。
于是可以少枚举两个东西，复杂度变成nk^2，可以通过。

具体考虑怎么算y以及转移。
前面总数是sum，枚举x，y=sum-dp[i-1][x]*k-x。
钦定当前混用最多1个篮子，因为超过一个可以等价转化成1个混用+其他的同色。
如果没有共用的篮子，剩下nx=(x+a)%k，有转移：
dp[i][nx]  <-  dp[i-1][x]+(a+x)/k+(b+y)/k
所以再枚举当前a中有j个混用，转移后剩下nx=(x+a-j)%k，有转移：
dp[i][nx]  <-  dp[i-1][x]+1+(a+x-j)/k+(b+y-(k-j))/k
枚举时注意无法混用的情况。
*/
