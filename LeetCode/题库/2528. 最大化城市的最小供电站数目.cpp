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
int ck(ll x,vector<int>& stations, int r, int k)
{
	int i,n=sz(stations);
	ll res=0;
	VL bit(n+5,0);
	for(i=1;i<=n;i++)
	{
		bit[max(1,i-r)]+=stations[i-1];
		bit[min(n,i+r)+1]-=stations[i-1];
	}
	for(i=1;i<=n;i++)
	{
		bit[i]+=bit[i-1];
		if(bit[i]<x)
		{
			res+=x-bit[i];
			bit[min(n,i+r+r)+1]-=x-bit[i];
			bit[i]=x;
		}
		if(res>k) return 0;
	}
	return res<=k;
}
class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        ll l,rr,mid;
        l=0;
        rr=1e15;
		while(l<rr)
		{
			mid=(l+rr)>>1;
			if(ck(mid+1,stations,r,k)) l=mid+1;
			else rr=mid;
		}
		return l;
    }
};
