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
const int MAX=1e4+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct node{int x,c;};
vector<node> mp[105];
int dis[105][2];
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        int i;
        for(i=0;i<=n;i++) mp[i].clear();
        for(auto &it:redEdges) mp[it[0]].pb({it[1],0});
        for(auto &it:blueEdges) mp[it[0]].pb({it[1],1});
        mem(dis,0x3f);
        queue<node> q;
        dis[0][0]=dis[0][1]=0;
        for(auto &to:mp[0])
        {
        	q.push({to.x,to.c});
        	dis[to.x][to.c]=min(dis[to.x][to.c],1);
		}
    	while(!q.empty())
    	{
    		node t=q.front();
    		q.pop();
    		for(auto &to:mp[t.x])
    		{
    			if(to.c==t.c) continue;
    			if(dis[to.x][to.c]>dis[t.x][t.c]+1)
    			{
    				dis[to.x][to.c]=dis[t.x][t.c]+1;
    				q.push(to);
				}
			}
		}
		VI ans(n,-1);
		for(i=0;i<n;i++)
		{
			int res=min(dis[i][0],dis[i][1]);
			if(res!=INF) ans[i]=res;
		}
		return ans;
    }
};
