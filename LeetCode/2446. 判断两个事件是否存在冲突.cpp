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
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int l1,r1,l2,r2;
        int h,m;
        sscanf(event1[0].c_str(),"%d:%d",&h,&m);
        l1=h*60+m;
        sscanf(event1[1].c_str(),"%d:%d",&h,&m);
        r1=h*60+m;
        
        sscanf(event2[0].c_str(),"%d:%d",&h,&m);
        l2=h*60+m;
        sscanf(event2[1].c_str(),"%d:%d",&h,&m);
        r2=h*60+m;
        
        if(l1>=l2&&l1<=r2) return true;
        if(r1>=l2&&r1<=r2) return true;
        if(l2>=l1&&l2<=r1) return true;
        if(r2>=l1&&r2<=r1) return true;
        return false;
    }
};
