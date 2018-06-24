////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-29 18:31:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4705
////Problem Title: 
////Run result: Accept
////Run time:405MS
////Run memory:13304KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
vector <ll> mp[MAX];
ll ans,n;
ll dfs(ll x,ll pre)
{
	ll i,sz=0,temp;
	for(i=0;i<mp[x].size();i++)
	{
		if(mp[x][i]==pre) continue;
		temp=dfs(mp[x][i],x);
		sz+=temp;
		ans+=temp*(n-sz-1);
	}
	return sz+1;
}
int main()
{
	ll i,a,b;
	while(~scanf("%lld",&n))
	{
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		ans=0;
		dfs(1,0);
	//	cout<<ans<<endl;
		printf("%lld\n",n*(n-1)*(n-2)/6-ans);
	} 
	return 0;
}