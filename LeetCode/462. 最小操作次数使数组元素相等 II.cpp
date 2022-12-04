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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int i;
        int n=sz(nums);
        ll bit,suf,ans;
        bit=suf=0;
        sort(all(nums));
        for(i=0;i<n;i++) suf+=nums[i];
        ans=LLINF;
        for(i=0;i<n;i++)
        {
            suf-=nums[i];
            ans=min(ans,1ll*i*nums[i]-bit+suf-1ll*(n-i-1)*nums[i]);
            bit+=nums[i];
        }
        return ans;
    }
};
