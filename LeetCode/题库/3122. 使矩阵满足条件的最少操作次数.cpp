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
int cnt[1010][12],dp[1010][12];
class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int i,j,k,n,m;
        n=sz(grid);
        m=sz(grid[0]);
        for(j=0;j<=m+1;j++)
        {
        	mem(cnt[j],0);
        	mem(dp[j],0x3f);
		}
        for(j=0;j<m;j++)
        {
        	for(i=0;i<n;i++)
        	{
        		cnt[j+1][grid[i][j]]++;
			}
		}
		for(j=0;j<=9;j++) dp[1][j]=n-cnt[1][j];
		for(i=1;i<=m;i++)
		{
			for(j=0;j<=9;j++)
			{
				for(k=0;k<=9;k++)
				{
					if(j==k) continue;
					dp[i][j]=min(dp[i][j],dp[i-1][k]+n-cnt[i][j]);
				}
			}
		}
		int ans=INF;
		for(i=0;i<=9;i++) ans=min(ans,dp[m][i]);
		return ans;
    }
};
/*
[[4,2,2],[8,2,5],[1,5,2]]
*/
