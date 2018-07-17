#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
struct ll_hash{size_t operator()(ll x)const{return x;}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int v[]={0,0,1,2,9};
ll C(ll n,ll m)
{
	ll i,j,res=1;
	for(i=n,j=m;j>0;i--,j--) res*=i;
	for(i=m;i>=1;i--) res/=i;
	return res;
}
int main()
{
	ll n,k,i,ans;
	while(~scanf("%lld%lld",&n,&k))
	{
		ans=0;
		for(i=1;i<=k;i++)
		{
			ans+=C(n,i)*v[i];
		}
		printf("%lld\n",ans+1);
	}
	return 0;
}