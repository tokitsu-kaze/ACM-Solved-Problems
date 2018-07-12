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
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	ll i,w,n,a[1111],l,r,bit[1111];
	while(~scanf("%lld%lld",&n,&w))
	{
		bit[0]=0;
		l=0;
		r=w;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			bit[i]=a[i];
			bit[i]+=bit[i-1];
			r=min(r,w-bit[i]);
			l=max(l,-bit[i]);
		}
		printf("%lld\n",max(r-l+1,0LL));
	}
	return 0;
}