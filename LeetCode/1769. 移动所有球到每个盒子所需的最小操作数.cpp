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
    vector<int> minOperations(string boxes) {
		VI bit(sz(boxes),0),bit2(sz(boxes),0);
		int i;
		bit[0]=0;
		bit2[0]=(boxes[0]=='1');
		for(i=1;i<sz(boxes);i++)
		{
			if(boxes[i]=='1')
			{
				bit[i]=i;
				bit2[i]=1;
			}
			bit[i]+=bit[i-1];
			bit2[i]+=bit2[i-1];
		}
		VI ans(sz(boxes),0);
		for(i=0;i<sz(boxes);i++)
		{
			if(i-1>=0) ans[i]+=i*bit2[i-1]-bit[i-1];
			if(i+1<sz(boxes)) ans[i]+=(bit[sz(boxes)-1]-bit[i])-i*(bit2[sz(boxes)-1]-bit2[i]);
		}
		return ans;
    }
};
