#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define sqr(x) ((x)*(x))
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
/************* define end  *************/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
/********* gp_hash_table end  **********/
void println(VI x){for(int i=0;i<sz(x);i++) printf("%d%c",x[i]," \n"[i==sz(x)-1]);}
void println(VL x){for(int i=0;i<sz(x);i++) printf("%lld%c",x[i]," \n"[i==sz(x)-1]);}
void println(int *x,int l,int r){for(int i=l;i<=r;i++) printf("%d%c",x[i]," \n"[i==r]);}
void println(ll *x,int l,int r){for(int i=l;i<=r;i++) printf("%lld%c",x[i]," \n"[i==r]);}
/*************** IO end  ***************/
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
//O(nlogn)-O(logn) 
struct LCA
{
	int fa[MAX][22],dep[MAX],n,limt,bin[22];
	VI mp[MAX];
	void init(int _n)
	{
		n=_n;
		for(limt=1;1<<(limt-1)<=n;limt++);
		for(int i=bin[0]=1;1<<(i-1)<=n;i++) bin[i]=(bin[i-1]<<1);
		for(int i=0;i<=n;i++)
		{
			mp[i].clear();
			mem(fa[i],0);
		}
	}
	void add_edge(int a,int b)
	{
		mp[a].pb(b);
		mp[b].pb(a);
	}
	void dfs(int x,int pre)
	{
		for(int i=1;bin[i]<=dep[x];i++) fa[x][i]=fa[fa[x][i-1]][i-1];
		for(int i=0;i<sz(mp[x]);i++)
		{
			int to=mp[x][i];
			if(to==pre) continue;
			dep[to]=dep[x]+1;
			fa[to][0]=x;
			dfs(to,x);
		}
	}
	void work(int rt)
	{
		dep[rt]=0;
		dfs(rt,0);
	}
	int go(int x,int d)
	{
		for(int i=0;i<=limt&&d;i++)
		{
			if(bin[i]&d)
			{
				d^=bin[i];
				x=fa[x][i];
			}
		}
		return x;
	}
	int lca(int a,int b)
	{
		if(dep[a]<dep[b]) swap(a,b);
		a=go(a,dep[a]-dep[b]);
		if(a==b) return a;
		for(int i=limt;~i;i--)
		{
			if(fa[a][i]!=fa[b][i])
			{
				a=fa[a][i];
				b=fa[b][i];
			}
		}
		return fa[a][0];
	}
}lca;
class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {
		lca.init(n);
		for(int i=1;i<n;i++) lca.add_edge(parent[i],i);
		lca.work(0);
    }
    
    int getKthAncestor(int node, int k) {
    	if(lca.dep[node]<k) return -1;
		return lca.go(node,k);
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
