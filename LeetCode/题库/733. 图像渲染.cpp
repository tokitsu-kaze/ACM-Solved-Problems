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
const int MAX=2e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    	int dir[4][2]={0,1,1,0,0,-1,-1,0};
    	int flag[55][55]={0};
    	int tmpc=image[sr][sc];
        queue<PII > q;
        q.push(MP(sr,sc));
        flag[sr][sc]=1;
        while(!q.empty())
        {
        	PII t=q.front();
        	q.pop();
        	image[t.fi][t.se]=color;
        	for(int i=0;i<4;i++)
        	{
        		PII nex=t;
        		nex.fi+=dir[i][0];
        		nex.se+=dir[i][1];
        		if(nex.fi<0 || nex.fi>=sz(image) || nex.se<0 || nex.se>=sz(image[0])) continue;
        		if(flag[nex.fi][nex.se]) continue;
        		if(image[nex.fi][nex.se]!=tmpc) continue;
        		q.push(nex);
        		flag[nex.fi][nex.se]=1;
			}
		}
		return image;
    }
};
