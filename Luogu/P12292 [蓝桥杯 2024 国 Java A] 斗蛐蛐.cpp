#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=(1<<15)+10;
int mod,inv2;
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
ll inv(ll x){return qpow(x,mod-2);}
int n,dp[MAX][17],a[17];
int work(int x)
{
	int s,i,m,ls,rs,y[17],k[17],b[17],dp0;
	memset(dp,0,sizeof dp);
	dp[1<<x][x]=1;
	for(s=1;s<(1<<n);s++)
	{
		m=__builtin_popcount(s);
		if(m==1) continue;
		vector<int> now;
		for(i=0;i<n;i++)
		{
			if((s>>i)&1) now.push_back(i);
		}
		for(i=0;i<m;i++)
		{
			if(m>2)
			{
				ls=s^(1<<(now[(i-1+m)%m]));
				rs=s^(1<<(now[(i+1)%m]));
				y[i]=1LL*(dp[ls][now[(i+1)%m]]+dp[rs][now[(i+2)%m]])
					 *a[now[i]]%mod*inv2%mod;
			}
			else y[i]=1LL*a[now[i]]*dp[1<<now[i]][now[i]]%mod;
		}
		k[0]=1;
		b[0]=0;
		for(i=m-1;~i;i--)
		{
			k[i]=1LL*(1-a[now[i]]+mod)*k[(i+1)%m]%mod;
			b[i]=(1LL*(1-a[now[i]]+mod)*b[(i+1)%m]+y[i])%mod;
		}
		dp0=1LL*b[0]*inv(1-k[0]+mod)%mod;
		for(i=0;i<m;i++) dp[s][now[i]]=(1LL*dp0*k[i]+b[i])%mod;
	}
	return dp[(1<<n)-1][0];
}
int main()
{
	int i;
	scanf("%d%d",&n,&mod);
	inv2=inv(2);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n;i++) printf("%d%c",work(i)," \n"[i+1==n]);
	return 0;
}
/*
枚举最后剩哪只，它获胜概率为1，然后按题意列转移。
先算出y[i]为击败的概率，转移为 dp[s][i]=y[i]+(1-a[i])*dp[s][i+1]。
注意最后剩2只的时候要特殊处理一下。
会发现在不能击败时，转移有环。

设dp[s][i]=k[i]*dp[s][0]+b[i]，
由于dp[s][0]=k[0]*dp[s][0]+b[0]，解得 k[0]=1,b[0]=0，
然后考虑倒着从下一个带入回来：
dp[s][i]=y[i]+(1-a[i])*(k[i+1]*dp[s][0]+b[i+1])，
这样 k[i]=(1-a[i])*k[i+1]，b[i]=(1-a[i])*b[i+1]+y[i]。

现在已经算出了 k[1] 和 b[1]，要带入算 dp[s][0]。
带入i=0，dp[s][0]=y[0]+(1-a[i])*(k[1]*dp[s][0]+b[1])，
但这里其实你会发现，可以再多算一步，算出新的 k[0] 和 b[0]：
k[0]=(1-a[0])*k[1]，b[0]=(1-a[0])*b[1]+y[0]。
最终 dp[s][0]=b[0]/(1-k[0])。
然后再带入算出所有的 dp[s][i]。

在转移过程中要注意 a[i] 其实是 a[now[i]]。
*/
