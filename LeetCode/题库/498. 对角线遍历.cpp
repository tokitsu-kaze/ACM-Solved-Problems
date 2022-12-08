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
const int MAX=2e4+10;
const ll mod=1e9+7;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
		VI res;
		int f=1;
		int x,y,n,m;
		n=sz(mat);
		m=sz(mat[0]);
		x=y=0;
		while(x<n&&y<m)
		{
			while(x>=0&&y>=0&&x<n&&y<m)
			{
				res.pb(mat[x][y]);
				x-=f;
				y+=f;
			}
			x+=f;
			y-=f;
			if(f==1) y++;
			else x++;
			if(y>=m)
			{
				y--;
				x++;
			}
			else if(x>=n)
			{
				x--;
				y++;
			}
			f*=-1;
		}
		return res;
    }
};
