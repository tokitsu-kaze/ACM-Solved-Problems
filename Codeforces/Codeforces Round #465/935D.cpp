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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
ll pow2(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll inv(ll x)
{
	return pow2(x,mod-2);
}
ll a[MAX],b[MAX];
int main()
{
	ll n,m,i,ans,now,tmp;
	while(~scanf("%lld%lld",&n,&m))
	{
		for(i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(i=1;i<=n;i++) scanf("%lld",&b[i]);
		tmp=0;
		for(i=1;i<m;i++) tmp=(tmp+(m-i)*inv(m))%mod;
		tmp=tmp*inv(m)%mod;
		ans=0;
		now=1;
		for(i=1;i<=n;i++)
		{
			if(a[i]==0&&b[i]==0)
			{
				ans=(ans+now*tmp%mod)%mod;
				now=now*inv(m)%mod;
			}
			else if(a[i]==0)
			{
				ans=(ans+now*(m-b[i])%mod*inv(m)%mod)%mod;
				now=now*inv(m)%mod;
			}
			else if(b[i]==0)
			{
				ans=(ans+now*(a[i]-1)%mod*inv(m)%mod)%mod;
				now=now*inv(m)%mod;
			}
			else if(a[i]>b[i])
			{
				ans=(ans+now)%mod;
				break;
			}
			else if(a[i]<b[i]) break;
		}
		printf("%lld\n",ans);
	}
	return 0;
}