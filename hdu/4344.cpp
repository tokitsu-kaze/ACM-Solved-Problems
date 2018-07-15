#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define len(x) (int) x.length()
#define all(x) x.begin(),x.end()
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e4+10;
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
int check(ll a,ll n,ll x,ll t)
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
map<ll,int> mp;
void findfac(ll n)
{
	if(Miller_Rabin(n))
	{
		mp[n]++;
		return;
	}
	ll t=n;
	while(t>=n) t=Pollard_rho(t,rand()%(n-1)+1);
	findfac(t);
	findfac(n/t);
}
int main()
{
	ll n,t,ans;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		mp.clear();
		findfac(n);
		if(sz(mp)==1)
		{
			auto it=*mp.begin();
			ans=n/it.fi;
		}
		else
		{
			ans=0;
			for(auto it:mp) ans+=pow2(it.fi,it.se,n+1);
		}
		printf("%d %lld\n",sz(mp),ans);
	}
	return 0;
}
