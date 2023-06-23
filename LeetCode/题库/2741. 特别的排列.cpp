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
const int MAX=(1<<14)+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int dp[MAX][16];
class Solution {
public:
    int specialPerm(vector<int>& nums) {
        mem(dp,0);
        int i,j,k;
        for(i=0;i<sz(nums);i++) dp[1<<i][i]=1;
        for(i=1;i<(1<<sz(nums));i++)
        {
        	for(j=0;j<sz(nums);j++)
        	{
        		if(!((i>>j)&1)) continue;
        		for(k=0;k<sz(nums);k++)
        		{
        			if(!((i>>k))&1) continue;
        			if(k==j) continue;
        			if(nums[j]%nums[k]&&nums[k]%nums[j]) continue;
        			dp[i][j]=(dp[i][j]+dp[i^(1<<j)][k])%mod;
				}
			}
		}
		ll ans=0;
		for(i=0;i<sz(nums);i++) ans=(ans+dp[(1<<sz(nums))-1][i])%mod;
		return ans;
    }
};
