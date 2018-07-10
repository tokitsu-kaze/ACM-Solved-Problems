#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=2e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
int dis[MAX],n,k;
char s[MAX];
vector<string> res;
vector<PII > mp[MAX];
void bfs()
{
	int x;
	queue<int> q;
	mem(dis,-1);
	dis[1]=0;
	q.push(1);
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(auto to:mp[x])
		{
			if(dis[to.fi]==-1)
			{
				dis[to.fi]=dis[x]+1;
				q.push(to.fi);
			}
		}
	}
}
void dfs(int x)
{
	if(x==n+1)
	{
		res.pb(s);
		return;
	}
	for(auto to:mp[x])
	{
		if(dis[to.fi]+1==dis[x])
		{
			s[to.se]='1';
			dfs(x+1);
			s[to.se]='0';
			if(sz(res)==k) return;
		}
	}
}
int main()
{
	int m,i,a,b;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=0;i<m;++i)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(MP(b,i));
			mp[b].pb(MP(a,i));
		}
		bfs();
		for(i=0;i<m;++i) s[i]='0';
		dfs(2);
		printf("%d\n",sz(res));
		for(i=0;i<sz(res);i++) cout<<res[i]<<"\n";
	}
	return 0;
}