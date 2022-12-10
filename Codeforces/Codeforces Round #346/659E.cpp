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
const int MAX=1e5+10;
const ll mod=1e9+7;
vector<int> mp[MAX];
int tag,flag[MAX];
void dfs(int x,int fa)
{
	int i,to;
	if(flag[x])
	{
		tag=0;
		return;
	}
	flag[x]=1;
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(to==fa) continue;
		dfs(to,x);
	}
}
int main()
{
	int n,m,i,a,b,ans;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=n;i++) mp[i].clear();
		while(m--)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		mem(flag,0);
		ans=0;
		for(i=1;i<=n;i++)
		{
			if(flag[i]) continue;
			tag=1;
			dfs(i,-1);
			ans+=tag;
		}
		printf("%d\n",ans);
	}
	return 0;
}