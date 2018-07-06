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
const double eps=1e-4;
const int MAX=2e5+10;
const ll mod=998244353;
int main()
{
	ll n,d,i,a[222];
	while(~scanf("%lld%lld",&n,&d))
	{
		for(i=1;i<=n;i++) scanf("%lld",&a[i]);
		set<int> s;
		sort(a+1,a+1+n);
		a[0]=-LLINF;
		a[n+1]=LLINF;
		for(i=1;i<=n;i++)
		{
			ll t=a[i]-d;
			if(abs(t-a[i-1])>=d&&abs(a[i+1]-t)>=d) s.insert(t);
			t=a[i]+d;
			if(abs(t-a[i-1])>=d&&abs(a[i+1]-t)>=d) s.insert(t);
		}
		printf("%d\n",sz(s));
	}
	return 0;
} 
