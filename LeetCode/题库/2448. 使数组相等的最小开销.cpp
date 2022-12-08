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
const int MAX=1e5+10;
const ll mod=998244353;
/*********************************  head  *********************************/
ll bit[MAX],bitres[MAX];
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<PLL > res;
        int i;
        for(i=0;i<sz(nums);i++) res.pb(MP(nums[i],cost[i]));
        sort(all(res));
        bit[0]=bitres[0]=0;
        for(i=1;i<=sz(res);i++)
        {
        	bit[i]=bit[i-1]+res[i-1].se;
        	bitres[i]=bitres[i-1]+res[i-1].fi*res[i-1].se;
		}
		ll ans=LLINF,now;
		for(i=1;i<=sz(res);i++)
		{
			now=res[i-1].fi*bit[i-1]-bitres[i-1];
			now+=(bitres[sz(res)]-bitres[i])-res[i-1].fi*(bit[sz(res)]-bit[i]);
			ans=min(ans,now);
		}
		return ans;
    }
};
