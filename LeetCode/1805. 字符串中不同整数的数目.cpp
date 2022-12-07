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
class Solution {
public:
    int numDifferentIntegers(string word) {
		set<string> s;
		string now;
		string tmp;
		for(auto &it:word)
		{
			if(it>='0'&&it<='9') now+=it;
			else
			{
				tmp="";
				for(auto it2:now)
				{
					if(sz(tmp)==0&&it2=='0') continue;
					tmp+=it2;
				}
				if(sz(now)&&!sz(tmp)) tmp="0";
				if(sz(tmp)) s.insert(tmp);
				now="";
			}
		}
		tmp="";
		for(auto it2:now)
		{
			if(sz(tmp)==0&&it2=='0') continue;
			tmp+=it2;
		}
		if(sz(now)&&!sz(tmp)) tmp="0";
		if(sz(tmp)) s.insert(tmp);
		return sz(s);
    }
};
