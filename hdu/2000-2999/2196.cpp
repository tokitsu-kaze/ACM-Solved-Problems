////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-28 20:00:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2196
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:2336KB
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
const int MAX=1e4+10;
const ll mod=2008;
struct node
{
	int to,w;
	node(int a,int b):to(a),w(b){}
};
vector<node> mp[MAX];
int s,maxx,dp[MAX];
void dfs(int x,int pre,int len)
{
	int i,to;
	if(len>maxx)
	{
		maxx=len;
		s=x;
	}
	dp[x]=max(dp[x],len);
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i].to;
		if(to!=pre)
		{
			dfs(to,x,len+mp[x][i].w);
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
			mp[i].clear();
			dp[i]=0;
		}
		for(i=2;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[i].pb(node(a,b));
			mp[a].pb(node(i,b));
		}
		maxx=0;
		s=1;
		dfs(1,0,0);
		dfs(s,0,0);
		dfs(s,0,0);
		for(i=1;i<=n;i++)
		{
			printf("%d\n",dp[i]);
		}
	}
	return 0;
}