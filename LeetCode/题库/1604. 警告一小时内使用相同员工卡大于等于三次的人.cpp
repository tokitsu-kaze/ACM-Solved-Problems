#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
		int i,j,t,h,m;
		VS res[1444];
		for(i=0;i<=1440;i++) res[i].clear();
		for(i=0;i<sz(keyName);i++)
		{
			sscanf(keyTime[i].c_str(),"%d:%d",&h,&m);
			t=h*60+m;
			res[t].pb(keyName[i]);
		}
		set<string> tmp;
		map<string,int> cnt;
		for(i=0;i<=60;i++)
		{
			for(auto &it:res[i])
			{
				cnt[it]++;
				if(cnt[it]==3) tmp.insert(it);
			}
		}
		for(i=61;i<=1440;i++)
		{
			for(auto &it:res[i-61])
			{
				cnt[it]--;
			}
			for(auto &it:res[i])
			{
				cnt[it]++;
				if(cnt[it]==3) tmp.insert(it);
			}
		}
		VS ans;
		for(auto &it:tmp) ans.pb(it);
		return ans;
    }
};
