#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define len(x) (int) x.length()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
const int S=20;
ll mul2(ll a,ll b,ll p)
{
	ll res=0;
	while(b)
	{
		if(b&1) res=(res+a)%p;
		a=(a+a)%p;
		b>>=1;
	}
	return res;
}
ll pow2(ll a,ll b,ll p)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=mul2(res,a,p);
		a=mul2(a,a,p);
		b>>=1;
	}
	return res;
}
int check(ll a,ll n,ll x,ll t)//一定是合数返回1,不一定返回0
{
	ll now,nex,i;
	now=nex=pow2(a,x,n);
	for(i=1;i<=t;i++)
	{
		now=mul2(now,now,n);
		if(now==1&&nex!=1&&nex!=n-1) return 1;
		nex=now;
	}
	if(now!=1) return 1;
	return 0;
}
int Miller_Rabin(ll n)
{
	if(n<2) return 0;
	if(n==2) return 1;
	if((n&1)==0) return 0;
	ll x,t,i;
	x=n-1;
	t=0;
	while((x&1)==0) x>>=1,t++;
	for(i=0;i<S;i++)
	{
		if(check(rand()%(n-1)+1,n,x,t)) return 0;
	}
	return 1;
}
ll Pollard_rho(ll x,ll c)
{
	ll i,k,g,t,y;
	i=1;
	k=2;
	y=t=rand()%x;
	while(1)
	{
		i++;
		t=(mul2(t,t,x)+c)%x;
		g=__gcd(y-t+x,x);
		if(g!=1&&g!=x) return g;
		if(y==t) return x;
		if(i==k)
		{
			y=t;
			k+=k;
		}
	}
}
vector<ll> fac;
void findfac(ll n)
{
	if(Miller_Rabin(n))
	{
		fac.pb(n);
		return;
	}
	ll t=n;
	while(t>=n) t=Pollard_rho(t,rand()%(n-1)+1);
	findfac(t);
	findfac(n/t);
}
int main()
{
	ll n,t,ans,i;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(Miller_Rabin(n))
		{
			puts("Prime");
			continue;
		}
		fac.clear();
		findfac(n);
		ans=(1LL<<60);
		for(i=0;i<sz(fac);i++) ans=min(ans,fac[i]);
		printf("%lld\n",ans);
	}
	return 0;
}