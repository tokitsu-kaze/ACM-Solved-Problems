////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-26 19:04:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1520
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:2080KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
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
int v[MAX],dp[MAX][2],ans;
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
			ans=max(ans,max(dp[x][0],dp[x][1]));
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
		ans=-INF;
		mem(dp,0);
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}