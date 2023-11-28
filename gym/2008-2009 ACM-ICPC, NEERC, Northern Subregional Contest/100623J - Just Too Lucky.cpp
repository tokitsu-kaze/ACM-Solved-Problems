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
const int DIG=20+2;
ll dp[DIG][111][111][111];
ll gao(ll x,ll md)
{
	const int base=10;
	int p[DIG],tot=0;
	if(x==-1) return 0;
	while(1)
	{
		p[tot++]=x%base;
		x/=base;
		if(!x) break;
	}
	function<ll(int,int,int,int,int)> dfs=[&](int pos,int lead,int sta,int limt,int now)->ll
	{
		if(pos==-1) return !lead&&!sta&&now==md;
		if(!limt&&!lead&&dp[pos][sta][md][now]!=-1) return dp[pos][sta][md][now];
		ll res=0;
		for(int i=(limt?p[pos]:base-1);~i;i--)
		{
			res+=dfs(pos-1,lead&&i==0&&pos,(sta*10+i)%md,limt&&i==p[pos],now+i); 
		}
		if(!limt&&!lead) dp[pos][sta][md][now]=res;
		return res;
	};
	return dfs(tot-1,1,0,1,0);
}
int main()
{
	freopen("just.in", "r", stdin);
	freopen("just.out", "w", stdout);
	mem(dp,-1);
	ll n,ans,i;
	while(~scanf("%lld",&n))
	{
		ans=0;
		for(i=1;i<=108;i++) ans+=gao(n,i);
		printf("%lld\n",ans);
	}
	return 0;
}