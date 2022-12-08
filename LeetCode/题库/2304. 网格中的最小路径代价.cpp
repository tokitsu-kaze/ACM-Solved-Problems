#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII > VPII;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;

int dp[111][111];
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        mem(dp,0x3f);
        int i,j,k;
		for(i=0;i<sz(grid);i++)
		{
			for(j=0;j<sz(grid[i]);j++)
			{
				if(i==0)
                {
                    dp[i][j]=grid[i][j];
                    continue;
                }
				for(k=0;k<sz(grid[i]);k++)
				{
					dp[i][j]=min(dp[i][j],grid[i][j]+dp[i-1][k]+moveCost[grid[i-1][k]][j]);
				}
                printf("%d %d %d\n",i,j,dp[i][j]);
			}
		}
        int mn=INF;
        for(i=0;i<sz(grid[0]);i++) mn=min(mn,dp[sz(grid)-1][i]);
		return mn;
    }
};
