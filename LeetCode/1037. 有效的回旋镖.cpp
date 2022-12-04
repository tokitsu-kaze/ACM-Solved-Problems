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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e4+10;
const ll mod=1e9+7;

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
		VPII res;
		for(auto it:points) res.pb(MP(it[0],it[1]));
		sort(all(res));
		if(res[0]==res[1] || res[0]==res[2] || res[1]==res[2]) return false;
		PII a,b;
		a=MP(res[1].fi-res[0].fi,res[1].se-res[0].se);
		b=MP(res[2].fi-res[0].fi,res[2].se-res[0].se);
		int ka,kb;
		ka=__gcd(res[1].fi-res[0].fi,res[1].se-res[0].se);
		kb=__gcd(res[2].fi-res[0].fi,res[2].se-res[0].se);
		a.fi/=ka;
		a.se/=ka;
		b.fi/=kb;
		b.se/=kb;
		if(a==b) return false;
		return true;
    }
};
