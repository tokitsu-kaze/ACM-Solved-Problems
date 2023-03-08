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
int dp[1010][1<<12];
class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {
        VI tmp=VI{2,3,5,7,11,13,17,19,23,29};
        mem(dp,0);
        dp[0][0]=1;
        int i,j,k,now,cnt,cnt1=0;
        for(i=1;i<=sz(nums);i++)
        {
        	if(nums[i-1]==1) cnt1++;
        	now=0;
        	for(j=0;j<sz(tmp);j++)
        	{
        		cnt=0;
        		while(nums[i-1]%tmp[j]==0)
        		{
        			cnt++;
        			nums[i-1]/=tmp[j];
				}
				if(cnt>1)
				{
					now=-1;
					break;
				}
				else if(cnt) now|=(1<<j);
			}
        	for(j=0;j<(1<<sz(tmp));j++)
        	{
        		(dp[i][j]+=dp[i-1][j])%=mod;
        		if(now<=0) continue;
        		if(j&now) continue;
        		(dp[i][j|now]+=dp[i-1][j])%=mod;
			}
		}
		ll ans=0;
		for(i=0;i<(1<<sz(tmp));i++) (ans+=dp[sz(nums)][i])%=mod;
		while(cnt1>0)
		{
			cnt1--;
			ans=ans*2%mod;
		}
		ans--;
		if(ans<0) ans+=mod;
		return ans;
    }
};
