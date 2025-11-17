#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e7+10;
namespace TMP
{
	//O(r-l+1)
	const int N=2e7+10;
	ll p[N],tot;
	bool vis[N],prime[N];
	void init(ll l,ll r)
	{
		ll i,j,sq=sqrt(r+0.5);
		tot=0;
		for(i=0;i<=sq;i++) vis[i]=1;
		for(i=l;i<=r;i++) prime[i-l]=1;
		if(l==0) prime[0]=prime[1]=0;
		if(l==1) prime[0]=0;
		for(i=2;i<=sq;i++)
		{
			if(!vis[i]) continue;
			for(j=i+i;j<=sq;j+=i) vis[j]=0;
			for(j=max(2LL,(l+i-1)/i)*i;j<=r;j+=i) prime[j-l]=0;
		}
		for(i=l;i<=r;i++)
		{
			if(prime[i-l]) p[tot++]=i;
		}
	}
}
//x is a prime if prime[x]==x(x>=2)
int p[MAX],tot,prime[MAX];
void init_prime(int n)
{
	int i,j;
	tot=0;
	memset(prime,0,sizeof prime);
	prime[1]=1;
	for(i=2;i<=n;i++)
	{
		if(!prime[i]) prime[i]=p[tot++]=i;
		for(j=0;j<tot&&p[j]*i<=n;j++)
		{
			prime[i*p[j]]=p[j];
			if(i%p[j]==0) break;
		}
	}
}
const ll LIMT=1e18;
int main()
{
	init_prime(1e7);
	int i;
	ll l,r,ans,x;
	scanf("%lld%lld",&l,&r);
	if(l==r)
	{
		puts("1");
		return 0;
	}
	ans=1;
	TMP::init(l+1,r);
	ans+=TMP::tot;
	for(i=0;i<tot;i++)
	{
		x=1LL*p[i]*p[i];
		while(x<=r)
		{
			if(x>=l+1 && x<=r) ans++;
			if(x<=LIMT/p[i]) x*=p[i];
			else break;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
/*
[L+1,R]内质数个数
[L+1,R]内有多少个数是幂次
+1 
*/
