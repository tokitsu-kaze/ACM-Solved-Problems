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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int a[MAX],b[MAX],c[MAX];
int main()
{
	int t,n,i;
	ll ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		for(i=0;i<n;i++) scanf("%d",&b[i]);
		for(i=0;i<n;i++) scanf("%d",&c[i]);
		sort(a,a+n);
		sort(c,c+n);
		ans=0;
		for(i=0;i<n;i++)
		{
			ll p1=lower_bound(a,a+n,b[i])-a;
			ll p2=upper_bound(c,c+n,b[i])-c;
			p2=n-p2;
			ans+=p1*p2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}