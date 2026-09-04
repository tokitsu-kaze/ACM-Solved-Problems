#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e7+10;
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
ll inv(ll x){return qpow(x,mod-2);}
int fac[MAX],invfac[MAX];
void init_comb(int n)
{
	assert(n<MAX);
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
	invfac[n]=inv(fac[n]);
	for(int i=n-1;~i;i--) invfac[i]=1ll*invfac[i+1]*(i+1)%mod;
}
ll C(int n,int m)
{
	if(m>n||m<0||n<0) return 0;
	return 1ll*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
ll A(int n,int m)
{
	if(m>n||m<0||n<0) return 0;
	return 1ll*fac[n]*invfac[n-m]%mod;
}
int main()
{
	init_comb(MAX-10);
	int T,a,b,k,x;
	ll fz,fm;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&a,&b,&k);
		fz=0;
		for(x=0;x<=a;x++)
		{
			fz=(fz+(C(x+(x+k-1),x)-C(x+(x+k-1),(x+k-1)-k)+mod)
					*C((a-x)+(b-(x+k)),a-x)%mod
					*(x+k))%mod;
		}
		if(b<a+k) fz=(fz+b*(C(a+b,a)-C(a+b,b-k)+mod))%mod;
		fm=C(a+b,a);
		printf("%lld\n",fz*inv(fm)%mod);
	}
	return 0;
}
/*
假期望，考虑求出最后剩下牌所对应的方案数。最后除以总方案数C(a+b,a)。
设过程中抽出了 x 个强贪壶，y张普通牌。
当 y=x+k 时，没有强贪壶了，停止；并且在这之前都没有达到 y=x+k。
枚举壶的数量 x，转化成格路计数：
- 先考虑牌堆没抽干的情况。
从(0,0)开始，抽一张普通牌(x,y)->(x,y+1)，抽一张壶(x,y)->(x+1,y)，最终走到(x,x+k)。
最后停止那一步一定是向上，转化为最终走到(x,x+k-1)。
中途不能碰到 y=x+k。套用单线反射容斥公式，方案数为：C(x+(x+k-1),x)-C(x+(x+k-1),(x+k-1)-k)。
考虑剩下牌堆的顺序，即从(x,x+k)走到(a,b)，没有限制。方案数为：C((a-x)+(b-(x+k)),a-x)。
这种情况剩下(x+k)张牌。
- 再考虑牌堆抽干的情况，即 b<a+k。
其实就是走的过程中都没有碰到 y=x+k，同样套公式，方案数为：C(a+b,a)-C(a+b,b-k)。
最后剩下b张牌。

单线反射容斥公式：(0,0)->(n,m) 不碰到 y=x+k 的方案数：C(n+m,n)-C(n+m,m-k)。
*/
