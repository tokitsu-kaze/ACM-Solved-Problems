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
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=6e3+10;
const ll mod=1e9+7;
vector<int> mp[MAX];
int v[MAX],dp[MAX][2];
void dfs(int x,int pre)
{
	int i,to;
	dp[x][1]=v[x];
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(to!=pre)
		{
			dfs(to,x);
			dp[x][0]+=max(dp[to][1],dp[to][0]);
			dp[x][1]+=dp[to][0];
		}
	}
}
int main()
{
	int n,i,a,b;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			mp[i].clear();
		}
		while(~scanf("%d%d",&a,&b)&&a+b)
		{
			mp[a].pb(b);
			mp[b].pb(a);
		}
		mem(dp,0);
		dfs(1,0);
		printf("%d\n",max(dp[1][0],dp[1][1]));
	}
	return 0;
}