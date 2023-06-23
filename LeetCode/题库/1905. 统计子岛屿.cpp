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
const int MAX=2e4+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int flag[505][505];
int n,m,ok;
void dfs(int x,int y,vector<vector<int>>& mp)
{
	if(x<0||x>=n||y<0||y>=m) return;
	if(mp[x][y]==0) return;
	mp[x][y]=0;
	if(!flag[x][y]) ok=0;
	flag[x][y]=1;
	dfs(x+1,y,mp);
	dfs(x,y+1,mp);
	dfs(x-1,y,mp);
	dfs(x,y-1,mp);
}
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
		int i,j;
        int ans=0;
        n=sz(grid1);
        m=sz(grid1[0]);
        mem(flag,0);
        for(i=0;i<n;i++)
        {
        	for(j=0;j<m;j++)
        	{
        		if(grid1[i][j]==0) continue;
        		dfs(i,j,grid1);
			}
		}
        for(i=0;i<n;i++)
        {
        	for(j=0;j<m;j++)
        	{
        		if(grid2[i][j]==0) continue;
        		ok=1;
        		dfs(i,j,grid2);
        		if(ok) ans++;
			}
		}
		return ans;
    }
};
