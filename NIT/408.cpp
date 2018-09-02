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
const int MAX=2e4+10;
const ll mod=1e9+7;
vector<int> mp[MAX];
int ans[5001][5001];
int v[MAX],now[MAX],m;
void dfs(int x)
{
	int i;
	for(i=1;i<=m;i++)
	{
		if(now[i]) ans[i][v[x]]+=now[i];
	}
	now[v[x]]++;
	for(i=0;i<sz(mp[x]);i++)
	{
		dfs(mp[x][i]);
	}
	now[v[x]]--;
}
int main()
{
	int n,k,i,j,a,b;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<=m;i++)
		{
			now[i]=0;
			for(j=1;j<=m;j++)
			{
				ans[i][j]=0;
			}
		}
		scanf("%d",&v[1]);
		for(i=2;i<=n;i++)
		{
			scanf("%d%d",&a,&v[i]);
			mp[a].pb(i);
		}
		dfs(1);
		while(k--)
		{
			scanf("%d%d",&a,&b);
			printf("%d\n",ans[a][b]);
		}
	}
	return 0;
}