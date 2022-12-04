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
const int MAX=1e4+10;
const ll mod=1e9+7;

int flag[303][303];
int n,m;
void dfs(int x,int y,vector<vector<char>>& mp)
{
	if(x<0||x>=n||y<0||y>=m) return;
	if(flag[x][y]) return;
	if(mp[x][y]=='0') return;
	flag[x][y]=1;
	dfs(x+1,y,mp);
	dfs(x,y+1,mp);
	dfs(x-1,y,mp);
	dfs(x,y-1,mp);
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        mem(flag,0);
        int i,j;
        int ans=0;
        n=sz(grid);
        m=sz(grid[0]);
        for(i=0;i<n;i++)
        {
        	for(j=0;j<m;j++)
        	{
        		if(flag[i][j]) continue;
        		if(grid[i][j]=='0') continue;
        		dfs(i,j,grid);
        		ans++;
			}
		}
		return ans;
    }
};
