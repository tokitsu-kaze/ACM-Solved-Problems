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
const int MAX=1e5+10;
const ll mod=1e9+7;
int res[MAX],ans;
vector<int> mp[MAX];
void dfs(int x,int fa,int pre)
{
	int i,to,ne=pre;
	if(res[x]!=pre) ne=res[x],ans++;
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(to==fa) continue;
		dfs(to,x,ne);
	}
}
int main()
{
	int i,x,n;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=2;i<=n;i++)
		{
			scanf("%d",&x);
			mp[x].pb(i);
			mp[i].pb(x);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&res[i]);
		}
		ans=0;
		dfs(1,-1,0);
		printf("%d\n",ans);
	}
	return 0;
}