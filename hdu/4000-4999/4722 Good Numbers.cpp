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
ll dp[33][11];
ll gao(ll x)
{
	int p[33],tot=0;
	if(x==-1) return 0LL;
	while(x)
	{
		p[tot++]=x%10;
		x/=10;
	}
	function<ll(int,int,int)> dfs=[&](int pos,int sta,int limt)->ll
	{
		if(pos==-1)
		{
			if(!sta) return 1;
			return 0;
		}
		if(!limt&&dp[pos][sta]!=-1) return dp[pos][sta];
		ll res=0;
		for(int i=(limt?p[pos]:9);~i;i--)
		{
			res+=dfs(pos-1,(sta+i)%10,limt&&i==p[pos]); 
		}
		if(!limt) dp[pos][sta]=res;
		return res;
	};
	return dfs(tot-1,0,1);
}
int main()
{
	int t,cas=1;
	ll l,r;
	mem(dp,-1);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&l,&r);
		printf("Case #%d: %lld\n",cas++,gao(r)-gao(l-1));
	}
	return 0;
} 

