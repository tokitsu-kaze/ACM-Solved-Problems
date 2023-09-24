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
const int MAX=1e5+10;
const ll mod=1e9+7;
ll a[MAX];
int main()
{
	int n,x,k,i;
	ll l,r;
	ll ans;
	while(~scanf("%d%d%d",&n,&x,&k))
	{
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		sort(a,a+n);
		ans=0;
		for(i=0;i<n;i++)
		{
			l=(a[i]/x-k)*x+1;
			r=min(a[i],(a[i]/x-k+1)*x);
			ans+=(ll)max(0,upper_bound(a,a+n,r)-lower_bound(a,a+n,l));
	//		cout<<l<<" "<<r<<" "<<ans<<endl;
		}
		printf("%lld\n",ans);
	}
	return 0;
}