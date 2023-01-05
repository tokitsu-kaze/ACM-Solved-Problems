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
int d[MAX];
class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        mem(d,0);
        map<PII,int> mp;
        for(auto &it:edges)
        {
        	d[it[0]]++;
        	d[it[1]]++;
        	if(it[0]>it[1]) swap(it[0],it[1]);
        	mp[MP(it[0],it[1])]++;
		}
		int i;
		VI res;
		for(i=1;i<=n;i++)
		{
			if(d[i]%2) res.pb(i);
		}
		if(sz(res)==0) return true;
		if(sz(res)&1) return false;
		if(sz(res)>4) return false;
		if(sz(res)==2)
		{
			if(!mp.count(MP(res[0],res[1]))) return true;
			for(i=1;i<=n;i++)
			{
				if(i==res[0]||i==res[1]) continue;
				PII a,b;
				a=MP(res[0],i);
				if(a.fi>a.se) swap(a.fi,a.se);
				b=MP(res[1],i);
				if(b.fi>b.se) swap(b.fi,b.se);
				if(!mp.count(a)&&!mp.count(b)) return true;
			}
			return false;
		}
		do
		{
			PII a,b;
			a=MP(res[0],res[1]);
			if(res[0]>res[1]) swap(a.fi,a.se);
			b=MP(res[2],res[3]);
			if(res[2]>res[3]) swap(b.fi,b.se);
			if(!mp.count(a)&&!mp.count(b)) return true;
			
		}while(next_permutation(all(res)));
		return false;
    }
};
