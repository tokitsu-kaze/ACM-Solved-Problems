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
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
class Allocator {
public:
	int limt;
	vector<pair<PII,int> > res;
    Allocator(int n) {
		limt=n;
		res.clear();
		res.pb(MP(MP(0,0),-1));
		res.pb(MP(MP(n,n),-1));
    }
    
    int allocate(int size, int mID) {
		int i;
		for(i=0;i<sz(res)-1;i++)
		{
			if(res[i].fi.se+size<=res[i+1].fi.fi)
			{
				res.pb(MP(MP(res[i].fi.se,res[i].fi.se+size),mID));
				sort(all(res));
				return res[i].fi.se;
			}
		}
		return -1;
    }
    
    int free(int mID) {
		vector<pair<PII,int> > tmp;
		int cnt=0;
		for(auto it:res)
		{
			if(it.se!=mID) tmp.pb(it);
			else cnt+=it.fi.se-it.fi.fi;
		}
		res=tmp;
		return cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */
