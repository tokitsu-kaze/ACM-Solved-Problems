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
int bit[1010];
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
		int i,now,ans;
		bit[0]=0;
		now=0;
		for(i=1;i<firstLen;i++)
		{
			now+=nums[i-1];
			bit[i]=0;
		}
		for(i=firstLen;i<=sz(nums);i++)
		{
			now+=nums[i-1];
			bit[i]=max(bit[i-1],now);
			now-=nums[i-firstLen];
		}
		ans=0;
		now=0;
		for(i=sz(nums);i>sz(nums)-secondLen+1;i--) now+=nums[i-1];
		for(i=sz(nums)-secondLen+1;i>=firstLen;i--)
		{
			now+=nums[i-1];
			ans=max(ans,bit[i-1]+now);
			now-=nums[i+secondLen-2];
		}
		swap(firstLen,secondLen);
		bit[0]=0;
		now=0;
		for(i=1;i<firstLen;i++)
		{
			now+=nums[i-1];
			bit[i]=0;
		}
		for(i=firstLen;i<=sz(nums);i++)
		{
			now+=nums[i-1];
			bit[i]=max(bit[i-1],now);
			now-=nums[i-firstLen];
		}
		now=0;
		for(i=sz(nums);i>sz(nums)-secondLen+1;i--) now+=nums[i-1];
		for(i=sz(nums)-secondLen+1;i>=firstLen;i--)
		{
			now+=nums[i-1];
			ans=max(ans,bit[i-1]+now);
			now-=nums[i+secondLen-2];
		}
		return ans;
    }
};
