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
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
    	ll l,r,mid;
    	l=0;
    	r=1e12;
    	while(l<r)
    	{
    		mid=(l+r)>>1;
    		ll cnt1,cnt2,s;
			cnt1=mid/divisor2-mid/(1ll*divisor1*divisor2/__gcd(divisor1,divisor2));
    		cnt2=mid/divisor1-mid/(1ll*divisor1*divisor2/__gcd(divisor1,divisor2));
    		s=mid-(cnt1+cnt2)-mid/(1ll*divisor1*divisor2/__gcd(divisor1,divisor2));
			printf("%lld %lld %lld %lld %lld\n",mid,cnt1,cnt2,s,max(0ll,uniqueCnt1-cnt1)+max(0ll,uniqueCnt2-cnt2));
    		if(s>=max(0ll,uniqueCnt1-cnt1)+max(0ll,uniqueCnt2-cnt2)) r=mid;
    		else l=mid+1;
		}
		return l;
    }
};
