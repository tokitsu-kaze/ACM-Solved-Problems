#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=100+2;
int dp[MAX][MAX*MAX*MAX],tmp[MAX];
int main()
{
	int n,k,mod,i,j,l,sum,x;
	ll ans;
	scanf("%d%d%d",&n,&k,&mod);
	memset(dp,0,sizeof dp);
	dp[0][0]=1;
	sum=0;
	for(i=1;i<=n;i++)
	{
		sum+=i*k;
		memset(tmp,0,sizeof tmp);
		for(j=0;j<=sum;j++)
		{
			dp[i][j]=(dp[i-1][j]+tmp[j%i])%mod;
			tmp[j%i]=(tmp[j%i]+dp[i-1][j])%mod;
			if(j-i*k>=0) tmp[j%i]=(tmp[j%i]-dp[i-1][j-i*k]+mod)%mod;
		}
	}
	for(x=1;x<=n;x++)
	{
		sum=k*min(x*(x-1)/2,(1+n-x)*(n-x)/2);
		ans=0;
		for(j=0;j<=sum;j++) ans=(ans+1LL*dp[x-1][j]*dp[n-x][j])%mod;
		ans=(ans*(k+1)-1)%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
/*
总和是 O(n^2 * k) 级别
平均数为 x，等价于把每个数都减掉 x 后 sum=0
即在[1-x,-1]选若干个，再在[1,n-x]选若干个，sum=0
0的位置随便选，可以选 0,1,2,...,k 个，所以有 k+1 种选法 
dp[i][j] 表示 选了数字 1-i 后 sum=j 的方案数
枚举 x，最后答案为 ((k+1)*sum_j{dp[x-1][j]*dp[n-x][j]})-1
减1是空集
*/
