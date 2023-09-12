#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define sqr(x) ((x)*(x))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VS> VVS;
typedef vector<VPII> VVPII;
/************* define end  *************/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
/********* gp_hash_table end  **********/
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
int cnt[MAX];
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        VPII qst;
        int i=0;
        for(auto &it:queries) qst.pb({it,i++});
        sort(all(qst));
        VPII a;
        for(auto &it:logs) a.pb({it[1],it[0]});
        sort(all(a));
        for(i=1;i<=n;i++) cnt[i]=0;
		VI res(sz(qst),0);
        int ans=0;
        int j;
        i=j=0;
        for(auto &it:qst)
        {
        	while(i<sz(a)&&a[i].fi<=it.fi)
        	{
        		cnt[a[i].se]++;
        		if(cnt[a[i].se]==1) ans++;
        		i++;
			}
			while(j<sz(a)&&a[j].fi+x<it.fi)
        	{
        		cnt[a[j].se]--;
        		if(cnt[a[j].se]==0) ans--;
        		j++;
			}
			res[it.se]=n-ans;
		}
		return res;
    }
};
