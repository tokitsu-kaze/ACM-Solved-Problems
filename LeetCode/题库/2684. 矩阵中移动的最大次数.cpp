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
int n,m,mp[1005][1005],dir[3][2]={-1,1,0,1,1,1};
int dp[1005][1005];
int dfs(int x,int y)
{
	if(dp[x][y]!=-1) return dp[x][y];
	int i,nx,ny,res;
	res=1;
	for(i=0;i<3;i++)
	{
		nx=x+dir[i][0];
		ny=y+dir[i][1];
		if(nx<1 || ny<1 || nx>n || ny>m) continue;
		if(mp[nx][ny]>mp[x][y]) res=max(res,dfs(nx,ny)+1);
	}
	return dp[x][y]=res;
}
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int i,j,ans;
        n=sz(grid);
        m=sz(grid[0]);
        for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				mp[i][j]=grid[i-1][j-1];
			}
		}
        ans=0;
		for(i=1;i<=n;i++)
		{
			ans=max(ans,dfs(i,1));
		}
		return ans-1;
    }
};
