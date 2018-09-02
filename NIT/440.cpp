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
ll dp[19][1025][11][11];
ll gao(ll x,int md)
{
	vector<int> p;
	if(x==-1) return 0;
	while(1)
	{
		p.pb(x%10);
		x/=10;
		if(!x) break;
	}
	function<ll(int,int,int,int,ll)> dfs=[&](int pos,int lead,int sta,int limt,ll now)->ll
	{
		int tmp=__builtin_popcount(sta);
		if(tmp+pos+1<md) return 0;
		if(tmp>md) return 0;
		if(pos==-1) return tmp==md&&now==0;
		if(!limt&&!lead&&dp[pos][sta][now][md]!=-1) return dp[pos][sta][now][md];
		ll res=0;
		for(int i=(limt?p[pos]:9);~i;i--)
		{
			if(lead&&i==0&&pos) tmp=sta;
			else tmp=(sta|(1<<i));
			res+=dfs(pos-1,lead&&i==0&&pos,tmp,limt&&i==p[pos],(now*10+i)%md); 
		}
		if(!limt&&!lead) dp[pos][sta][now][md]=res;
		return res;
	};
	return dfs(sz(p)-1,1,0,1,0);
}
int main()
{
	ll l,r;
	int t;
	scanf("%d",&t);
	mem(dp,-1);
	while(t--)
	{
		scanf("%lld%lld",&l,&r);
		ll ans=0;
		for(int i=1;i<=10;i++) ans+=gao(r,i)-gao(l-1,i);
		printf("%lld\n",ans);
	}
	return 0;
} 