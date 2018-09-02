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
ll dp[21][1111][13];
ll gao(ll x,ll k)
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
		if(pos==-1)
		{
			if(__builtin_popcount(sta)<=k) return 1;
			return 0;
		}
		if(!limt&&!lead&&dp[pos][sta][k]!=-1) return dp[pos][sta][k];
		ll res=0;
		int tmp;
		for(int i=(limt?p[pos]:9);~i;i--)
		{
			tmp=sta;
			if(i==0&&lead&&pos);
			else tmp^=(1<<i);
			res+=dfs(pos-1,lead&&i==0&&pos,tmp,limt&&i==p[pos]); 
		}
		if(!limt&&!lead) dp[pos][sta][k]=res;
		return res;
	};
	return dfs(sz(p)-1,1,0,1);
}
int main()
{
	int t,cas=1;
	ll k,l,r,ans,i;
	mem(dp,-1);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&k,&l,&r);
		printf("%lld\n",gao(r,k)-gao(l-1,k));
	}
	return 0;
} 
/*
100
0 1 1
*/