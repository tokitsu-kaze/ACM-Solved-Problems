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
typedef vector<string> VS;
/************* define end  *************/
void println(VI x){for(int i=0;i<sz(x);i++) printf("%d%c",x[i]," \n"[i==sz(x)-1]);}
void println(VL x){for(int i=0;i<sz(x);i++) printf("%lld%c",x[i]," \n"[i==sz(x)-1]);}
void println(int *x,int l,int r){for(int i=l;i<=r;i++) printf("%d%c",x[i]," \n"[i==r]);}
void println(ll *x,int l,int r){for(int i=l;i<=r;i++) printf("%lld%c",x[i]," \n"[i==r]);}
/*************** IO end  ***************/
void assert_lr(ll x,ll l,ll r) {assert(x>=l&&x<=r);};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=998244353;
/*********************************  head  *********************************/
ll bit[MAX];
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        bit[0]=0;
        int i;
        map<int,int> mp;
        for(i=1;i<=sz(nums);i++)
        {
        	bit[i]=bit[i-1]+nums[i-1];
		}
		ll ans=0;
		set<int> s;
		for(i=0;i<k-1;i++)
		{
			mp[nums[i]]++;
			if(mp[nums[i]]>1) s.insert(nums[i]);
		}
		for(i=k;i<=sz(nums);i++)
		{
			mp[nums[i-1]]++;
			if(mp[nums[i-1]]>1) s.insert(nums[i-1]);
			if(sz(s)==0) ans=max(ans,bit[i]-bit[i-k]);
			mp[nums[i-1-k+1]]--;
			if(mp[nums[i-1-k+1]]==1) s.erase(nums[i-1-k+1]);
			
		}
		return ans;
    }
};
