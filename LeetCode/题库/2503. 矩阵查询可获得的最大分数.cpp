#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef vector<string> VS;
/************* define end  *************/
void println(VI x){for(int i=0;i<sz(x);i++) printf("%d%c",x[i]," \n"[i==sz(x)-1]);}
void println(VL x){for(int i=0;i<sz(x);i++) printf("%lld%c",x[i]," \n"[i==sz(x)-1]);}
void println(int *x,int l,int r){for(int i=l;i<=r;i++) printf("%d%c",x[i]," \n"[i==r]);}
void println(ll *x,int l,int r){for(int i=l;i<=r;i++) printf("%lld%c",x[i]," \n"[i==r]);}
/*************** IO end  ***************/
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        VI ans(sz(queries),0);
    	VPII qst;
    	int i=0;
    	for(auto &it:queries)
    	{
    		qst.pb(MP(it,i));
    		i++;
		}
		sort(all(qst));
		int n,m;
		n=sz(grid);
		m=sz(grid[0]);
		vector<VI> flag(n,VI(m,0));
		priority_queue<pair<int,PII> > q;
		q.push(MP(-grid[0][0],MP(0,0)));
		flag[0][0]=1;
		int now=0;
		int dir[4][2]={0,1,1,0,0,-1,-1,0};
		for(auto it:qst)
		{
			while(!q.empty())
			{
				auto t=q.top();
				if(it.fi<=-t.fi) break;
				q.pop();
				now++;
				for(i=0;i<4;i++)
				{
					int x=t.se.fi+dir[i][0];
					int y=t.se.se+dir[i][1];
					if(x<0||y<0||x>=n||y>=m) continue;
					if(flag[x][y]) continue;
					q.push(MP(-grid[x][y],MP(x,y)));
					flag[x][y]=1;
				}
			}
			ans[it.se]=now;
		}
		return ans;
    }
};
