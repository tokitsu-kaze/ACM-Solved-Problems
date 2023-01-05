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
int ck(int v,int p,int s,int n)
{
	ll mn,mx,l,r;
	mx=v+(1ll*(v+1+v+p)*p/2)+(1ll*(v+1+v+(n-p-1))*(n-p-1)/2);
	mn=v+(1ll*(v-min(p,v-1)+v-1)*min(p,v-1)/2+p-min(p,v-1))+(1ll*(v-min((n-p-1),v-1)+v-1)*min((n-p-1),v-1)/2+(n-p-1)-min((n-p-1),v-1));
	printf("%d %lld %lld\n",v,mn,mx);
	return s>=mn;
}
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
		int l,r,mid;
		l=0;
		r=maxSum;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid+1,index,maxSum,n)) l=mid+1;
			else r=mid;
		}
		return l;
    }
};

