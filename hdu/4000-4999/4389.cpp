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
const int MAX=1e6+10;
const ll mod=998244353;
/****************************************  head  ****************************************/
int dp[11][82][82][82];
int gao(int x,int md)
{
	vector<int> p;
	if(x==-1) return 0;
	while(1)
	{
		p.pb(x%10);
		x/=10;
		if(!x) break;
	}
	function<int(int,int,int,int,int)> dfs=[&](int pos,int lead,int sta,int limt,int now)->int
	{
		if(pos==-1) return now==md&&sta==0;
		if(!limt&&!lead&&dp[pos][sta][now][md]!=-1) return dp[pos][sta][now][md];
		int res=0;
		for(int i=(limt?p[pos]:9);~i;i--)
		{
			res+=dfs(pos-1,lead&&i==0&&pos,(sta*10+i)%md,limt&&i==p[pos],now+i); 
		}
		if(!limt&&!lead) dp[pos][sta][now][md]=res;
		return res;
	};
	return dfs(sz(p)-1,1,0,1,0);
}
int main()
{
	int t,cas=1;
	scanf("%d",&t);
	mem(dp,-1);
	int l,r,ans,i;
	while(~scanf("%d%d",&l,&r))
	{
		ans=0;
		for(i=1;i<=81;i++) ans+=gao(r,i)-gao(l-1,i);
		printf("Case %d: %d\n",cas++,ans);
	}
	return 0;
}
