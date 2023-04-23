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
const int MAX=100+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct Dijkstra
{
	#define type int
	#define inf INF
	#define PTI pair<type,int>
	static const int N=MAX;
	vector<pair<int,type> > mp[N];
	type dis[N];
	int n,vis[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int x,int y,type v){ mp[x].pb(MP(y,v));}
	void work(int s)
	{
		int i,to;
		type w;
		priority_queue<PTI ,vector<PTI>,greater<PTI> > q;
		for(i=0;i<=n;i++)
		{
			dis[i]=inf;
			vis[i]=0;
		}
		dis[s]=0;
		q.push(MP(type(0),s));
		while(!q.empty())
		{
			PTI t=q.top();
			q.pop();
			if(vis[t.se]) continue;
			vis[t.se]=1;
			for(auto it:mp[t.se])
			{
				to=it.fi;
				w=it.se;
				if(dis[to]>dis[t.se]+w)
				{
					dis[to]=dis[t.se]+w;
					if(!vis[to]) q.push(MP(dis[to],to));
				}
			}
		}
	}
	#undef type
	#undef inf
	#undef PTI
}dij;
class Graph {
public:
    Graph(int n, vector<vector<int>>& edges) {
		dij.init(n);
		for(auto &it:edges)
		{
			dij.add_edge(it[0]+1,it[1]+1,it[2]);
		}
    }
    
    void addEdge(vector<int> edge) {
		dij.add_edge(edge[0]+1,edge[1]+1,edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
		dij.work(node1+1);
		if(dij.dis[node2+1]==INF) return -1;
		return dij.dis[node2+1];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
