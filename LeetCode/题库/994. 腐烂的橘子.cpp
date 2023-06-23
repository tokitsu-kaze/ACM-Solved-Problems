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
struct node{int x,y;};
int dir[4][2]={0,1,1,0,0,-1,-1,0};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
		int i,j,n,m,sz;
		n=sz(grid);
		m=sz(grid[0]);
		queue<node> q;
		VVI ans(n,VI(m,-0x3f));
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(grid[i][j]==2)
				{
					q.push({i,j});
					ans[i][j]=0;
				}
				else if(grid[i][j]==0) ans[i][j]=0;
			}
		}
		while(!q.empty())
		{
			sz=sz(q);
			while(sz--)
			{
				node t=q.front();
				q.pop();
				for(i=0;i<4;i++)
				{
					node nex=t;
					nex.x+=dir[i][0];
					nex.y+=dir[i][1];
					if(nex.x<0||nex.x>=n||nex.y<0||nex.y>=m) continue;
					if(grid[nex.x][nex.y]!=1) continue;
					grid[nex.x][nex.y]++;
					ans[nex.x][nex.y]=ans[t.x][t.y]+1;
					q.push(nex);
				}
			}
		}
		int mx=-1;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(grid[i][j]==1) return -1;
				mx=max(mx,ans[i][j]);
			}
		}
		return mx;
    }
};
