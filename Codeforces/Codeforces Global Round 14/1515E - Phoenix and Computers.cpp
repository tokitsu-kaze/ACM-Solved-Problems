#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=400+10;
int mod;
int comb[MAX][MAX];
void init_comb(int n)
{
	int i,j;
	comb[0][0]=1;
	for(i=1;i<=n;i++)
	{
		comb[i][0]=1;
		for(j=1;j<=i;j++)
		{
			comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
			if(comb[i][j]>=mod) comb[i][j]-=mod;
		}
	}
}
ll C(int n,int m)
{
	if(m>n||m<0||n<0) return 0;
	return comb[n][m];
}
int pw2[MAX];
ll dp[MAX][MAX];
int main()
{
	int n,i,j,k,x;
	ll ans;
	scanf("%d%d",&n,&mod);
	init_comb(n);
	pw2[0]=1;
	for(i=1;i<=n;i++) pw2[i]=pw2[i-1]*2%mod;
	memset(dp,0,sizeof dp);
	for(i=1;i<=n;i++)
	{
		dp[i][i]=pw2[i-1];
		for(k=1;k+2<=i;k++)
		{
			x=i-(k+2)+1;
			for(j=x;j<=i;j++)
			{
				dp[i][j]=(dp[i][j]+dp[k][j-x]*pw2[x-1]%mod*C(j,x))%mod;
			}
		}
	}
	ans=0;
	for(j=1;j<=n;j++) ans=(ans+dp[n][j])%mod;
	printf("%lld\n",ans);
	return 0;
}
/*
先考虑所有电脑都是手动打开的情况：
先开i=1或者i=n，只有1种；
否则，开i=x，只能往左右拓展，
相当于n-1次操作中要有x-1次操作左侧，并且操作的顺序是定的
C(n-1,0)+C(n-1,1)+C(n-1,2)+...+C(n-1,n-1)=2^(n-1)

接下来就会了。dp[i][j]表示1-i已经开了，其中j个是手动开的
枚举上一个段的位置 k，那么本次手动开的电脑为 x=i-(k+2)+1
开这些电脑的方案数是2^(x-1)，
再考虑与前面手动开的电脑的顺序，在总的j个中选x个，C(j,x) 
dp[i][j]+=dp[k][j-x]*pw2[x-1]%mod*C(j,x)
*/
