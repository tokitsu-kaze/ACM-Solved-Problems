#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
ll pow2(ll a,ll b)
{
	ll res=1;
	if(b<1) return 1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int main()
{
	freopen("azerah.in","r",stdin);
	freopen("azerah.out","w",stdout);
	ll ans,cnt[3],i,n,t,x;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		mem(cnt,0);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&x);
			cnt[x%2]++;
		}
		ll a=(pow2(2,cnt[1]-1)-1+mod)%mod;
		ll b=(pow2(2,cnt[0])-1+mod)%mod;
		printf("%lld\n",(a+b+a*b%mod)%mod);
	}
	return 0;
}
/*
100
4
1 2 3 4
4
1 3 5 7
*/