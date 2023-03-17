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
#define VI vector<int>
#define VL vector<ll>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
bool gao(ll k,ll n)
{
	ll a,b,x=n;
	a=b=0;
	while(n)
	{
		a+=min(n,k);
		n-=k;
		if(n<=0) break;
		b+=n/10;
		n-=n/10; 
	}
	return a*2>=x;
} 
int main()
{
	ll n,l,r,mid;
	while(~scanf("%lld",&n))
	{
		l=1;
		r=n;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(gao(mid,n)) r=mid;
			else l=mid+1; 
		}
		printf("%lld\n",l);
	}
	return 0;
}
