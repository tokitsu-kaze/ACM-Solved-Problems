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
int flag[MAX];
void dfs(int x)
{
	int i,to;
	flag[x]=1;
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(flag[to]) continue;
		dfs(to);
	}
}
int main()
{
	int t,n,m,i,a,b,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
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
			if(!flag[i])
			{
				dfs(i);
				ans++;
			}
		}
		printf("%d\n",ans-1);
	}
	return 0;
}