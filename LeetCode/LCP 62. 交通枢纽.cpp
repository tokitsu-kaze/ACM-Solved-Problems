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
const int MAX=3e5+10;
const ll mod=998244353;
/*********************************  head  *********************************/
class Solution {
public:
    int transportationHub(vector<vector<int>>& path) {
		int d[1010],flag[1010];
		int i;
		VI mp[1010];
		for(i=0;i<=1000;i++) mp[i].clear();
		set<int> s;
		mem(d,0);
		for(auto it:path)
		{
			s.insert(it[0]);
			s.insert(it[1]);
			mp[it[1]].pb(it[0]);
			d[it[0]]++;
		}
		int ok;
		for(auto it:s)
		{
			if(d[it]) continue;
			mem(flag,0);
			for(auto to:mp[it]) flag[to]=1;
			ok=1;
			for(auto it2:s)
			{
				if(it2==it) continue;
				ok&=flag[it2];
			}
			if(ok) return it;
		}
		return -1;
    }
};
