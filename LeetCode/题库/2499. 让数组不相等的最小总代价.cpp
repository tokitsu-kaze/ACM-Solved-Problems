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
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        for(auto it:nums1) mp[it]++;
        for(auto it:nums2) mp[it]++;
        for(auto it:mp)
        {
        	if(it.se>sz(nums1)) return -1ll;
		}
		ll ans=0;
		int i,cnt;
		mp.clear();
		cnt=0;
		for(i=0;i<sz(nums1);i++)
		{
			if(nums1[i]==nums2[i])
			{
				ans+=i;
				cnt++;
				mp[nums1[i]]++;
			}
		}
		int need=0;
		int tmp;
		for(auto it:mp)
		{
			if(it.se*2>cnt)
			{
				need=it.se*2-cnt;
				tmp=it.fi;
				break;
			}
		}
		if(need==0) return ans;
		VI res;
		for(i=0;i<sz(nums1);i++)
		{
			if(need==0) break;
			if(nums1[i]==nums2[i]) continue;
			if(nums1[i]!=tmp && nums2[i]!=tmp)
			{
				need--;
				ans+=i;
			}
		}
		if(need>0) return -1ll;
		return ans;
    }
};
