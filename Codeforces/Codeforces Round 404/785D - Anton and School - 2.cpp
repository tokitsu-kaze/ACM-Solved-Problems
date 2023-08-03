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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
ll fac[MAX];
void init()
{
	ll i;
	fac[0]=1;
	for(i=1;i<=2e5;i++)
	{
		fac[i]=fac[i-1]*i%mod;
	}
}
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
ll C(ll n,ll m)
{
	if(m>n||m<0) return 0;
	return fac[n]*pow2(fac[m]*fac[n-m]%mod,mod-2)%mod;
}
char a[MAX];
int main()
{
	ll i,len,l,r,ans;
	init();
	while(~scanf("%s",a))
	{
		len=strlen(a);
		r=0;
		for(i=0;i<len;i++)
		{
			if(a[i]==')') r++;
		}
		l=0;
		ans=0;
		for(i=0;i<len;i++)
		{
			if(a[i]=='(')
			{
				l++;
				ans+=C(l+r-1,l);
				ans%=mod;
			}
			else r--;
		}
		printf("%lld\n",ans);
	}
	return 0;
}