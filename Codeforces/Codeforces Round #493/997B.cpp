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
const int MAX=5e5+10;
const ll mod=998244353;
set<ll> xx;
void dfs(int x,ll s)
{
	if(x==0)
	{
		xx.insert(s);
		return;
	}
	dfs(x-1,s+1);
	dfs(x-1,s+5);
	dfs(x-1,s+10);
	dfs(x-1,s+50);
}

int main()
{
	ll n,a[]={0,4,10,20,35,56,83,116,155,198,244,292};
	while(~scanf("%lld",&n))
	{
/*		for(int i=1;i<=15;i++)
		{
			xx.clear();
			dfs(i,0);
			cout<<sz(xx)<<",";
		}*/
		if(n<=11)
		{
			printf("%lld\n",a[n]);
			continue;
		}
		printf("%lld\n",a[11]+(n-11)*49);
	}
	return 0;
}