#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e7+10;
const int mod=1e9+7;
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
int main()
{
	init_comb(MAX-10);
	int n,m,x,y;
	ll x1,x2,y1,y2;
	scanf("%d%d",&n,&m);
	n++;
	x=(n+1)/2;
	y=n-x;
	x1=C(m+x,m);
	x2=C(m+x-1,m);
	y1=C(m+y,m);
	y2=C(m+y-1,m);
	printf("%lld\n",((x1*y2+x2*y1-x2*y2)%mod+mod)%mod);
	return 0;
}
/*
先列式子，发现条件是
a1<=a3<=a5..
a2<=a4<=a6.. 
题目求的是S的方案数，
分别算这两个条件再乘积，发现有重。

考虑S固定时，有哪些方案是重复的。
首先发现当a1或者ax确定后，整个序列都能确定。
x为最后的偶数位。 
然后a1如果能-1，偶数位就能通过+1调整。
钦定a1=0使其不能-1；或者ax=m，使最大的偶数位不能+1。
*/
