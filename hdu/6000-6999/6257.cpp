////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-05-04 23:52:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6257
////Problem Title: 
////Run result: Accept
////Run time:1326MS
////Run memory:14740KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
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
const int MAX=1e5+10;
const ll mod=1e9+7;
vector<int> mp[MAX];
int h[MAX],f[MAX];
void dfs(int x,int fa)
{
	int to,i,res=0,flag=0;
	h[x]=h[fa]+1;
	if(h[x]&1) res=INF;
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(to==fa) continue;
		flag=1;
		dfs(to,x);
		if(h[x]&1) res=min(res,f[to]);
		else res+=f[to];
	}
	if(!flag) f[x]=1;
	else f[x]=res;
}
int main()
{
	int t,a,b,i,ans,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		h[0]=0;
		dfs(1,0);
		printf("%d\n",f[1]);
	}
	return 0;
}