#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define len(x) (int) x.length()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
ll dp[22][22];
vector<int> p;
ll dfs(int pos,int lead,int sta,int limt)
{
	if(pos==-1) return sta;
	if(!limt&&!lead&&dp[pos][sta]!=-1) return dp[pos][sta];
	ll res=0;
	for(int i=(limt?p[pos]:9);~i;i--)
	{
		res+=dfs(pos-1,lead&&i==0&&pos,sta+((!lead||!pos)&&i==0),limt&&i==p[pos]); 
	}
	if(!limt&&!lead) dp[pos][sta]=res;
	return res;
}
ll gao(ll x)
{
	if(x==-1) return 0;
	p.clear();
	while(1)
	{
		p.pb(x%10);
		x/=10;
		if(!x) break;
	}
	return dfs(sz(p)-1,1,0,1);
}
int main()
{
	ll l,r;
	mem(dp,-1);
	while(~scanf("%lld%lld",&l,&r)&&~l&&~r)
	{
		printf("%lld\n",gao(r)-gao(l-1));
	}
	return 0;
}