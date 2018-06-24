////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-01-10 14:36:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2063
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1716KB
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
const double eps=1e-8;
const int MAX=5e2+10;
const ll mod=1e9+7;
vector<int> mp[MAX];
int link[MAX],used[MAX];
int dfs(int x)
{
	int i,to;
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(!used[to])
		{
			used[to]=1;
			if(link[to]==-1||dfs(link[to]))
			{
				link[to]=x;
				return 1;
			}
		}
	}
	return 0;
}
int hungary(int n)
{
	mem(link,-1);
	int i,res=0;
	for(i=1;i<=n;i++)
	{
		mem(used,0);
		if(dfs(i)) res++;
	}
	return res;
}
int main()
{
	int m,n,k,a,b,i;
	while(~scanf("%d",&m)&&m)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) mp[i].clear();
		while(m--)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
		}
		printf("%d\n",hungary(n));
	}
	return 0;
}