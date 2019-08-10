#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <bitset>
#include <limits>
#include <assert.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
void go();
int main(){
	#ifdef tokitsukaze
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct Bipartite_Matching
{
	static const int N=200+10;
	int n,m;
	VI mp[N];
	int link[N],s[N];
	bool used[N],flag[N];
	void init(int _n,int _m)
	{
		n=_n;
		m=_m;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int a,int b){mp[a].pb(b);}
	int ban[N];
	bool dfs(int x)
	{
		int i,to;
		flag[x]=1;
		for(i=0;i<sz(mp[x]);i++)
		{
			to=mp[x][i];
			if(used[to]) continue;
			if(ban[to]) continue;
			used[to]=1;
			if(link[to]==-1||dfs(link[to]))
			{
				link[to]=x;
				s[x]=to;
				return 1;
			}
		}
		return 0;
	}
	int max_match()
	{
		int i,res;
		mem(link,-1);
		mem(s,-1);
		res=0;
		for(i=1;i<=n;i++)
		{
			if(ban[i]) continue;
			if(!sz(mp[i])) continue;
			mem(used,0);
			if(dfs(i)) res++;
		}
		return res;
	}
	int min_cover(VI &x,VI &y)
	{
		int i,res;
		res=max_match();
		mem(flag,0);
		mem(used,0);
		x.clear();
		y.clear();
		for(i=1;i<=n;i++)
		{
			if(s[i]==-1) dfs(i);
		}
		for(i=1;i<=n;i++)
		{
			if(!flag[i]) x.pb(i);
		}
		for(i=1;i<=m;i++)
		{
			if(used[i]) y.pb(i);
		}
		return res;
	}
}bpm;
int col[222];
void go()
{
	int t,n,m,i,a,b,res,tmp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		bpm.init(n,n);
		for(i=1;i<=n;i++) scanf("%d",&col[i]);
		while(m--)
		{
			scanf("%d%d",&a,&b);
			a++;
			b++;
			if(col[a]!=col[b])
			{
				if(col[a]==0) bpm.add_edge(a,b);
				else bpm.add_edge(b,a);
			}
		}
		mem(bpm.ban,0);
		res=bpm.max_match();
		VI ans;
		for(i=1;i<=n;i++)
		{
			bpm.ban[i]=1;
			tmp=bpm.max_match();
			if(tmp<res)
			{
				ans.pb(i-1);
				res=tmp;
			}
			else bpm.ban[i]=0;
		}
		printf("%d",sz(ans));
		for(i=0;i<sz(ans);i++) printf(" %d",ans[i]);
		puts("");
	}
}
