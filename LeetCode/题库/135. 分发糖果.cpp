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
int a[MAX];
class Solution {
public:
    int candy(vector<int>& ratings) {
		mem(a,0);
		VPII res;
		int i;
		for(i=1;i<=sz(ratings);i++) res.pb(MP(ratings[i-1],i));
		sort(all(res));
		for(auto it:res)
		{
			a[it.se]=1;
			if(it.se-2>=0 && ratings[it.se-1]>ratings[it.se-2]) a[it.se]=max(a[it.se-1]+1,a[it.se]);
			if(it.se<sz(ratings) && ratings[it.se-1]>ratings[it.se]) a[it.se]=max(a[it.se+1]+1,a[it.se]);
		}
		int ans=0;
		for(i=1;i<=sz(ratings);i++) ans+=a[i];
		return ans;
    }
};
