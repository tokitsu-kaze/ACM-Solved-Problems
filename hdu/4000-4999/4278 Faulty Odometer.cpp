#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
ll dp[22][11];
ll gao(ll x)
{
	vector<int> p;
	if(x==-1) return 0;
	while(1)
	{
		p.pb(x%10);
		x/=10;
		if(!x) break;
	}
	function<ll(int,int,int,int)> dfs=[&](int pos,int lead,int sta,int limt)->ll
	{
		if(pos==-1) return 1;
		if(!limt&&!lead&&dp[pos][sta]!=-1) return dp[pos][sta];
		ll res=0;
		for(int i=(limt?p[pos]:9);~i;i--)
		{
			if(i==3||i==8) continue;
			res+=dfs(pos-1,lead&&i==0&&pos,i,limt&&i==p[pos]); 
		}
		if(!limt&&!lead) dp[pos][sta]=res;
		return res;
	};
	return dfs(sz(p)-1,1,0,1);
}
int main()
{
	ll n;
	mem(dp,-1);
	while(~scanf("%lld",&n)&&n)
	{
		printf("%lld: %lld\n",n,gao(n)-1);
	}
	return 0;
}
