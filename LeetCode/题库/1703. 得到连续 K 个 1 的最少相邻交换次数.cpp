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
    int minMoves(vector<int>& nums, int k) {
		VI res;
		int i=0;
		for(auto &it:nums)
		{
			if(it==1) res.pb(i);
			i++;
		}
		VL bit(sz(res)+2,0);
		for(i=1;i<=sz(res);i++) bit[i]=bit[i-1]+res[i-1];
		ll ans=LLINF;
		for(i=k;i<=sz(res);i++)
		{
			int mid=i-k/2;
			ans=min(ans,(res[mid-1]*(k-k/2)-(bit[mid]-bit[i-k]))
                        +(bit[i]-bit[mid]-(k/2)*res[mid-1])
                        -(0+k-k/2-1)*(k-k/2)/2
                        -(1+k/2)*(k/2)/2);
            printf("%d %d %d %d\n",(res[mid-1]*(k-k/2)-(bit[mid]-bit[i-k])),
									(bit[i]-bit[mid]-(k/2)*res[mid-1]),
									(0+k-k/2-1)*(k-k/2)/2,
									(1+k/2)*(k/2)/2);
		}
		return ans;
    }
};
