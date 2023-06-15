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
int dis[105][105];
int dir[8][2]={0,1,1,0,0,-1,-1,0,1,1,1,-1,-1,1,-1,-1};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    	if(grid[0][0]==1) return -1;
		int i,n,m;
		n=sz(grid);
		m=sz(grid[0]);
		mem(dis,0x3f);
		queue<PII> q;
		q.push({0,0});
		dis[0][0]=0;
		while(!q.empty())
		{
			auto t=q.front();
			q.pop();
			for(i=0;i<8;i++)
			{
				auto nex=t;
				nex.fi+=dir[i][0];
				nex.se+=dir[i][1];
				if(nex.fi<0||nex.fi>=n||nex.se<0||nex.se>=m) continue;
				if(grid[nex.fi][nex.se]==1) continue;
				if(dis[nex.fi][nex.se]>dis[t.fi][t.se]+1)
				{
					dis[nex.fi][nex.se]=dis[t.fi][t.se]+1;
					q.push(nex);
				}
			}
		}
		if(dis[n-1][m-1]==INF) return -1;
		return dis[n-1][m-1]+1;
    }
};
