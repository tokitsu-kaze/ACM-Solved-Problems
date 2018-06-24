#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
#define VI vector<int>
#define VL vector<ll>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
ll mul2(ll a,ll b)
{
	ll res=0;
	while(b)
	{
		if(b&1) res=(res+a)%mod;
		a=(a+a)%mod;
		b>>=1;
	}
	return res;
}
ll pow2(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=mul2(res,a);
		a=mul2(a,a);
		b>>=1;
	}
	return res;
}
int main()
{
	ll x,k;
	while(~scanf("%lld%lld",&x,&k))
	{
		if(x==0)
		{
			puts("0");
			continue;
		}
		x%=mod;
		printf("%lld\n",(pow2(2,k+1)*x%mod-(pow2(2,k)-1+mod)%mod+mod)%mod);
	}
	return 0;
}
