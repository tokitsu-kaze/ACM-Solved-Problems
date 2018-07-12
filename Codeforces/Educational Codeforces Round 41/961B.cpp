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
const double eps=1e-8;
const int MAX=2e5+10;
const ll mod=1e9+7;
ll a[MAX],b[MAX],sum[MAX],sum2[MAX];
int main()
{
	ll n,m,i,ans,s1,s2;
	while(~scanf("%lld%lld",&n,&m))
	{
		for(i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(i=1;i<=n;i++) scanf("%lld",&b[i]);
		for(i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
		for(i=1;i<=n;i++) sum2[i]=sum2[i-1]+b[i]*a[i];
		ans=0;
		for(i=1;i<=n-m+1;i++)
		{
			s1=s2=0;
			s1+=sum[i+m-1]-sum[i-1];
			s2+=sum2[i-1];
			s2+=sum2[n]-sum2[i+m-1];
			ans=max(ans,s1+s2);
		}
		printf("%lld\n",ans);
	}
	return 0;
}