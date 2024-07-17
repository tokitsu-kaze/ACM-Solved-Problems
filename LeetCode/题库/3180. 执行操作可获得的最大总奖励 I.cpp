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
const int MAX=4000+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int a[MAX];
bitset<MAX> dp,tmp;
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int i,n,j;
        n=sz(rewardValues);
        for(i=0;i<n;i++) a[i]=rewardValues[i];
        sort(a,a+n);
        n=unique(a,a+n)-a;
        if(n==1) return a[n-1];
        dp.reset();
        tmp.reset();
        dp[0]=1;
        tmp[0]=1;
        j=0;
        for(i=0;i<n;i++)
        {
        	while(j<a[i]) tmp[j++]=1;
        	dp|=((dp&tmp)<<a[i]);
		}
		for(i=2*a[n-1];~i;i--)
		{
			if(dp[i]) return i;
		}
		return 0;
    }
};
