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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
vector<int> mp[MAX];
vector<PII> res;
int in[MAX],rt,flag;
void dfs(int x,int fa)
{
	int tag=0;
	if(x!=rt&&sz(mp[x])>2) flag=1;
	for(auto to:mp[x])
	{
		if(to==fa) continue;
		tag=1;
		dfs(to,x);
	}
	if(!tag) res.pb(MP(rt,x));
}
int main()
{
	int n,i,a,b;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++) mp[i].clear(),in[i]=0;
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
			in[a]++;
			in[b]++;
		}
		rt=1;
		for(i=1;i<=n;i++)
		{
			if(in[i]>=3) rt=i;
		}
		res.clear();
		flag=0;
		dfs(rt,-1);
		if(flag)
		{
			puts("No");
			continue;
		}
		puts("Yes");
		printf("%d\n",sz(res));
		for(i=0;i<sz(res);i++) printf("%d %d\n",res[i].fi,res[i].se);
	}
	return 0;
}