
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
/************* define end  *************/
void println(VI x){for(int i=0;i<sz(x);i++) printf("%d%c",x[i]," \n"[i==sz(x)-1]);}
void println(VL x){for(int i=0;i<sz(x);i++) printf("%lld%c",x[i]," \n"[i==sz(x)-1]);}
void println(int *x,int l,int r){for(int i=l;i<=r;i++) printf("%d%c",x[i]," \n"[i==r]);}
void println(ll *x,int l,int r){for(int i=l;i<=r;i++) printf("%lld%c",x[i]," \n"[i==r]);}
/*************** IO end  ***************/
void assert_lr(ll x,ll l,ll r) {assert(x>=l&&x<=r);};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=3e5+10;
const ll mod=998244353;
/*********************************  head  *********************************/

class Solution {
public:
    vector<vector<int>> sandyLandManagement(int size) {
		vector<vector<int>> res;
		int i,j;
		int f=1;
		for(i=size;i>=1;i-=2)
		{
			if(i==size)
			{
				for(j=1;j<=2*i-1;j+=2)
				{
					res.pb(VI{i,j});
				}
			}
			else
			{
				if(f) res.pb(VI{i+1,2});
				else res.pb(VI{i+1,1});
				
				if(i==1&&f) res.pb(VI{1,1});
				for(f==0?j=1:j=3;j<=2*i-1;j+=2) res.pb(VI{i,j});
				f^=1;
			}
		} 
		if(size%2==0) res.pb(VI{1,1});
		return res;
    }
};

