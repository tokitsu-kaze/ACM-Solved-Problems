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
#include <assert.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define len(x) (int) x.length()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
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
const int MAX=1e6+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct Maximum_Clique
{
	static const int N=110;
	vector<int> sol;
	int mp[N][N/30+1],s[N][N/30+1];
	int n,ans,dp[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++)
		{
			dp[i]=0;
			mem(mp[i],0);
		}
	}
	void add_edge(int a,int b) //0~n-1
	{
		if(a>b) swap(a,b);
		if(a==b) return;
		mp[a][b/32]|=(1<<(b%32));
	}
	bool dfs(int x,int k)
	{
		int c=0,d=0;
		for(int i=0;i<(n+31)/32;i++)
		{
			s[k][i]=mp[x][i];
			if(k!=1) s[k][i]&=s[k-1][i];
			c+=__builtin_popcount(s[k][i]);
		}
		if(c==0)
		{
			if(k>ans)
			{
				ans=k;
				sol.clear();
				sol.pb(x);
				return 1;
			}
			return 0;
		}
		for(int i=0;i<(n+31)/32;i++)
		{
			for(int a=s[k][i];a;d++)
			{
				if(k+(c-d)<=ans) return 0;
				int lb=a&(-a),lg=0;
				a^=lb;
				while(lb!=1)
				{
					lb=(unsigned int)(lb)>>1;
					lg++;
				}
				int u=i*32+lg;
				if(k+dp[u]<=ans) return 0;
				if(dfs(u,k+1))
				{
					sol.pb(x);
					return 1;
				}
			}
		}
		return 0;
	}
	int maximum_clique()
	{
		ans=0;
		for(int i=n-1;i>=0;i--)
		{
			dfs(i,1);
			dp[i]=ans;
		}
		return ans;
	}
}mcp;
/*
undirected graph
mcp.init(n);
mcp.add_edge(a,b); a,b: 0~n-1
*/
int mp[101][101];
void go()
{
	int t,n,m,i,j,a,b;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d%d",&n,&m);
			mcp.init(n);
			mem(mp,0);
			while(m--)
			{
				scanf("%d%d",&a,&b);
				a--;
				b--;
				mp[a][b]=mp[b][a]=1;
			}
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(i==j) continue;
					if(mp[i][j]) continue;
					mcp.add_edge(i,j);
				}
			}
			printf("%d\n",mcp.maximum_clique());
			for(i=0;i<sz(mcp.sol);i++) printf("%d%c",mcp.sol[i]+1," \n"[i==sz(mcp.sol)-1]);
			if(t) puts("");
		}
	}
}
