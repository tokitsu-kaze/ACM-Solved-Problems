#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e6+10;
ll mod;
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
int main()
{
	ll n,k,j,l,ans,now,i,tot;
	while(~scanf("%lld%lld%lld",&n,&k,&mod))
	{
		tot=now=n;
		now++;
		ans=0;
		for(i=1;i<=k;i++)
		{
			now=1;
			ll t;
			for(j=n+1,l=0;l<=i;l++,j--)
			{
				if(j%(i+1)==0)
				{
					t=j;
					break;
				}
			}
			for(j=n+1,l=0;l<=i;l++,j--)
			{
				if(t!=j) now=mul2(now,j);
			}
			now=mul2(now,t/(i+1));
			ans+=now;
			ans%=mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
