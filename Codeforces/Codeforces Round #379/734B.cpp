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
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	ll a,b,c,d,cnt1,cnt2;
	while(~scanf("%lld%lld%lld%lld",&a,&b,&c,&d))
	{
		cnt1=min(a,min(c,d));
		a-=cnt1;
		c-=cnt1;
		d-=cnt1;
		cnt2=min(a,b);
		printf("%lld\n",cnt1*256+cnt2*32);
	}
	return 0;
}