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
typedef vector<string> VS;
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
const int MAX=2e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        map<string,ll> mp;
         map<string,ll> mxm;
        map<pair<string,ll>,string> id;
        int i;
		for(i=0;i<sz(creators);i++)
		{
			mp[creators[i]]+=views[i];
			mxm[creators[i]]=max(mxm[creators[i]],1ll*views[i]);
			if(id.count(MP(creators[i],views[i]))) id[MP(creators[i],views[i])]=min(ids[i],id[MP(creators[i],views[i])]);
			else id[MP(creators[i],views[i])]=ids[i];
		}
		ll mx=0;
		for(auto it:mp) mx=max(mx,it.se);
		vector<vector<string>> res;
		for(auto it:mp)
		{
			if(it.se==mx)
			{
				res.pb(VS{it.fi,id[MP(it.fi,mxm[it.fi])]});
			}
		}
		return res;
    }
};
