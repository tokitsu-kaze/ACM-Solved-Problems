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
int main()
{
	freopen("perechi3.in","r",stdin);
	freopen("perechi3.out","w",stdout);
	ll t,n,i,ans;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n==1)
		{
			puts("1");
			continue;
		}
		ans=0;
		for(i=1;i<=sqrt(n);i++)
		{
			ans+=n/i-i;
		}
		printf("%lld\n",ans*2+(int)sqrt(n));
	}
	return 0;
}