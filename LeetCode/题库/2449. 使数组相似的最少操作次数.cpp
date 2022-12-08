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
const int MAX=1e6+10;
const ll mod=998244353;
/*********************************  head  *********************************/
class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
    	int i;
    	VI a[2],b[2];
    	for(auto it:nums) a[it&1].pb(it);
    	for(auto it:target) b[it&1].pb(it);
        sort(all(a[0]));
        sort(all(a[1]));
        sort(all(b[0]));
        sort(all(b[1]));
        ll ans=0;
        for(i=0;i<sz(a[0]);i++)
        {
        	ans+=abs(a[0][i]-b[0][i])/2;
		}
		for(i=0;i<sz(a[1]);i++)
        {
        	ans+=abs(a[1][i]-b[1][i])/2;
		}
		return ans/2;
    }
};
