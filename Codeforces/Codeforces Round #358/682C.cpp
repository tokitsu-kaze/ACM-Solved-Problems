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
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e6;
vector<ll> mp[MAX];
map<pair<ll,ll>,ll> w;
ll v[MAX],cnt;
ll dfs(ll x,ll now)
{
	ll i,temp=0,tnow;
	
	for(i=0;i<mp[x].size();i++)
	{
		tnow=now+w[MP(x,mp[x][i])];
		if(tnow<0) tnow=0;
		temp+=dfs(mp[x][i],tnow);
	}
	if(now>v[x])
	{
//		cout<<now<<" "<<v[x]<<" "<<x<<endl;
		cnt+=temp+1;
		return 0;
	}
	return temp+1;
}
int main()
{
	ll n,i,j,temp;
	while(~scanf("%lld",&n))
	{
		cnt=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&v[i]);
			mp[i].clear();
		}
		for(i=2;i<=n;i++)
		{
			scanf("%lld%lld",&j,&temp);
			mp[j].pb(i);
			w[MP(i,j)]=temp;
			w[MP(j,i)]=temp;
		}
		dfs(1,0);
		printf("%lld\n",cnt);
	}
	return 0;
}