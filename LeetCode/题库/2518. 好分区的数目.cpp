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
ll pow2(ll a,ll b)
{
	ll res=1;
	while(b>0)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll dp[1010][1010];
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        sort(all(nums));
        mem(dp,0);
        int i,j;
        ll s=0;
        for(auto &it:nums) s+=it;
        dp[0][0]=1;
        for(i=1;i<=sz(nums);i++)
        {
        	for(j=0;j<k;j++)
        	{
        		dp[i][j]=dp[i-1][j];
        		if(j-nums[i-1]>=0) dp[i][j]=(dp[i][j]+dp[i-1][j-nums[i-1]])%mod;
			}
		}
		ll ans;
		ans=pow2(2,sz(nums))-2;
		for(i=1;i<k;i++)
		{
			if(s==i) continue;
			if(s-i>=k) ans=(ans-2*dp[sz(nums)][i])%mod;
			else ans=(ans-dp[sz(nums)][i])%mod;
		}
		if(ans<0) ans+=mod;
		return ans;
    }
};
