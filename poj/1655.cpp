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
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define sqr(x) ((x)*(x))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VS> VVS;
typedef vector<VPII> VVPII;
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
const int MAX=2e4+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct Tree_Centroid
{
	VI centroid;
	int sz[MAX],w[MAX],n;
	void dfs(VI *mp,int x,int fa)
	{
		sz[x]=1;
		w[x]=0;
		for(int i=0;i<sz(mp[x]);i++)
		{
			int to=mp[x][i];
			if(to==fa) continue;
			dfs(mp,to,x);
			sz[x]+=sz[to];
			w[x]=max(w[x],sz[to]);
		}
		w[x]=max(w[x],n-sz[x]);
		if(w[x]<=n/2) centroid.pb(x);
	}
	VI get_tree_centroid(int _n,VI *mp,int root)
	{
		n=_n;
		centroid.clear();
		dfs(mp,root,0);
		return centroid;
	}
}trct;
VI mp[MAX];
void go()
{
	int t,n,i,a,b;
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
		VI res=trct.get_tree_centroid(n,mp,1);
		printf("%d %d\n",res[0],trct.w[res[0]]);
	}
}
