#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII > VPII;
typedef vector<PLL > VPLL;
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

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int i,r;
        int ans=0;
        r=-1;
		for(i=0;i<sz(garbage);i++)
		{
			for(auto it:garbage[i])
			{
				if(it=='G') r=i;
			}
		}
		for(auto it:garbage[0]) ans+=it=='G';
		for(i=0;i<r;i++)
		{
			ans+=travel[i];
			for(auto it:garbage[i+1]) ans+=it=='G';
		}
		
		r=-1;
		for(i=0;i<sz(garbage);i++)
		{
			for(auto it:garbage[i])
			{
				if(it=='P') r=i;
			}
		}
		for(auto it:garbage[0]) ans+=it=='P';
		for(i=0;i<r;i++)
		{
			ans+=travel[i];
			for(auto it:garbage[i+1]) ans+=it=='P';
		}
		r=-1;
		for(i=0;i<sz(garbage);i++)
		{
			for(auto it:garbage[i])
			{
				if(it=='M') r=i;
			}
		}
		for(auto it:garbage[0]) ans+=it=='M';
		for(i=0;i<r;i++)
		{
			ans+=travel[i];
			for(auto it:garbage[i+1]) ans+=it=='M';
		}
		return ans;
    }
};
