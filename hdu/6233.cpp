////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-11-11 19:27:26
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6233
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1808KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e3+10;
const ll mod=1e9+7;
vector<int> mp[MAX];
int be,ans,flag[MAX];
void dfs(int x,int pre,int now)
{
	int i,to;
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(to==pre) continue;
		dfs(to,x,now+1);
	}
	if(now>ans&&flag[x])
	{
		ans=now;
		be=x;
	}
}
int main()
{
	int t,n,m,x,i,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) mp[i].clear();
		mem(flag,0);
		while(m--)
		{
			scanf("%d",&x);
			flag[x]=1;
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		ans=0;
		dfs(1,0,0);
		ans=0;
		dfs(be,0,0);
		printf("%d.00\n",ans/2);
	}
	return 0;
}
