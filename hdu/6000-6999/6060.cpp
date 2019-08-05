////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-02 19:18:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6060
////Problem Title: 
////Run result: Accept
////Run time:1216MS
////Run memory:89108KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) a.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
struct node
{
	ll to,v;
	node(ll a,ll b):to(a),v(b){};
};
vector<node> mp[MAX];
ll k;
ll ans;
ll dfs(ll x,ll pre)
{
	ll i,w=0,sz=1;
	for(i=0;i<sz(mp[x]);i++)
	{
		if(mp[x][i].to==pre)
		{
			w=mp[x][i].v;
			continue;
		}
		sz+=dfs(mp[x][i].to,x);
	}
	ans+=(ll)sz>k?k*w:sz*w;
	return sz;
}
int main()
{
	ll n,i,a,b,v;
	while(~scanf("%lld%lld",&n,&k))
	{
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
		}
		for(i=1;i<n;i++)
		{
			scanf("%lld%lld%lld",&a,&b,&v);
			mp[a].pb(node(b,v));
			mp[b].pb(node(a,v));
		}
		ans=0;
		dfs(1,0);
		printf("%lld\n",ans);
	}
	return 0;
}
