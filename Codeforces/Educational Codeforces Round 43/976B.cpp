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
const ll mod=1e9;
int main()
{
	ll n,m,k,x,y;
	while(~scanf("%lld%lld%lld",&n,&m,&k))
	{
		if(k<=n-1)
		{
			x=1+k;
			y=1;
		}
		else if(k<=n+m-2)
		{
			x=n;
			y=k-n+2;
		}
		else
		{
			k-=n;
			x=n-(k/(m-1));
			if((n-x)%2) y=m;
			else y=2;
			k%=(m-1);
			if((n-x)%2==0) y+=k;
			else y-=k;
		}
		printf("%lld %lld\n",x,y);
	}
	return 0;
}